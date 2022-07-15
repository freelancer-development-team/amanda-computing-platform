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

SynchronizationLock::SynchronizationLock()
:
disposed(false)
{
    // Initialize the mutex
    std::memset(nativeLock, 0, 16);
    *((pthread_mutex_t*) nativeLock) = PTHREAD_MUTEX_INITIALIZER;

    core::String failCause;

    // Lock
    int result = pthread_mutex_lock((pthread_mutex_t*) nativeLock);
    switch (result)
    {
        case EINVAL:
            failCause = "the value specified by mutex does not refer to an initialized mutex object.";
            break;
        case EAGAIN:
            failCause = "the mutex could not be acquired.";
            break;
        case EDEADLK:
            failCause = "the current thread already owns the mutex.";
            break;
        case EPERM:
            failCause = "the current thread does not own the mutex.";
            break;
    }

    if (result != 0)
    {
        throw SynchronizationError(failCause);
    }
}

SynchronizationLock::~SynchronizationLock()
{
    if (!disposed)
    {
        unlock();
    }
    pthread_mutex_destroy((pthread_mutex_t*) nativeLock);
}

void SynchronizationLock::unlock()
{
    if (!disposed)
    {
        core::String failCause;

        int result = pthread_mutex_unlock((pthread_mutex_t*) nativeLock);
        switch (result)
        {
            case EINVAL:
                failCause = "the value specified by mutex does not refer to an initialized mutex object.";
                break;
            case EAGAIN:
                failCause = "the mutex could not be acquired.";
                break;
            case EDEADLK:
                failCause = "the current thread already owns the mutex.";
                break;
            case EPERM:
                failCause = "the current thread does not own the mutex.";
                break;
        }

        if (result != 0)
        {
            throw SynchronizationError(failCause);
        }
    }
    disposed = true;
}

