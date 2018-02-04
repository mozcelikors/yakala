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

#include "filesearch.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <QProcess>
#include <cstdio>
#include <iostream>

FileSearch::FileSearch()
{

}

void FileSearch::fileSearch (QString needle)
{
	QProcess file_search_process;
	QString exec = "/usr/bin/find";
	QStringList params;
	 params << "/" << "-name" << "*"+needle+"*";
	file_search_process.start(exec,params);
	file_search_process.waitForFinished();
	QByteArray newData=file_search_process.readAll();
	this->result = QString::fromLocal8Bit(newData);
	//std::cout << this->result.toUtf8().constData() << std::endl;
}

void FileSearch::librarySearch (QString needle)
{
	QProcess file_search_process;
	QString exec = "/usr/bin/find";
	QStringList params;
	 params << "/" << "-name" << "*lib"+needle+".*";
	file_search_process.start(exec,params);
	file_search_process.waitForFinished();
	QByteArray newData=file_search_process.readAll();
	this->result = QString::fromLocal8Bit(newData);
	//std::cout << this->result.toUtf8().constData() << std::endl;
}

QString FileSearch::getResult (void)
{
	return this->result;
}
