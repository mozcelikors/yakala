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

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include <QString>
#include <QStringList>

class Environment
{
private:
	QStringList envs;
	QStringList values;
public:
	Environment();

	void readEnvList (void);
	QStringList getEnvs (void);
	QStringList getValues (void);
	void addEnv (QString env, QString value);
	void removeEnv (QString env);

};

#endif // ENVIRONMENT_H
