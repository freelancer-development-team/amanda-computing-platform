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
 * File:   BaseExceptions.h
 * Author: Javier Marrero
 *
 * Created on March 28, 2022, 7:41 PM
 */

#ifndef BASEEXCEPTIONS_H
#define BASEEXCEPTIONS_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace vm
{

class VMRuntimeException : public core::Exception
{
    AMANDA_OBJECT(VMRuntimeException, core::Exception)

public:

    VMRuntimeException(const core::String& message)
    :
    core::Exception(message)
    {   
    }

    virtual ~VMRuntimeException() throw()
    {
    }

};

}
}

#endif /* BASEEXCEPTIONS_H */

