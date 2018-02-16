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

#ifndef FILESEARCH_H
#define FILESEARCH_H

#include <QString>

#define FILESEARCH_ 0
#define LIBSEARCH_  1

typedef struct
{
	int finished_ = 0;  // 0-unfinished 1-finished
	int file_or_library_ = 0; // 0-file 1-library
	QString folder_;
	QString text_;
} FileSearch_t;

class FileSearch
{
private:
	QString result;
public:
	FileSearch();
	void fileSearch (QString needle, QString folder);
	void librarySearch (QString needle);
	QString getResult (void);
};

#endif // FILESEARCH_H
