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

#ifndef SOCKETS_H
#define SOCKETS_H

#include <QStringList>

class Sockets
{
private:
	QStringList protos;
	QStringList recvQs;
	QStringList sendQs;
	QStringList localAddrs;
	QStringList foreignAddrs;
	QStringList states;
public:
	Sockets();
	void readSocketList (void);
	QStringList getProtos (void);
	QStringList getRecvQs (void);
	QStringList getSendQs(void);
	QStringList getLocalAddrs (void);
	QStringList getForeignAddrs (void);
	QStringList getStates (void);
};

#endif // SOCKETS_H
