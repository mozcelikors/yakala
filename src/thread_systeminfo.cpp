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

#include <pthread.h>
#include <unistd.h>
#include <thread_systeminfo.h>

#include <stdio.h>
#include "mainwindow.h"
#include <main.h>
#include <filesearch.h>
#include <sockets.h>
#include <QDebug>
#include <packages.h>

void *Thread_NetworkSearch (void *arg)
{
	switch (myNetworkSearch.filter_type_)
	{
		case FILTERTYPE_ALL_:
			n.readNetworkAll(myNetworkSearch.networkstart_);
			break;
		case FILTERTYPE_HOSTNAME_:
			n.readNetworkFilterHostname(myNetworkSearch.networkstart_, myNetworkSearch.filter_text_);
			break;
		case FILTERTYPE_IP_:
			n.readNetworkFilterIP(myNetworkSearch.networkstart_, myNetworkSearch.filter_text_);
			break;
		case FILTERTYPE_MAC_:
			n.readNetworkFilterMAC(myNetworkSearch.networkstart_, myNetworkSearch.filter_text_);
			break;
		case FILTERTYPE_COMPANY_:
			n.readNetworkFilterCompany(myNetworkSearch.networkstart_, myNetworkSearch.filter_text_);
			break;
		default:
			break;
	}

	myNetworkSearch.finished_ = 1;

	pthread_exit(NULL);
	return NULL;
}

void *Thread_FileSearch (void *arg)
{
	if (myFileSearch.file_or_library_ == 0)
		f.fileSearch(myFileSearch.text_, myFileSearch.folder_);
	myFileSearch.finished_ = 1;
	//qDebug() <<  f.getResult();
	pthread_exit(NULL);
	return NULL;
}

void *Thread_SystemInfo (void *arg)
{
	/* Get Static System Details */
	s.readMemoryTotal();
	s.readCpuModel();
	s.readCpuCount();
	s.readDistro();
	s.readKernelRelease();
	s.readArchitecture();
	s.readHostname();
	a.readAliasesList();
	s.readDiskTotal();
	pa.readPackageList();


	while (1)
	{
		/* Get Periodic System Details*/
		s.readCpuUsage();
		usleep(1* 250000);

		s.readMemoryFree();
		usleep(1* 250000);

		s.readDiskUsed();
		usleep(1* 250000);

		s.readIP();
		usleep(1* 250000);

	}

	return NULL;
}


