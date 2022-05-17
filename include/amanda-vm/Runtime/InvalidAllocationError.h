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
 * File:   InvalidAllocationError.h
 * Author: Javier Marrero
 *
 * Created on May 17, 2022, 9:51 AM
 */

#ifndef INVALIDALLOCATIONERROR_H
#define INVALIDALLOCATIONERROR_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace vm
{

class InvalidAllocationError : public core::Exception
{
    AMANDA_OBJECT(InvalidAllocationError, core::Exception)
public:

    InvalidAllocationError(const core::String& message);

    virtual ~InvalidAllocationError() throw ();
} ;

}
}

#endif /* INVALIDALLOCATIONERROR_H */

