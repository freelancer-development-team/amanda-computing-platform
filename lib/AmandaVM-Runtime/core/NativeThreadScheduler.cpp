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
 * File:   NativeThreadScheduler.cpp
 * Author: Javier Marrero
 * 
 * Created on June 3, 2022, 2:36 AM
 */

#include <amanda-vm/Runtime/NativeThreadScheduler.h>
#include <amanda-vm/Runtime/UnschedulableException.h>

using namespace amanda;
using namespace amanda::vm;

NativeThreadScheduler::NativeThreadScheduler(const Context& context)
:
ThreadScheduler(context),
threadCount(0)
{
}

unsigned NativeThreadScheduler::getActiveThreadCount() const
{
    //TODO: Perhaps synchronize?
    return threadCount;
}

void NativeThreadScheduler::notifyThreadFinalization()
{
    AMANDA_SYNCHRONIZED(lock);
    {
        // Decrease the active thread count
        --threadCount;
    }
    AMANDA_DESYNCHRONIZED(lock);
}

void NativeThreadScheduler::schedule(const Procedure* procedure)
{
    assert(procedure != NULL && "Null pointer exception");
    if (getActiveThreadCount() > getMaximunThreadCount())
    {
        throw UnschedulableException();
    }
    // Create the schedulable
    core::WeakReference<Schedulable> schedulable
            = new Schedulable(NULL, context, amanda::eliminateConstness(procedure));

    // Add procedure to the set of procedures

    // Execute the runnable
    core::WeakReference<concurrent::Thread> thread
            = new concurrent::Thread(schedulable->getReference());
    thread->start();

    // Increase the count of active threads
    AMANDA_SYNCHRONIZED(lock);
    {
        ++threadCount;
    }
    AMANDA_DESYNCHRONIZED(lock);
}

/* =========================== EXECUTABLE RUNNABLE ========================== */



