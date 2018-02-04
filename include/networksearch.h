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

#ifndef NETWORKSEARCH_H
#define NETWORKSEARCH_H

#include <QString>
#include <QStringList>

#define MAX_NETWORKSEARCH_BUFSIZE 4096

class NetworkSearch
{
private:
	char buffer[MAX_NETWORKSEARCH_BUFSIZE];
	QStringList hostnames;
	QStringList ips;
public:
	NetworkSearch();
	void readNetworkAll (QString networkstart);
	void readNetworkFilterHostname (QString networkstart, QString hostname);

	QStringList getHostnames(void);
	QStringList getIPs (void);

};

#endif // NETWORKSEARCH_H
