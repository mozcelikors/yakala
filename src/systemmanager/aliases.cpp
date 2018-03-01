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

#include "aliases.h"
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include <cstdio>
#include <QSettings>
#include <unistd.h>

Aliases::Aliases()
{

}

void Aliases::addAlias (QString alias, QString command)
{
	FILE *fp;

	/* Delete accidental newlines */
	QString alias_buf = alias;
	QString command_buf = command;
	alias_buf.remove(QRegExp("[\\n\\t\\r]"));
	command_buf.remove(QRegExp("[\\n\\t\\r]"));

	/* Add alias */
	fp = popen ((QString("timeout 5 echo \"alias ")+alias_buf+QString("=")+command_buf+QString("\" >> /home/$SUDO_USER/.bashrc")).toLocal8Bit(),"w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);
}

void Aliases::removeAlias (QString alias)
{
	FILE *fp;

	/* Delete accidental newlines */
	QString alias_buf = alias;
	alias_buf.remove(QRegExp("[\\n\\t\\r]"));
	alias_buf = "alias "+alias_buf;

	/* Remove alias */
	fp = popen ((QString("timeout 5 sed -i '/")+alias_buf+QString("/d' /home/$SUDO_USER/.bashrc")).toLocal8Bit(),"w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

}



void Aliases::readAliasesList (void)
{
	this->aliases.clear();
	this->commands.clear();

	FILE *fp;

	/* Open and filter alias file */
	fp = popen ("timeout 60 cat /home/$SUDO_USER/.bashrc | grep alias | sed 's/^ *//' | sed '/^#/d' | sed -n '/^alias/p' | sed -e ':1' -e 's/^alias //;t1' > /tmp/yakala.alias ","w");

	if (fp != NULL)
	{
		while (1)
		{
			if (fgets(this->buffer, MAX_ALIAS_BUFSIZE, fp) == NULL) break;
			//puts(this->buffer);

			//Delete last character
			this->buffer[strlen(buffer)-1] = 0;

		}
		//printf ("%s", this->buffer);

		//sscanf(buffer, "%s", &tmp_cpu_usage);

		//strncpy (this->aliases, buffer, strlen(buffer));

		buffer[0] = 0; //Clear array
	}
	else
	{

	}
	fclose(fp);

	/* Read from filtered temporary document using QSettings ini format */
	QSettings settings("/tmp/yakala.alias", QSettings::IniFormat);

	foreach (const QString &key, settings.childKeys())
	{
			//std::cout << key.toStdString() << std::endl;
			//std::cout << settings.value(key).toString().toUtf8().constData() << std::endl;

			// Add to out command and alias list
			aliases.append(key);
			commands.append(settings.value(key).toString());
	}
}

QStringList Aliases::getCommands (void)
{
	return this->commands;
}

QStringList Aliases::getAliases (void)
{
	return this->aliases;
}
