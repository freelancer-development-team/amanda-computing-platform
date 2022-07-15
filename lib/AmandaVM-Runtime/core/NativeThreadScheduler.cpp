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
 * File:   NativeThreadScheduler.cpp
 * Author: Javier Marrero
 * 
 * Created on June 3, 2022, 2:36 AM
 */

#include <amanda-vm/Runtime/NativeThreadScheduler.h>
#include <amanda-vm/Runtime/UnschedulableException.h>
#include <amanda-vm/Runtime/Schedulable.h>

using namespace amanda;
using namespace amanda::vm;

NativeThreadScheduler::NativeThreadScheduler(const Context& context)
:
ThreadScheduler(context),
threadCount(0)
{
}

NativeThreadScheduler::~NativeThreadScheduler()
{
    waitForAll();
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

Schedulable& NativeThreadScheduler::schedule(const Procedure* procedure)
{
    assert(procedure != NULL && "Null pointer exception");
    for (unsigned i = 0; i < threads.size(); ++i)
    {
        if (threads.at(i)->isDead())
        {
            threads.at(i)->release();
            threads.erase(threads.begin() + i);

            notifyThreadFinalization();
        }
    }
    if (getActiveThreadCount() > getMaximunThreadCount())
    {
        throw UnschedulableException();
    }

    // Create the schedulable
    core::WeakReference<Schedulable> schedulable
            = new Schedulable(NULL, context, amanda::eliminateConstness(procedure));

    // Execute the runnable
    core::WeakReference<concurrent::Thread> thread
            = new concurrent::Thread(schedulable->getReference());

    // Start the thread we've just scheduled
    thread->start();

    // Increase the count of active threads
    AMANDA_SYNCHRONIZED(lock);
    {
        // Grab reference
        thread->grab();

        // Push the thread
        threads.push_front(thread);
        ++threadCount;
    }
    AMANDA_DESYNCHRONIZED(lock);

    return schedulable->getReference();
}

void NativeThreadScheduler::waitForAll() const
{
    AMANDA_SYNCHRONIZED(lock);
    {
        for (std::deque<concurrent::Thread*>::const_iterator it = threads.begin(),
             end = threads.end(); it != end; ++it)
        {
            concurrent::Thread* thread = *it;
            if (thread != NULL)
            {
                if (thread->isDead() == false)
                {
                    concurrent::Thread::wait((*it)->getThreadId());
                }
            }
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
}

/* =========================== EXECUTABLE RUNNABLE ========================== */



