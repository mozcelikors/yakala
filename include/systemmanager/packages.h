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

#ifndef PACKAGES_H
#define PACKAGES_H

#include <QString>
#include <QStringList>

class Packages
{
private:
	QStringList names;
	QStringList aptcachename;
	QStringList aptcachedescription;
	QString uninstallpackage;

public:
	Packages();

	void readPackageList (void);
	QStringList getNames (void);
	void setUninstallPackage (QString packagename);
	void searchPackages (QString needle);
	void removeUnusedPackages (void);

	void uninstallPackage (void);
	QString getUninstallPackage (void);

	void searchAptcache (QString needle);
	QStringList getAptcachenames (void);
	QStringList getAptcachedescription (void);
};


#endif // PACKAGES_H

