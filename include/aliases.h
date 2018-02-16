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

#ifndef ALIASES_H
#define ALIASES_H

#include <QString>
#include <QStringList>

#define MAX_ALIAS_BUFSIZE 4096
class Aliases
{
private:
	QStringList commands;
	QStringList aliases;
	char buffer[MAX_ALIAS_BUFSIZE];
public:
	Aliases();

	void readAliasesList (void);
	QStringList getCommands (void);
	QStringList getAliases (void);
	void addAlias (QString alias, QString command);
	void removeAlias (QString alias);

};

#endif // ALIASES_H
