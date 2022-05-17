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
 * File:   JitContext.h
 * Author: Javier Marrero
 *
 * Created on March 29, 2022, 9:13 AM
 */

#ifndef JITCONTEXT_H
#define JITCONTEXT_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace vm
{
namespace jit
{

/**
 * This is an abstract class that hides the diversity of implementations of
 * contexts in JIT frameworks. Almost every JIT framework contains the notion
 * of a context, in order to be able to synchronize the machine code generation
 * with other threads. In order to hide these specific implementation details,
 * we've developed this wrapper library.
 *
 * For those frameworks that doesn't contain the notion of an object, here we
 * provide the NullJitContext class. Every operation on a NullJitContext class
 * does not do anything.
 *
 * Classes that inherit from this class are template specializations.
 *
 * @author J. Marrero
 */
class JitContext : public core::Object
{
    AMANDA_OBJECT(JitContext, core::Object)
    
public:

    virtual void lock() const = 0;
    virtual void unlock() const = 0;

    template<typename T>
    T& getContext()
    {
        return *((T*) context);
    }

protected:

    void* context;
} ;

}
}
}

#endif /* JITCONTEXT_H */

