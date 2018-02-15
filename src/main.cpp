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

#include "main.h"
#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QFontDatabase>

#include <systeminfo.h>
#include <aliases.h>
#include <networksearch.h>
#include <environment.h>
#include <processes.h>
#include <filesearch.h>
#include <sockets.h>

SystemInfo s;
Aliases a;
NetworkSearch n;
Environment e;
Processes p;
FileSearch f;
Sockets so;

FileSearch_t myFileSearch;
NetworkSearch_t myNetworkSearch;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MainWindow w;

	/* Set a stylesheet file */
	QFile File(":/gui/stylesheet.qss");
	File.open(QFile::ReadOnly);
	QString StyleSheet = QLatin1String(File.readAll());
	a.setStyleSheet(StyleSheet);

	/* Set icon */
	QIcon icon(":/gui/icon2.ico");
	w.setWindowIcon(icon);

	/* Load Ubuntu font */
	QFontDatabase::addApplicationFont(":/gui/Ubuntu-R.ttf");

	/* Show main window / widget */
	w.show();

	return a.exec();
}
