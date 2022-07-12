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
 * File:   ThreadScheduler.h
 * Author: Javier Marrero
 *
 * Created on May 21, 2022, 11:58 PM
 */

#ifndef THREADSCHEDULER_H
#define THREADSCHEDULER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Runtime/Schedulable.h>
#include <amanda-vm/Runtime/Procedure.h>

namespace amanda
{
namespace vm
{

class Schedulable;
class Context;

/**
 * The <code>ThreadScheduler</code> class defines a contract that concrete
 * implementor classes must fulfill in order to comply with the virtual machine
 * scheduling policies.
 */
class ThreadScheduler : public core::Object
{
    AMANDA_OBJECT(ThreadScheduler, core::Object)
public:

    ThreadScheduler(const Context& context);

    virtual Schedulable&    schedule(const Procedure* procedure) = 0;
    virtual unsigned        getActiveThreadCount() const = 0;
    virtual unsigned        getMaximunThreadCount() const;
    virtual void            setMaximumThreadCount(unsigned count);
    virtual void            waitForAll() const = 0;

protected:

    const Context&      context;
    unsigned            maxThreads;
} ;

}
}

#endif /* THREADSCHEDULER_H */

