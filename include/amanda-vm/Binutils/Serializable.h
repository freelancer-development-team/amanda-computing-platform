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
 * File:   Serializable.h
 * Author: Javier Marrero
 *
 * Created on April 9, 2022, 4:06 PM
 */

#ifndef AMANDA_BINUTILS_SERIALIZABLE_H
#define AMANDA_BINUTILS_SERIALIZABLE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/OutputStream.h>

// C++ STL
#include <vector>

namespace amanda
{
namespace binutils
{

class Serializer;

/**
 * Serializable objects are objects destined to be encoded as a mean of making
 * objects persistent.
 */
class Serializable : public core::Object
{
    AMANDA_OBJECT(Serializable, core::Object)

    // Declare friends
    friend class Serializer;

public:

    static const size_t DEFAULT_CAPACITY = sizeof (unsigned long long);
    static const float  RESIZE_FACTOR = 0.2f;  // This thing will resize a 20% of the original capacity

    Serializable();
    virtual ~Serializable();

    virtual void        addSerializationHandler(Serializer* marshaller);
    virtual void        constructBinaryData();
    const void*         getBinaryData();
    virtual size_t      getBufferLength() const;
    virtual void        marshall() const;
    virtual void        marshallSingle(Serializer* marshaller);
    virtual void        removeSerializationHandler(Serializer* marshaller);

protected:

    virtual void marshallImpl(io::OutputStream& stream) const = 0;
    virtual void resize(long long delta);
    virtual void write(const void* data, size_t size, size_t count = 1);

private:

    unsigned char*              buffer;
    size_t                      bufferLength;
    size_t                      capacity;
    size_t                      pointer;

    std::vector<Serializer*>    serializers;
} ;

}
}

#endif /* SERIALIZABLE_H */

