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

#ifndef MAIN_H
#define MAIN_H

#include <systeminfo.h>
#include <aliases.h>
#include <networksearch.h>
#include <environment.h>
#include <processes.h>
#include <mainwindow.h>
#include <filesearch.h>
#include <sockets.h>

extern Processes p;
extern SystemInfo s;
extern Aliases a;
extern NetworkSearch n;
extern Environment e;
extern FileSearch f;
extern Sockets so;

extern MainWindow *w;

extern FileSearch_t myFileSearch;
extern NetworkSearch_t myNetworkSearch;

#endif // MAIN_H

