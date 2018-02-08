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

#include "environment.h"
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include <cstdio>
#include <QSettings>
#include <unistd.h>

Environment::Environment()
{

}

void Environment::addEnv (QString env, QString value)
{
	FILE *fp;

	/* Delete accidental newlines */
	QString env_buf = env;
	QString value_buf = value;
	env_buf.remove(QRegExp("[\\n\\t\\r]"));
	value_buf.remove(QRegExp("[\\n\\t\\r]"));

	/* Add env */
	fp = popen ((QString("timeout 5 echo \"export ")+env_buf+QString("=")+value_buf+QString("\" >> /home/$SUDO_USER/.bashrc ")).toLocal8Bit(),"w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);
}

void Environment::removeEnv (QString env)
{

}

void Environment::readEnvList (void)
{
	this->envs.clear();
	this->values.clear();

	FILE *fp;

	/* Open and filter env */
	fp = popen ("sudo -i -u mozcelikors sh -c '. /home/mozcelikors/.bashrc && printenv > /tmp/yakala.env' ","w");

	if (fp != NULL)
	{

	}
	else
	{

	}
	fclose(fp);

	/* Read from filtered temporary document using QSettings ini format */
	QSettings settings("/tmp/yakala.env", QSettings::IniFormat);

	foreach (const QString &key, settings.childKeys())
	{
			// Add to out command and environment list
			this->envs.append(key);
			this->values.append(settings.value(key).toString());
	}
}

QStringList Environment::getValues (void)
{
	return this->values;
}

QStringList Environment::getEnvs (void)
{
	return this->envs;
}
