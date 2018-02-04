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

#include <pthread.h>
#include <unistd.h>
#include <thread_systeminfo.h>

#include <stdio.h>
#include "mainwindow.h"
#include <main.h>


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


	while (1)
	{
		/* Get Periodic System Details*/
		s.readCpuUsage();
		s.readMemoryFree();
		s.readDiskUsed();
		s.readIP();
		usleep(1* 1000000);

	}

	return NULL;
}


