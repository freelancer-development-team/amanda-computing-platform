/*
 * Copyright (C) 2022 FreeLancer Development Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   Synchronization.h
 * Author: Javier Marrero
 *
 * Created on March 25, 2022, 12:49 AM
 */

#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include <amanda-vm/Object.h>

namespace amanda
{
namespace concurrent
{

class SynchronizationLock : public core::Object
{
    AMANDA_OBJECT(SynchronizationLock, core::Object)
public:

    SynchronizationLock();
    virtual ~SynchronizationLock();

    void unlock();

private:

    bool    disposed;
    char    nativeLock[16];
} ;

#define AMANDA_SYNCHRONIZED(name)       amanda::concurrent::SynchronizationLock name
#define AMANDA_DESYNCHRONIZED(name)     name.unlock()

}
}

#endif /* SYNCHRONIZATION_H */
