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

#ifndef PROCESSES_H
#define PROCESSES_H

#include <QString>
#include <QStringList>

class Processes
{
private:
	QStringList pids;
	QStringList processes;
	QStringList cpus;
	QStringList mems;
	QString kill_pid;
public:
	Processes();

	void readProcessesList (void);
	QStringList getProcesses (void);
	QStringList getPIDs (void);
	QStringList getCPUs (void);
	QStringList getMEMs (void);
	void killProcess (void);
	void searchProcess (QString process_name);
	void setKillPID (QString kpid);
	QString getKillPID (void);

};


#endif // PROCESSES_H

