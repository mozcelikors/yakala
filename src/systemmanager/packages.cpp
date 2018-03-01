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

#include <packages.h>

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

Packages::Packages ()
{
	this->uninstallpackage = QString("0");
}

void Packages::searchAptcache (QString needle)
{
	this->aptcachename.clear();
	this->aptcachedescription.clear();

	FILE *fp;

	/* Process retrieval */
	fp = popen ((QString("timeout 30 apt-cache search ") +needle+ QString(" 2>/dev/null | sed 's/\ -.*//' > /tmp/yakala.aptcache && apt-cache search ")+needle+QString(" 2>/dev/null | sed 's/.*- //' > /tmp/yakala.aptcache2")).toLocal8Bit(),"w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	QFile MyFile3("/tmp/yakala.aptcache");
	if (MyFile3.open(QIODevice::ReadWrite))
	{
		QTextStream in3 (&MyFile3);
		QString line3;
		while (!in3.atEnd())
		{
			line3 = in3.readLine();
			this->aptcachename.append(line3);
		}
		MyFile3.close();
	}

	QFile MyFile4("/tmp/yakala.aptcache2");
	if (MyFile4.open(QIODevice::ReadWrite))
	{
		QTextStream in4 (&MyFile4);
		QString line4;
		while (!in4.atEnd())
		{
			line4 = in4.readLine();
			this->aptcachedescription.append(line4);
		}
		MyFile4.close();
	}
}

void Packages::readPackageList (void)
{
	this->names.clear();

	FILE *fp;

	/* Process retrieval */
	fp = popen ("timeout 5 apt list --installed 2>/dev/null | sed 's\/\\\/.*\/\/' > /tmp/yakala.packages ","w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	QFile MyFile3("/tmp/yakala.packages");
	if (MyFile3.open(QIODevice::ReadWrite))
	{
		QTextStream in3 (&MyFile3);
		QString line3;
		while (!in3.atEnd())
		{
			line3 = in3.readLine();
			this->names.append(line3);
		}
		MyFile3.close();
	}

	this->names.removeFirst();

}

void Packages::searchPackages (QString needle)
{
	this->readPackageList();

	QStringList names_new;

	for (int i = 0; i< this->names.count(); i++)
	{
		if (this->names.at(i).contains(needle, Qt::CaseInsensitive) == true)
		{
			names_new.append(this->names.at(i));
		}
	}

	this->names = names_new;
}

QStringList Packages::getNames (void)
{
	return this->names;
}

QStringList Packages::getAptcachenames (void)
{
	return this->aptcachename;
}

QStringList Packages::getAptcachedescription (void)
{
	return this->aptcachedescription;
}

void Packages::uninstallPackage (void)
{
	FILE *fp;

	/* Process retrieval */
	fp = popen ((QString("echo 'Y' | sudo apt-get remove ")+this->uninstallpackage+QString(" 1>/dev/null 2>/dev/null")).toLocal8Bit(), "w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	/* Package list update */
	this->readPackageList();
}

void Packages::removeUnusedPackages (void)
{
	FILE *fp;

	/* Process retrieval */
	fp = popen ((QString("echo 'Y' | sudo apt-get autoremove ")+QString(" 1>/dev/null 2>/dev/null")).toLocal8Bit(), "w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	/* Package list update */
	this->readPackageList();
}

void Packages::setUninstallPackage (QString packagename)
{
	this->uninstallpackage = packagename;
}

QString Packages::getUninstallPackage (void)
{
	return this->uninstallpackage;
}
