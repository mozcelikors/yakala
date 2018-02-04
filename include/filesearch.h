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

#ifndef FILESEARCH_H
#define FILESEARCH_H

#include <QString>

class FileSearch
{
private:
	QString result;
public:
	FileSearch();
	void fileSearch (QString needle);
	void librarySearch (QString needle);
	QString getResult (void);
};

#endif // FILESEARCH_H
