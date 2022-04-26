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
 * File:   Serializer.h
 * Author: Javier Marrero
 *
 * Created on April 9, 2022, 4:10 PM
 */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/OutputStream.h>

namespace amanda
{
namespace binutils
{

class Serializable;

/**
 * A 'Serializer' is an object that is capable to provide a valid output stream
 * for serialization purposes. They are serialization handlers, and multiple
 * instances of these objects can be attached to a single serializable object.
 * 
 */
class Serializer : public core::Object
{
    AMANDA_OBJECT(Serializer, core::Object)
public:

    Serializer(io::OutputStream* stream);

    virtual void marshall(const Serializable* serializable) const;

protected:

    core::StrongReference<io::OutputStream> outputStream;
} ;

}
}

#endif /* SERIALIZER_H */

