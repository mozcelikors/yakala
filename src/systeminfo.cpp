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

#include "systeminfo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

SystemInfo::SystemInfo()
{}

void SystemInfo::readMemoryTotal (void)
{
	FILE *fp;
	int tmp_mem_total;

	fp = popen ("timeout 5 cat /proc/meminfo | grep MemTotal | sed 's/[^0-9]*//g' 2>/dev/null ","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		sscanf(buffer, "%d", &tmp_mem_total);

		this->memory_total = (tmp_mem_total/1024.0)/1024.0;
	}
	else
	{
		this->memory_total = 0;
	}
}

void SystemInfo::readMemoryFree (void)
{
	FILE *fp;
	int tmp_mem_free;

	fp = popen ("timeout 5 cat /proc/meminfo | grep MemFree | sed 's/[^0-9]*//g' 2>/dev/null ","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		sscanf(buffer, "%d", &tmp_mem_free);

		this->memory_free = (tmp_mem_free/1024.0)/1024.0;
	}
	else
	{
		this->memory_free = 0;
	}
}

void SystemInfo::readCpuUsage (void)
{
	FILE *fp;
	int tmp_cpu_usage;

	fp = popen ("timeout 5 awk -v a=\"$(awk '/cpu /{print $2+$4,$2+$4+$5}' /proc/stat; sleep 0.5)\" '/cpu /{split(a,b,\" \"); print 100*($2+$4-b[1])/($2+$4+$5-b[2])}'  /proc/stat 2>/dev/null ","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		sscanf(buffer, "%d", &tmp_cpu_usage);

		this->cpu_usage = (tmp_cpu_usage);
	}
	else
	{
		this->cpu_usage = 0;
	}
}

void SystemInfo::readCpuModel (void)
{
	FILE *fp;

	fp = popen ("timeout 5 cat /proc/cpuinfo | grep -m1 'model name' | sed 's/.*: //' 2>/dev/null","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		strncpy (this->cpu_model, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
}


void SystemInfo::readCpuCount (void)
{
	FILE *fp;
	int tmp_cpu_count;

	fp = popen ("timeout 5 cat /proc/cpuinfo | grep 'processor' | tail -1 | sed 's/[^0-9]*//g'","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		sscanf(buffer, "%d", &tmp_cpu_count);

		buffer[0] = 0; //Clear array

		this->cpu_count = (tmp_cpu_count + 1);
	}
	else
	{
		this->cpu_count = 0;
	}
}

void SystemInfo::readDistro (void)
{
	FILE *fp;

	fp = popen ("timeout 5 cat /etc/os-release | grep PRETTY_NAME | sed -e 's#.*=\\(\\)#\1#' | sed 's/\\\"//g' ","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		strncpy (this->distro, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
}

void SystemInfo::readKernelRelease (void)
{
	FILE *fp;

	fp = popen ("timeout 5 uname -r","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		strncpy (this->kernel_release, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
}

void SystemInfo::readArchitecture (void)
{
	FILE *fp;

	fp = popen ("timeout 5 uname -i","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		strncpy (this->architecture, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
}

void SystemInfo::readHostname (void)
{
	FILE *fp;

	fp = popen ("timeout 5 hostname","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		strncpy (this->hostname, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
}

void SystemInfo::readIP (void)
{
	FILE *fp;

	fp = popen ("timeout 5 ifconfig | grep 'inet addr:' | grep '192.168' | cut -d: -f2 | awk '{ print $1}'","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		strncpy (this->ip, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
}

void SystemInfo::readDiskTotal (void)
{
	FILE *fp;
	int tmp_disk_space_total;

	fp = popen ("timeout 5 df -k / -l --output=size | tail -1","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		sscanf(buffer, "%d", &tmp_disk_space_total);

		buffer[0] = 0; //Clear array

		this->disk_space_total = ((tmp_disk_space_total)/1024.0)/1024.0;
	}
	else
	{
		this->disk_space_total = 0;
	}
}

void SystemInfo::readDiskUsed (void)
{
	FILE *fp;
	int tmp_disk_space_used;

	fp = popen ("timeout 5 df -k / -l --output=used | tail -1","r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);
		}
		//printf ("%s\n", this->buffer);

		sscanf(buffer, "%d", &tmp_disk_space_used);

		buffer[0] = 0; //Clear array

		this->disk_space_used = ((tmp_disk_space_used)/1024.0)/1024.0;
	}
	else
	{
		this->disk_space_used = 0;
	}
}

float SystemInfo::getMemoryTotal (void)
{
	return this->memory_total;
}

float SystemInfo::getMemoryFree (void)
{
	return this->memory_free;
}

float SystemInfo::getMemoryPercentage (void)
{
	this->memory_percentage = ((this->memory_total - this-> memory_free) / this->memory_total) * 100.0;
	return this->memory_percentage;
}

float SystemInfo::getCpuUsage (void)
{
	return this->cpu_usage;
}

char * SystemInfo::getCpuModel (void)
{
	return this->cpu_model;
}

int SystemInfo::getCpuCount (void)
{
	return this->cpu_count;
}

char* SystemInfo::getDistro (void)
{
	return this->distro;
}

char* SystemInfo::getKernelRelease (void)
{
	return this->kernel_release;
}

char* SystemInfo::getArchitecture (void)
{
	return this->architecture;
}

char* SystemInfo::getHostname (void)
{
	return this->hostname;
}

char* SystemInfo::getIP (void)
{
	return this->ip;
}

float SystemInfo::getDiskSpaceTotal (void)
{
	return this->disk_space_total;
}

float SystemInfo::getDiskSpaceUsed (void)
{
	return this->disk_space_used;
}

int SystemInfo::getDiskPercentage (void)
{
	this->disk_percentage = (this->disk_space_used / this->disk_space_total) * 100.0;
	return this->disk_percentage;
}


