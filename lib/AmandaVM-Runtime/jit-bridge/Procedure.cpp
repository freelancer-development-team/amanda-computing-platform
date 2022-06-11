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
 * File:   Procedure.cpp
 * Author: Javier Marrero
 * 
 * Created on June 3, 2022, 2:48 AM
 */

#include <amanda-vm/Runtime/Procedure.h>
#include <amanda-vm/Runtime/Context.h>
#include <amanda-vm/Threading/Runnable.h>
#include <amanda-vm/Threading/Thread.h>
#include <amanda-vm/System.h>

// C/C++
#include <ck_spinlock.h>

using namespace amanda;
using namespace amanda::vm;

Procedure::Procedure(const Context& context, binutils::Function* symbol)
:
context(context),
executionCount(0),
symbol(symbol)
{
}

Procedure::~Procedure()
{
    for (std::deque<const AdaptiveOptimizationCondition*>::const_iterator it = optimizationCritera.begin(),
         end = optimizationCritera.end(); it != end; ++it)
    {
        // Release the previously grabbed reference
        (*it)->release();
    }
}

void Procedure::addOptimizationCriteria(const AdaptiveOptimizationCondition* criteria)
{
    // Grab a reference to the object
    criteria->grab();

    // Push it into the list
    optimizationCritera.push_back(criteria);
}

void Procedure::applyStack(Stack * const stack)
{
    this->stack = stack;
}

bool Procedure::equals(const Object* object)
{
    bool result = false;
    if (object->is<Procedure>())
    {
        if (static_cast<const Procedure*> (object)->getName() == getName())
        {
            result = true;
        }
    }
    return result;
}

void Procedure::execute()
{
    if (isOptimized())
    {
        /* Run the 'jitted' code. */
        executeOptimized();
    }
    else
    {
        /* Interpret the code */
        executeInterpreted();
    }

    // Check if needs optimization
    if (!isOptimized() && shouldOptimize())
    {
        optimize();
    }

    // Increment the count of executions
    ++executionCount;
}

void Procedure::executeInterpreted()
{
}

void Procedure::executeOptimized()
{
}

const core::String& Procedure::getName() const
{
    return symbol->getName();
}

bool Procedure::isOptimized() const
{
    bool result = false;
    AMANDA_SYNCHRONIZED(lock);
    {
        result = optimized;
    }
    AMANDA_DESYNCHRONIZED(lock);

    return result;
}

void Procedure::optimize()
{
    /*
     * The optimization process is run in parallel in order to not to stop the
     * execution of the program. In uniprocessor machines this can increase the
     * overhead of building a function, so make it run in parallel only if we
     * may take advantage of true parallelism.
     */
    OptimizationRunnable runnable(this->getReference());
    if (core::getNumberOfAvailableCores() > 1)
    {
        concurrent::Thread thread(runnable);
        thread.start();
    }
    else
    {
        runnable.run();
    }
}

void Procedure::setOptimized(bool optimized)
{
    AMANDA_SYNCHRONIZED(lock);
    {
        this->optimized = optimized;
    }
    AMANDA_DESYNCHRONIZED(lock);
}

bool Procedure::shouldOptimize() const
{
    bool result = true;
    for (std::deque<const AdaptiveOptimizationCondition*>::const_iterator it = optimizationCritera.begin(),
         end = optimizationCritera.end(); it != end; ++it)
    {
        result = result && (*it)->eval();
    }
    return result && (executionCount > 2);
}

// ======================= OPTIMIZATION RUNNABLE ===============================

Procedure::OptimizationRunnable::OptimizationRunnable(Procedure& procedure)
:
procedure(procedure)
{
}

void Procedure::OptimizationRunnable::run()
{

    // Set the optimization flag as true
    procedure.setOptimized(true);
}
