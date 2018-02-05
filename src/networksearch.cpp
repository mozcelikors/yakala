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

#include "networksearch.h"
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include <cstdio>
#include <QSettings>

NetworkSearch::NetworkSearch()
{

}

void NetworkSearch::readNetworkAll (QString networkstart)
{
	this->hostnames.clear();
	this->ips.clear();

	FILE *fp;

	/* Open and filter networks using NMAP tool*/
	fp = popen ((QString("timeout 60 nmap -sn ")+networkstart+QString("/24 | grep 'Nmap scan' | sed -e ':1' -e 's/^Nmap scan report for //;t1' | sed 's|[(),]||g' | sed 's/ /=/g'  > /tmp/yakala.network ")).toLocal8Bit(),"r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_NETWORKSEARCH_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);

			//Delete last character
			this->buffer[strlen(buffer)-1] = 0;

		}
		//printf ("%s", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		//strncpy (this->aliases, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
	fclose(fp);

	/* Read from filtered temporary document using QSettings ini format */
	QSettings settings("/tmp/yakala.network", QSettings::IniFormat);

	foreach (const QString &key, settings.childKeys())
	{
			//std::cout << key.toStdString() << std::endl;
			//std::cout << settings.value(key).toString().toUtf8().constData() << std::endl;

			// Add to out command and alias list
			this->hostnames.append(key);
			this->ips.append(settings.value(key).toString());
	}
}


void NetworkSearch::readNetworkFilterHostname (QString networkstart, QString hostname)
{
	this->hostnames.clear();
	this->ips.clear();

	FILE *fp;

	/* Open and filter networks using NMAP tool*/
	fp = popen ((QString("timeout 60 nmap -sn ")+networkstart+QString("/24 | grep 'Nmap scan' | grep '")+hostname+QString("' | sed -e ':1' -e 's/^Nmap scan report for //;t1' | sed 's|[(),]||g' | sed 's/ /=/g'  > /tmp/yakala.network ")).toLocal8Bit(),"r");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_NETWORKSEARCH_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);

			//Delete last character
			this->buffer[strlen(buffer)-1] = 0;

		}
		//printf ("%s", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		//strncpy (this->aliases, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
	fclose(fp);

	/* Read from filtered temporary document using QSettings ini format */
	QSettings settings("/tmp/yakala.network", QSettings::IniFormat);

	foreach (const QString &key, settings.childKeys())
	{
			//std::cout << key.toStdString() << std::endl;
			//std::cout << settings.value(key).toString().toUtf8().constData() << std::endl;

			// Add to out command and alias list
			this->hostnames.append(key);
			this->ips.append(settings.value(key).toString());
	}
}

QStringList NetworkSearch::getHostnames (void)
{
	return this->hostnames;
}

QStringList NetworkSearch::getIPs (void)
{
	return this->ips;
}

