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

#include "sockets.h"

#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include <cstdio>
#include <QSettings>
#include <unistd.h>
#include <QFile>

Sockets::Sockets()
{

}

void Sockets::readSocketList (void)
{
	this->protos.clear();
	this->recvQs.clear();
	this->sendQs.clear();
	this->localAddrs.clear();
	this->foreignAddrs.clear();
	this->states.clear();

	FILE *fp;

	/* Process retrieval */
	fp = popen ("timeout 5 netstat -atun | awk '{print $1\"=\"$2\"=\"$3\"=\"$4\"=\"$5\"=\"$6}' > /tmp/yakala.sockets ","w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	QFile MyFile3("/tmp/yakala.sockets");
	if (MyFile3.open(QIODevice::ReadWrite))
	{
		QTextStream in3 (&MyFile3);
		QString line3;
		while (!in3.atEnd())
		{
			line3 = in3.readLine();
			QStringList splittext = line3.split("=");
			this->protos.append(splittext.at(0));
			this->recvQs.append(splittext.at(1));
			this->sendQs.append(splittext.at(2));
			this->localAddrs.append(splittext.at(3));
			this->foreignAddrs.append(splittext.at(4));
			this->states.append(splittext.at(5));
		}
		MyFile3.close();
	}

	/* Delete useless starting info */
	for (int i = 0; i<2; i++)
	{
		this->protos.removeFirst();
		this->recvQs.removeFirst();
		this->sendQs.removeFirst();
		this->localAddrs.removeFirst();
		this->foreignAddrs.removeFirst();
		this->states.removeFirst();
	}

}

QStringList Sockets::getProtos (void)
{
	return this->protos;
}

QStringList Sockets::getRecvQs (void)
{
	return this->recvQs;
}

QStringList Sockets::getSendQs (void)
{
	return this->sendQs;
}

QStringList Sockets::getLocalAddrs (void)
{
	return this->localAddrs;
}

QStringList Sockets::getForeignAddrs (void)
{
	return this->foreignAddrs;
}

QStringList Sockets::getStates (void)
{
	return this->states;
}
