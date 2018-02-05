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

#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QString>

#define MAX_BUFSIZE 1024

class SystemInfo
{
private:
	char buffer[MAX_BUFSIZE];

	float memory_free;
	float memory_total;
	float memory_percentage;

	float disk_space_used;
	float disk_space_total;
	float disk_percentage;

	float cpu_usage;
	char cpu_model[MAX_BUFSIZE];

	int cpu_count;
	char distro[MAX_BUFSIZE];

	char kernel_release[MAX_BUFSIZE];
	char architecture[MAX_BUFSIZE];

	char hostname[MAX_BUFSIZE];

	char ip[MAX_BUFSIZE];

	char mac_addr[MAX_BUFSIZE];

public:
	SystemInfo();
	void readMemoryTotal();
	float getMemoryTotal (void);

	void readMemoryFree();
	float getMemoryFree (void);

	float getMemoryPercentage (void);

	void readCpuUsage(void);
	float getCpuUsage(void);

	void readCpuModel (void);
	char * getCpuModel (void);

	void readCpuCount (void);
	int getCpuCount (void);

	void readDistro (void);
	char* getDistro(void);

	void readKernelRelease (void);
	char* getKernelRelease (void);

	void readArchitecture (void);
	char * getArchitecture (void);

	void readHostname (void);
	char * getHostname (void);

	void readIP (void);
	char * getIP (void);

	void readDiskTotal (void);
	void readDiskUsed (void);

	float getDiskSpaceUsed(void);
	float getDiskSpaceTotal(void);
	int getDiskPercentage (void);

	void readMACAddress(QString ip_addr);
	QString getMACAddress (void);
};

#endif // SYSTEMINFO_H
