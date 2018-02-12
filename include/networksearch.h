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

#define FILTERTYPE_ALL_      0
#define FILTERTYPE_HOSTNAME_ 1
#define FILTERTYPE_IP_       2
#define FILTERTYPE_MAC_      3
#define FILTERTYPE_COMPANY_  4

typedef struct
{
	int finished_ = 0;  // 0-unfinished 1-finished
	int filter_type_ = 0;
	QString networkstart_;
	QString filter_text_;
} NetworkSearch_t;

class NetworkSearch
{
private:
	char buffer[MAX_NETWORKSEARCH_BUFSIZE];
	QStringList hostnames;
	QStringList ips;
	QStringList macs;
	QStringList companies;
public:
	NetworkSearch();
	void readNetworkAll (QString networkstart);
	void readNetworkFilterHostname (QString networkstart, QString hostname);
	void readNetworkFilterIP (QString networkstart, QString ip);
	void readNetworkFilterMAC (QString networkstart, QString mac);
	void readNetworkFilterCompany (QString networkstart, QString company);

	QStringList getHostnames(void);
	QStringList getIPs (void);
	QStringList getCompanies (void);
	QStringList getMACs (void);

};

#endif // NETWORKSEARCH_H
