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
#include <QFile>

// TODO: Network Searching multiple entries found.

NetworkSearch::NetworkSearch()
{

}

void NetworkSearch::readNetworkAll (QString networkstart)
{
	this->hostnames.clear();
	this->ips.clear();
	this->macs.clear();
	this->companies.clear();

	FILE *fp, *fp2;

	/* Open and filter networks using NMAP tool*/
	fp = popen ((QString("sudo timeout 60 nmap -T5 -sP ")+networkstart+QString("-255 >/tmp/yakala.network.cache && cat /tmp/yakala.network.cache | grep 'Nmap scan report' | sed -e ':1' -e 's/^Nmap scan report for //;t1' | sed 's|[(),]||g' | sed 's/ /=/g'  > /tmp/yakala.network ")+(QString("&& cat /tmp/yakala.network.cache | grep 'MAC Address' | sed -e ':1' -e 's/^MAC Address: //;t1' | sed 's|[(),]||g' | sed 's/ /=/'  > /tmp/yakala.network2 "))).toLocal8Bit(),"r");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	/* Check if file contains '=' ,which is ini format */
	QFile MyFile("/tmp/yakala.network");
	MyFile.open(QIODevice::ReadWrite);
	QString searchString("=");
	bool ini_format = false;

	QTextStream in (&MyFile);
	QString line;
	do {
		line = in.readLine();
		if (line.contains(searchString, Qt::CaseSensitive)) {
			ini_format = true;
			break;
		}
	} while (!line.isNull());
	MyFile.close();

	if (networkstart.contains("192.168.") ||
			networkstart.contains("172.16.") ||
			networkstart.contains("172.17.") ||
			networkstart.contains("172.18.") ||
			networkstart.contains("172.19.") ||
			networkstart.contains("172.20.") ||
			networkstart.contains("172.21.") ||
			networkstart.contains("172.22.") ||
			networkstart.contains("172.23.") ||
			networkstart.contains("172.24.") ||
			networkstart.contains("172.25.") ||
			networkstart.contains("172.26.") ||
			networkstart.contains("172.27.") ||
			networkstart.contains("172.28.") ||
			networkstart.contains("172.29.") ||
			networkstart.contains("172.30.") ||
			networkstart.contains("172.31."))
	{
		if (ini_format) /* Ini format */
		{
			QFile MyFile2("/tmp/yakala.network");
			if (MyFile2.open(QIODevice::ReadWrite))
			{
				QTextStream in2 (&MyFile2);
				QString line2;
				while (!in2.atEnd())
				{
					line2 = in2.readLine();
					QStringList splittext = line2.split("=");
					this->hostnames.append(splittext.at(0));
					this->ips.append(splittext.at(1));
				}
				MyFile2.close();
			}
		}
		else
		{
			QFile MyFile2("/tmp/yakala.network");
			if (MyFile2.open(QIODevice::ReadWrite))
			{
				QTextStream in2 (&MyFile2);
				QString line2;
				while (!in2.atEnd())
				{
					line2 = in2.readLine();

					this->hostnames.append(" ");
					this->ips.append(line2);

				}
				MyFile2.close();
			}
		}

		QFile MyFile3("/tmp/yakala.network2");
		if (MyFile3.open(QIODevice::ReadWrite))
		{
			QTextStream in3 (&MyFile3);
			QString line3;
			while (!in3.atEnd())
			{
				line3 = in3.readLine();
				QStringList splittext = line3.split("=");
				this->macs.append(splittext.at(0));
				this->companies.append(splittext.at(1));
			}
			this->macs.append(" ");
			this->companies.append(" ");
			MyFile3.close();
		}
	}
	else
	{

	}
}


void NetworkSearch::readNetworkFilterHostname (QString networkstart, QString hostname)
{
	this->hostnames.clear();
	this->ips.clear();
	this->macs.clear();
	this->companies.clear();

	FILE *fp;

	/* Open and filter networks using NMAP tool*/
	fp = popen ((QString("sudo timeout 60 nmap -T5 -sP ")+networkstart+QString("/24 | grep 'Nmap scan' | grep '")+hostname+QString("' | sed -e ':1' -e 's/^Nmap scan report for //;t1' | sed 's|[(),]||g' | sed 's/ /=/g'  > /tmp/yakala.network ")).toLocal8Bit(),"r");

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

QStringList NetworkSearch::getCompanies (void)
{
	return this->companies;
}

QStringList NetworkSearch::getMACs (void)
{
	return this->macs;
}
