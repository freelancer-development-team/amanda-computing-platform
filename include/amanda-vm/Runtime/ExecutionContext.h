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
 * File:   ExecutionContext.h
 * Author: Javier Marrero
 *
 * Created on March 25, 2022, 11:57 AM
 */

#ifndef EXECUTIONCONTEXT_H
#define EXECUTIONCONTEXT_H

#include <amanda-vm/Runtime/VMStack.h>

namespace amanda
{
namespace vm
{

/**
 * Each thread gains its corresponding execution context, and contexts are
 * separated in a per-thread manner. Execution contexts are dispatched via a
 * global executor that runs in the virtual machine main thread. This ensures
 * that even in the case of a fatal error the virtual machine itself can
 * recover simply by shutting down the problematic thread.
 * 
 * @author J. Marrero
 */
class ExecutionContext : public core::Object
{
    AMANDA_OBJECT(ExecutionContext, core::Object)
public:

private:

    VMStack stack;
} ;

}
}

#endif /* EXECUTIONCONTEXT_H */

