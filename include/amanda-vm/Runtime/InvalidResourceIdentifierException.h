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
 * File:   InvalidResourceIdentifierException.h
 * Author: Javier Marrero
 *
 * Created on May 27, 2022, 12:57 AM
 */

#ifndef INVALIDRESOURCEIDENTIFIEREXCEPTION_H
#define INVALIDRESOURCEIDENTIFIEREXCEPTION_H

#include <amanda-vm/NIO/IOException.h>
#include <amanda-vm/Runtime/ResourceIdentifier.h>

namespace amanda
{
namespace vm
{

class InvalidResourceIdentifierException : public nio::IOException
{
    AMANDA_OBJECT(InvalidResourceIdentifierException, nio::IOException)
public:

    InvalidResourceIdentifierException(const core::String& rid);
    virtual ~InvalidResourceIdentifierException() throw ();

    const core::String& getResourceIdentifier() const;

private:

    const core::String rid;
} ;

}
}

#endif /* INVALIDRESOURCEIDENTIFIEREXCEPTION_H */

