/*
 * Copyright (C) 2022 Javier Marrero
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
 * File:   Synchronization.cpp
 * Author: Javier Marrero
 * 
 * Created on March 25, 2022, 12:49 AM
 */

#include <amanda-vm/Threading/Synchronization.h>
#include <amanda-vm/Threading/SynchronizationError.h>
#include <amanda-vm/TypeSystem.h>

// This should be compiled with PThreads installed...
// Now pthreads is a dependency. It would be nice to be able to abstract all
// the low level details even more... make this threading API independent.
// At least the high level interface works... or so.
#include <pthread.h>
#include <unistd.h>


using namespace amanda;
using namespace amanda::concurrent;

class amanda::concurrent::SynchronizationLock : public core::Object
{

    AMANDA_OBJECT(SynchronizationLock, core::Object)
public:

    SynchronizationLock()
    {
        mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_lock(&mutex);
    }

    ~SynchronizationLock()
    {
        pthread_mutex_unlock(&mutex);
    }

private:

    pthread_mutex_t mutex;
};

SynchronizationLock* amanda::concurrent::synchronized()
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    SynchronizationLock* lock = NULL;

    try
    {
        lock = new SynchronizationLock();
        lock->grab();
    }
    catch (...)
    {
        throw SynchronizationError("Unable to create mutex object.");
    }

    pthread_mutex_unlock(&mutex);
    return lock;
}

void amanda::concurrent::unlock(SynchronizationLock* lock)
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);

    try
    {
        if (lock != NULL)
        {
            lock->release();
        }
    }
    catch (...)
    {
        throw SynchronizationError("Unable to exit synchronized block. Possible deadlock occurring.");
    }
    
    pthread_mutex_unlock(&mutex);
}

// WRAPPER OBJECT

SynchronizationLockWrapper::SynchronizationLockWrapper()
:
lock(amanda::concurrent::synchronized())
{
    assert(lock != NULL);
    lock->grab();
}

SynchronizationLockWrapper::SynchronizationLockWrapper(SynchronizationLock* lock)
:
lock(lock)
{
    assert(lock != NULL);
    lock->grab();
}

SynchronizationLockWrapper::SynchronizationLockWrapper(const SynchronizationLockWrapper& rhs)
:
lock(rhs.lock)
{
    lock->grab();
}

SynchronizationLockWrapper::~SynchronizationLockWrapper()
{
    assert(lock != NULL);
    unlock(lock);
}

SynchronizationLock* SynchronizationLockWrapper::getLock()
{
    return lock;
}

