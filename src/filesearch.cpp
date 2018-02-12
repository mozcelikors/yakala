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
#include <QDirIterator>
#include <QtDebug>

FileSearch::FileSearch()
{

}

void FileSearch::fileSearch (QString needle)
{
	this->result = "";

	/*QProcess file_search_process;
	QString exec = "locate";
	QStringList params;
	 params << needle;
	file_search_process.start(exec,params);
	file_search_process.waitForFinished();
	QByteArray newData=file_search_process.readAllStandardOutput();
	this->result = QString::fromLocal8Bit(newData);
	//std::cout << this->result.toUtf8().constData() << std::endl;*/

	QDirIterator dirIt("/",QDirIterator::Subdirectories);
	while (dirIt.hasNext()) {
		dirIt.next();
		if (QFileInfo(dirIt.filePath()).isFile())
			if(dirIt.filePath().contains(needle, Qt::CaseInsensitive))
			{
				//qDebug()<<dirIt.filePath();
				this->result.append(dirIt.filePath()+"\n");
			}

	}
}

void FileSearch::librarySearch (QString needle)
{
	this->result = "";

	/*QProcess file_search_process;
	QString exec = "/usr/bin/find";
	QStringList params;
	 params << "/" << "-name" << "*lib"+needle+".*";
	file_search_process.start(exec,params);
	file_search_process.waitForFinished();
	QByteArray newData=file_search_process.readAll();
	this->result = QString::fromLocal8Bit(newData);
	//std::cout << this->result.toUtf8().constData() << std::endl;*/

	QDirIterator dirIt("/",QDirIterator::Subdirectories);
	while (dirIt.hasNext()) {
		dirIt.next();
		if (QFileInfo(dirIt.filePath()).isFile())
			if(dirIt.filePath().contains(needle+".a", Qt::CaseInsensitive))
			{
				//qDebug()<<dirIt.filePath();
				this->result.append(dirIt.filePath()+"\n");
			}
			if(dirIt.filePath().contains(needle+".so", Qt::CaseInsensitive))
			{
				//qDebug()<<dirIt.filePath();
				this->result.append(dirIt.filePath()+"\n");
			}
			if(dirIt.filePath().contains(needle+".o", Qt::CaseInsensitive))
			{
				//qDebug()<<dirIt.filePath();
				this->result.append(dirIt.filePath()+"\n");
			}
	}
}

QString FileSearch::getResult (void)
{
	return this->result;
}
