/*
 * Copyright (c) 2018 Mustafa Ozcelikors
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v2.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v20.html
 *
 * Description:
 *     YAKALA project
 *
 * Author:
 *    M.Ozcelikors <mozcelikors@gmail.com>
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.h"

#include <stdio.h>
#include <unistd.h>

#include <pthread.h>
#include <thread_systeminfo.h>

#include <QTimer>
#include <QShortcut>
#include <QTableWidget>
#include <QHeaderView>

#include <filesearch.h>


void MainWindow::yakalaUpdateNetworkTable (void)
{
	/* Load table widget for Network section */
	ui->tableWidget_network->setColumnCount(2);
	ui->tableWidget_network->setRowCount(n.getHostnames().size());
	QStringList  TableHeader;
	TableHeader<<"Hostname"<<"IP Address";
	ui->tableWidget_network->setHorizontalHeaderLabels(TableHeader);

	ui->tableWidget_network->setColumnWidth(0, 200);

	ui->tableWidget_network->horizontalHeader()->setStretchLastSection(true);

	for (int i = 0; i < n.getHostnames().size(); i++)
	{
		QTableWidgetItem *item = new QTableWidgetItem(n.getHostnames().at(i));
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui->tableWidget_network->setItem(i, 0, item);

		QTableWidgetItem *item2 = new QTableWidgetItem(n.getIPs().at(i));
		item2->setFlags(item2->flags() ^ Qt::ItemIsEditable);
		ui->tableWidget_network->setItem(i, 1, item2);
	}
}



void MainWindow::yakalaUpdateAliasTable (void)
{
	/* Load table widget for Aliases section */
	ui->tableWidget_alias->setColumnCount(2);
	ui->tableWidget_alias->setRowCount(a.getAliases().size());
	QStringList  TableHeader;
	TableHeader<<"Alias"<<"Command";
	ui->tableWidget_alias->setHorizontalHeaderLabels(TableHeader);
	ui->tableWidget_alias->horizontalHeader()->setStretchLastSection(true);

	for (int i = 0; i < a.getAliases().size(); i++)
	{
		QTableWidgetItem *item = new QTableWidgetItem(a.getAliases().at(i));
		item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		ui->tableWidget_alias->setItem(i, 0, item);

		QTableWidgetItem *item2 = new QTableWidgetItem(a.getCommands().at(i));
		item2->setFlags(item2->flags() ^ Qt::ItemIsEditable);
		ui->tableWidget_alias->setItem(i, 1, item2);
	}

}

void MainWindow::yakalaUiManipulations(void)
{
	/* Set cursor at the tab bar */
	ui->tabWidget->tabBar()->setCursor(Qt::PointingHandCursor);

	/* Set fixed size for main window - make it unresizable */
	ui->statusBar->setSizeGripEnabled(false);
	this->setFixedSize(QSize(850, 610));

	/* Add the logo*/
	ui->graphicsView->setGeometry(35, 15, 217, 55);
	ui->graphicsView->setStyleSheet("background-image: url(:/gui/logo3.png)");

	/* Slogan color edit */
	ui->label->setStyleSheet("color:#333;");

	/* Menu bar graphics */
	ui->graphicsView_2->setGeometry(47, 110, 34,34);
	ui->graphicsView_2->setStyleSheet("background-image: url(:/gui/menu1.png)");
	ui->graphicsView_2->setVisible(true);

	ui->graphicsView_4->setGeometry(47, 210, 34,34);
	ui->graphicsView_4->setStyleSheet("background-image: url(:/gui/menu3.png)");
	ui->graphicsView_4->setVisible(false);

	ui->graphicsView_5->setGeometry(47, 300, 34,34);
	ui->graphicsView_5->setStyleSheet("background-image: url(:/gui/menu4.png)");
	ui->graphicsView_5->setVisible(false);

	ui->graphicsView_6->setGeometry(47, 385, 34,34);
	ui->graphicsView_6->setStyleSheet("background-image: url(:/gui/menu5.png)");
	ui->graphicsView_6->setVisible(false);

	/* Made with love icon */
	ui->graphicsView_madewithlove->setGeometry(670, 55, 125,13);
	ui->graphicsView_madewithlove->setStyleSheet("background-image: url(:/gui/madewithlove.png)");

	/* Style adjustment to labels */
	this->ui->label_cpuModel->setStyleSheet("color: gray;");
	this->ui->label_cpuCount->setStyleSheet("color: gray;");
	this->ui->label_Distro->setStyleSheet("color: gray;");
	this->ui->label_kernelRelease->setStyleSheet("color: gray;");
	this->ui->label_architecture->setStyleSheet("color: gray;");
	this->ui->label_hostname->setStyleSheet("color: gray;");
	this->ui->label_ip->setStyleSheet("color: gray;");

	/* Alias part UI manipulations */
	this->ui->pushButton_removealias->setStyleSheet("QPushButton::hover, QPushButton::focus{color:white; background-color:red;}");

	/* FileSearch part UI manipulations */
	this->ui->textEdit_filesearch->setText("Please enter file or library name to search..");
	this->ui->textEdit_filesearch->setStyleSheet("font-family:'Courier New'; font-size:14px;");

	/* Network part UI manipulations */
	this->ui->comboBox_searchnetwork->addItem("Show All");
	this->ui->comboBox_searchnetwork->addItem("Search Hostname");
	this->ui->lineEdit_networksearch->setEnabled(false);

	/*********** CONNECT and TIMERs ***************/

	/* Tab bar signal-slot */
	connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabSelected()));

	/* Timer event for system information update */
	QTimer *timer_systeminfoupdate = new QTimer(this);
	connect(timer_systeminfoupdate, SIGNAL(timeout()), this, SLOT(timerSystemInfoUpdate()));
	timer_systeminfoupdate->start(500); // 2 second timer

	/* Signal-slot for searchButton in File Search*/
	connect(ui->searchButton, SIGNAL(released()), this, SLOT (handleSearchButton()));

	/* Aliases tableWidget cell clicked signal-slot */
	connect(ui->tableWidget_alias, SIGNAL(cellClicked(int,int)), this, SLOT(handleAliasTableClicked(int,int)));

	/* Aliases addAlias button signal-slot */
	connect(ui->pushButton_addalias, SIGNAL(released()), this, SLOT (handleAddAliasButtonClicked()));

	/* Aliases removeAlias button signal-slot */
	connect(ui->pushButton_removealias, SIGNAL(released()), this, SLOT (handleRemoveAliasButtonClicked()));

	/* Network comboBox signal-slot */
	connect(ui->comboBox_searchnetwork, SIGNAL(currentIndexChanged(int)), this, SLOT(handleNetworkComboBox(int)));

	/* Network search button signal-slot */
	connect(ui->pushButton_networksearch, SIGNAL(released()), this, SLOT (handleNetworkSearchButton()));

	/* On MainWindow close */
	connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(yakalaCloseEvent()));

}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	/* UI */
	ui->setupUi(this);
	this->yakalaUiManipulations();

	/* Threads */
	pthread_t systeminfo_thread;
	pthread_attr_t attrs;
	pthread_attr_init(&attrs);
	pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_JOINABLE);

	if(pthread_create(&systeminfo_thread, &attrs, Thread_SystemInfo, NULL))
	{
		fprintf(stderr, "Error creating thread\n");
	}

}

MainWindow::~MainWindow()
{
	delete ui;
}

/**************** SLOTS *******************/

void MainWindow::handleAddAliasButtonClicked (void)
{
	/* Add alias and update alias table */
	a.addAlias(ui->lineEdit_alias->text(), ui->lineEdit_command->text());
	a.readAliasesList();
	this->yakalaUpdateAliasTable();
}

void MainWindow::handleRemoveAliasButtonClicked (void)
{
	/* Remove alias and update alias table */
	a.removeAlias(ui->lineEdit_alias->text());
	a.readAliasesList();
	this->yakalaUpdateAliasTable();
}

void MainWindow::handleAliasTableClicked (int row, int col)
{
	this->ui->lineEdit_alias->setText(a.getAliases().at(row));
	this->ui->lineEdit_command->setText(a.getCommands().at(row));


}

void MainWindow::handleSearchButton()
{
	FileSearch f = FileSearch();

	/* Adjustments to loadingText */
	this->ui->label_loadingText->move(280,20);
	this->ui->label_loadingText->show();

	/* Update GUI element loadingText*/
	this->ui->label_loadingText->repaint();

	if (this->ui->label_loadingText->isHidden() == false)
	{
		if (this->ui->lineEdit_filesearch->text().length() > 0)
		{
			f.fileSearch(this->ui->lineEdit_filesearch->text());
		}
		else
		{
			f.librarySearch(this->ui->lineEdit_librarysearch->text());
		}
		this->ui->label_loadingText->hide();
	}

	ui->textEdit_filesearch->setText(f.getResult().toUtf8().constData());
}

void MainWindow::tabSelected()
{
	/* Describes how icons behave when the tabs are selected*/
	if(ui->tabWidget->currentIndex()==0)
	{

		ui->graphicsView_2->setVisible(true);
	}
	else
	{
		ui->graphicsView_2->setVisible(false);
	}

	if(ui->tabWidget->currentIndex()==1)
	{
		ui->graphicsView_4->setVisible(true);

		this->yakalaUpdateNetworkTable ();
	}
	else
	{
		ui->graphicsView_4->setVisible(false);
	}

	if(ui->tabWidget->currentIndex()==2)
	{
		ui->graphicsView_5->setVisible(true);

		/* Set focus */
		this->ui->lineEdit_filesearch->setFocus();

		/* Set ENTER key binding to Search button */
		QShortcut *returnShortcut = new QShortcut(QKeySequence("Return"), ui->searchButton);
		QObject::connect(returnShortcut, SIGNAL(activated()), this, SLOT(handleSearchButton()));


	}
	else
	{
		/* Cancel this signal-slot */
		QShortcut *returnShortcut = new QShortcut(QKeySequence("Return"), ui->searchButton);
		QObject::disconnect(returnShortcut, SIGNAL(activated()), this, SLOT(handleSearchButton()));
		ui->graphicsView_5->setVisible(false);
	}

	if(ui->tabWidget->currentIndex()==3)
	{
		ui->graphicsView_6->setVisible(true);

		/* Update AliasTable */
		this->yakalaUpdateAliasTable();

	}
	else
	{
		ui->graphicsView_6->setVisible(false);

	}


	/* Describes additional actions when tabs are selected */
	if(ui->tabWidget->currentIndex()==0)
	{

	}
}

void MainWindow::timerSystemInfoUpdate(void)
{
	this->load_ctr = this->load_ctr + 1;

	this->ui->label_memoryTotal->setText(QString::number(s.getMemoryTotal())+"  GB");
	this->ui->label_memoryFree->setText(QString::number(s.getMemoryFree())+"  GB");
	this->ui->memoryusage_progressBar->setValue((int) s.getMemoryPercentage());
	this->ui->cpuusage_progressBar->setValue((int) s.getCpuUsage());
	this->ui->label_cpuModel->setText(s.getCpuModel());
	this->ui->label_cpuCount->setText(QString::number(s.getCpuCount()));
	this->ui->label_Distro->setText(s.getDistro());
	this->ui->label_kernelRelease->setText(s.getKernelRelease());
	this->ui->label_architecture->setText(s.getArchitecture());
	this->ui->label_hostname->setText(s.getHostname());
	this->ui->label_ip->setText(s.getIP());
	this->ui->label_totaldisk->setText(QString::number(s.getDiskSpaceTotal())+" GB");
	this->ui->label_useddisk->setText(QString::number(s.getDiskSpaceUsed())+" GB");
	this->ui->progressBar_diskUsage->setValue((int) s.getDiskPercentage());

	if (this->ui->loading_progressBar->isHidden() == false && this->load_ctr >2)
	{
		this->ui->loading_progressBar->hide();
		this->ui->label_loadingText->hide();
		this->load_ctr = 0;
	}
	else
	{
		this->ui->loading_progressBar->setValue(this->load_ctr*50);
	}

}

void MainWindow::handleNetworkComboBox (int idx)
{
	if (idx == 0)
	{
		this->ui->lineEdit_networksearch->setEnabled(false);
	}
	else
	{
		this->ui->lineEdit_networksearch->setEnabled(true);
	}
}

void MainWindow::handleNetworkSearchButton (void)
{
	switch (ui->comboBox_searchnetwork->currentIndex())
	{
		case 0: /* Search Everything */
			/* Loading */
			this->ui->label_loadingText->move(280,20);
			this->ui->label_loadingText->show();
			this->ui->label_loadingText->repaint();

			/* Do the search-update */
			n.readNetworkAll(ui->lineEdit_networkstart->text());
			this->yakalaUpdateNetworkTable();

			/* Loading finished */
			this->ui->label_loadingText->hide();
			this->ui->label_loadingText->repaint();
			break;

		case 1: /* Filter Hostname */
			/* Loading */
			this->ui->label_loadingText->move(280,20);
			this->ui->label_loadingText->show();
			this->ui->label_loadingText->repaint();

			/* Do the search-update */
			n.readNetworkFilterHostname(ui->lineEdit_networkstart->text(), ui->lineEdit_networksearch->text());
			this->yakalaUpdateNetworkTable();

			/* Loading finished */
			this->ui->label_loadingText->hide();
			this->ui->label_loadingText->repaint();
			break;
		default:
			break;
	}

}


void MainWindow::yakalaCloseEvent (void)
{
	printf ("yakala is closing...\n");
}
