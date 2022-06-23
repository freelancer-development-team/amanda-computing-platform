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
 * File:   NativeThreadScheduler.h
 * Author: Javier Marrero
 *
 * Created on June 3, 2022, 2:36 AM
 */

#ifndef NATIVETHREADSCHEDULER_H
#define NATIVETHREADSCHEDULER_H

#include <amanda-vm/Runtime/ThreadScheduler.h>

//TODO: Replace by concurrence API
#include <amanda-vm/Threading/Thread.h>
#include <amanda-vm/Threading/Runnable.h>

// C
#include <deque>

namespace amanda
{
namespace vm
{

class Schedulable;

/**
 * The native thread scheduler is the simplest of the scheduler classes. It
 * relies entirely on the system's scheduling policy and creates real threads
 * that may be scheduled by the kernel to run in parallel in different processors.
 * <p>
 * This is the class that possibly yields the greater performance improvement
 * since it backs up on real threads and not in the user-land scheduling policy.
 * However, schedulers are exchangeable at runtime.
 *
 * @author J. Marrero
 */
class NativeThreadScheduler : public ThreadScheduler
{
    AMANDA_OBJECT(NativeThreadScheduler, ThreadScheduler)
public:

    NativeThreadScheduler(const Context& context);
    virtual ~NativeThreadScheduler();

    virtual unsigned        getActiveThreadCount() const;
    virtual void            notifyThreadFinalization();
    virtual Schedulable&    schedule(const Procedure* procedure);
    virtual void            waitForAll() const;

private:

    unsigned threadCount;
    std::deque<concurrent::Thread*> threads;

} ;

}
}

#endif /* NATIVETHREADSCHEDULER_H */

