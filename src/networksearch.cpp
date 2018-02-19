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
	fp = popen ((QString("sudo timeout 60 nmap -T5 -sP ")+networkstart+QString("-255 >/tmp/yakala.network.cache && cat /tmp/yakala.network.cache | grep 'Nmap scan report' | sed -e ':1' -e 's/^Nmap scan report for //;t1' | sed 's|[(),]||g' | sed 's/ /=/g'  > /tmp/yakala.network.1 ")+(QString("&& cat /tmp/yakala.network.cache | grep 'MAC Address' | sed -e ':1' -e 's/^MAC Address: //;t1' | sed 's|[(),]||g' | sed 's/ /=/'  > /tmp/yakala.network.2 "))).toLocal8Bit(),"r");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	/* Check if file contains '=' ,which is ini format */
	QFile MyFile("/tmp/yakala.network.1");
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
			QFile MyFile2("/tmp/yakala.network.1");
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
			QFile MyFile2("/tmp/yakala.network.1");
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

		QFile MyFile3("/tmp/yakala.network.2");
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
			this->macs.append("YOUR NETWORK");
			this->companies.append("YOUR NETWORK");
			MyFile3.close();
		}
	}
	else
	{

	}
}


void NetworkSearch::readNetworkFilterHostname (QString networkstart, QString hostname)
{
	this->readNetworkAll(networkstart);

	for (int i = 0; i< this->hostnames.size(); i++)
	{
		if (this->hostnames.at(i).contains(hostname, Qt::CaseInsensitive) == false)
		{
			this->hostnames.removeAt(i);
			this->ips.removeAt(i);
			this->macs.removeAt(i);
			this->companies.removeAt(i);
		}
	}
}

void NetworkSearch::readNetworkFilterIP (QString networkstart, QString ip)
{
	this->readNetworkAll(networkstart);

	for (int i = 0; i< this->ips.size(); i++)
	{
		if (this->ips.at(i).contains(ip, Qt::CaseInsensitive) == false)
		{
			this->hostnames.removeAt(i);
			this->ips.removeAt(i);
			this->macs.removeAt(i);
			this->companies.removeAt(i);
		}
	}
}

void NetworkSearch::readNetworkFilterMAC (QString networkstart, QString mac)
{
	this->readNetworkAll(networkstart);

	for (int i = 0; i< this->macs.size(); i++)
	{
		if (this->macs.at(i).contains(mac, Qt::CaseInsensitive) == false)
		{
			this->hostnames.removeAt(i);
			this->ips.removeAt(i);
			this->macs.removeAt(i);
			this->companies.removeAt(i);
		}
	}
}

void NetworkSearch::readNetworkFilterCompany (QString networkstart, QString company)
{
	this->readNetworkAll(networkstart);

	for (int i = 0; i< this->companies.size(); i++)
	{
		if (this->companies.at(i).contains(company, Qt::CaseInsensitive) == false)
		{
			this->hostnames.removeAt(i);
			this->ips.removeAt(i);
			this->macs.removeAt(i);
			this->companies.removeAt(i);
		}
	}
}

void NetworkSearch::sshInto (int list_index, QString user_override)
{
	FILE *fp;
	if (user_override.length() > 1)
		system ("xterm -fa 'Monospace' -fs 12 -e \"ssh -o StrictHostKeyChecking=no "+user_override.toLocal8Bit()+"@"+QString(this->getIPs().at(list_index)).toLocal8Bit()+"\" &");
	else
		system (QString("xterm -fa 'Monospace' -fs 12 -e \"ssh -o StrictHostKeyChecking=no ").toLocal8Bit()+QString("root@").toLocal8Bit()+QString(this->getIPs().at(list_index)).toLocal8Bit()+"\" &");
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
