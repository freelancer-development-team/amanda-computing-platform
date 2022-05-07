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
 * File:   VMContext.h
 * Author: Javier Marrero
 *
 * Created on March 26, 2022, 10:46 PM
 */

#ifndef VMCONTEXT_H
#define VMCONTEXT_H

// Amanda API
#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Runtime/BaseExceptions.h>
#include <amanda-vm/Runtime/JitContext.h>

// C++ API
#include <vector>

namespace amanda
{
namespace vm
{

/**
 * The virtual machine context is a global object holding configuration data,
 * and with dispatch and execution responsibilities.
 */
class VMContext : public core::Object
{
    AMANDA_OBJECT(VMContext, core::Object)
public:

    VMContext();
    virtual ~VMContext();

private:

    core::StrongReference<jit::JitContext> jitContext;
} ;

}
}

#endif /* VMCONTEXT_H */

