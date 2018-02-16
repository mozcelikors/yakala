/*
 * Copyright (c) 2018 Mustafa Ozcelikors
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU General Public License
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/
 *
 * Description:
 *     YAKALA project
 *
 * Author:
 *    M.Ozcelikors <mozcelikors@gmail.com>
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	void yakalaUiManipulations (void);

	void yakalaUpdateAliasTable (void);
	void yakalaUpdateNetworkTable (void);
	void yakalaUpdateEnvironmentTable (void);
	void yakalaUpdateProcessTable (void);
	void yakalaUpdateSocketsTable (void);

	void loadingAnimStart (void);
	void loadingAnimStop (void);

	void graphCPUUtil (void);
	void graphMEMUtil (void);

	~MainWindow();

protected:
	 bool eventFilter(QObject *obj, QEvent *event);

private:
	Ui::MainWindow *ui;
	int load_ctr;

	// Related to Graphs
	QVector<double> plotTime;
	QVector<double> plotCPU;
	QVector<double> plotMEM;
	void configureGraphs (void);


signals:

private slots:
	void handleProcessTableClicked (int row, int col);
	void handleProcessKillButton();
	void handleSearchButton();
	void tabSelected();
	void timerSystemInfoUpdate(void);
	void timerGraphUpdate (void);
	void handleAliasTableClicked (int row, int col);
	void handleEnvTableClicked (int row, int col);
	void handleAddAliasButtonClicked (void);
	void handleRemoveAliasButtonClicked (void);
	void handleNetworkComboBox (int idx);
	void handleNetworkSearchButton (void);
	void yakalaCloseEvent (void);
	void inputProcessChanged (void);
	void handleSSHButtons (void);
	void handleBrowseFolderButton (void);

};

#endif // MAINWINDOW_H
