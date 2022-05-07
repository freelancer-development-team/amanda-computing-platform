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
 * File:   VMThreadContext.h
 * Author: Javier Marrero
 *
 * Created on March 28, 2022, 7:32 PM
 */

#ifndef VMTHREADCONTEXT_H
#define VMTHREADCONTEXT_H

// Amanda C++ API
#include <amanda-vm/TypeSystem.h>

// Amanda C API
#include <amanda-vm-c/sdk-jit-engine.h>

namespace amanda
{
namespace vm
{

/**
 * The thread context
 */
class VMThreadContext : public core::Object
{
    AMANDA_OBJECT(VMThreadContext, core::Object)
public:

    VMThreadContext();
    virtual ~VMThreadContext();

private:

    
} ;

}
}

#endif /* VMTHREADCONTEXT_H */

