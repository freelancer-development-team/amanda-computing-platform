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

class SynchronizationLock;
class SynchronizationLockWrapper : public core::Object
{
    AMANDA_OBJECT(SynchronizationLockWrapper, core::Object)
public:

    SynchronizationLockWrapper();
    SynchronizationLockWrapper(SynchronizationLock* lock);
    SynchronizationLockWrapper(const SynchronizationLockWrapper& rhs);
    virtual ~SynchronizationLockWrapper();

    SynchronizationLock* getLock();

private:

    SynchronizationLock* lock;
};

SynchronizationLock*    synchronized();
void                    unlock(SynchronizationLock* lock);

#define AMANDA_SYNCHRONIZED(name)   amanda::concurrent::SynchronizationLockWrapper name
#define AMANDA_DESYNCHRONIZED(name)  amanda::concurrent::unlock(name.getLock())

}
}

#endif /* SYNCHRONIZATION_H */
