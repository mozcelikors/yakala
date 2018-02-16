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

#ifndef THREAD_SYSTEMINFO_H
#define THREAD_SYSTEMINFO_H

#include <pthread.h>

void *Thread_NetworkSearch (void *arg);
void *Thread_FileSearch (void *arg);
void *Thread_SystemInfo (void * arg);

#endif // THREAD_SYSTEMINFO_H

