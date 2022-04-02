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
 * File:   NullJitContext.h
 * Author: Javier Marrero
 *
 * Created on March 29, 2022, 9:47 AM
 */

#ifndef NULLJITCONTEXT_H
#define NULLJITCONTEXT_H

#include <amanda-vm/Runtime/JitContext.h>

namespace amanda
{
namespace vm
{
namespace jit
{

/**
 * The null JIT context is a class for all those libraries that lack the notion
 * of a context. Though these kind of libraries are uncommon, we include them
 * for the sake of completeness. This is a template specialization of the more
 * general <code>JitContext</code> class.
 *
 * @author J. Marrero
 */
class NullJitContext : public JitContext
{
public:

    NullJitContext();

    virtual void lock() const;
    virtual void unlock() const;

} ;

}
}
}

#endif /* NULLJITCONTEXT_H */

