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

#include <processes.h>

#include <QString>
#include <QStringList>
#include <QProcess>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include <cstdio>
#include <QSettings>
#include <unistd.h>
#include <QFile>

Processes::Processes()
{
	this->kill_pid = QString("0");
}

void Processes::readProcessesList (void)
{
	this->pids.clear();
	this->processes.clear();

	FILE *fp;

	/* Process retrieval */
	fp = popen ("timeout 5 ps -A | awk '{print $1\"=\"$4}' > /tmp/yakala.procs ","w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	QFile MyFile3("/tmp/yakala.procs");
	if (MyFile3.open(QIODevice::ReadWrite))
	{
		QTextStream in3 (&MyFile3);
		QString line3;
		while (!in3.atEnd())
		{
			line3 = in3.readLine();
			QStringList splittext = line3.split("=");
			this->pids.append(splittext.at(0));
			this->processes.append(splittext.at(1));
		}
		MyFile3.close();
	}

	this->pids.removeFirst();
	this->processes.removeFirst();

	//printf ("%d\n", this->pids.count());
}

void Processes::searchProcess (QString process_name)
{
	this->readProcessesList();

	QStringList pids_new;
	QStringList processes_new;

	//printf ("%d\n", this->processes.count());
	for (int i = 0; i< this->processes.count(); i++)
	{
		if (this->processes.at(i).contains(process_name, Qt::CaseInsensitive) == true)
		{

			pids_new.append(this->pids.at(i));
			processes_new.append(this->processes.at(i));

		}
	}

	//this->pids.clear();
	//this->processes.clear();

	this->pids = pids_new;
	this->processes = processes_new;
	//qDebug() << this->pids.count() << "\n";
}

QStringList Processes::getProcesses (void)
{
	return this->processes;
}

QStringList Processes::getPIDs (void)
{
	return this->pids;
}

QString Processes::getKillPID (void)
{
	return this->kill_pid;
}

void Processes::setKillPID (QString kpid)
{
	this->kill_pid = kpid;
}

void Processes::killProcess (void)
{
	FILE *fp;

	/* Process retrieval */
	fp = popen ((QString("sudo kill -9 ")+this->kill_pid+QString(" 1>/dev/null 2>/dev/null")).toLocal8Bit(), "w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	this->kill_pid = QString("0");
}
