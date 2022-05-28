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
 * File:   NativeProcedure.h
 * Author: Javier Marrero
 *
 * Created on May 25, 2022, 10:57 PM
 */

#ifndef NATIVEPROCEDURE_H
#define NATIVEPROCEDURE_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace vm
{

/**
 * A native procedure is the abstract class representing a foreign function
 * call. The symbol can be stored in a dynamic link library and dynamically
 * constructed. This class encapsulates common behavior for foreign function
 * calls, no matter the target language.
 * <p>
 * The purpose of this class is to be extended by every particular subtype
 * of foreign function call.
 *
 * @author J. Marrero
 */
class NativeProcedure : public core::Object
{
    AMANDA_OBJECT(NativeProcedure, core::Object)
public:

    virtual void    addArgument(const void* __restrict__ argument) = 0;
    virtual void    call() = 0;
    virtual void*   getReturnValue() const = 0;

} ;

}
}

#endif /* NATIVEPROCEDURE_H */

