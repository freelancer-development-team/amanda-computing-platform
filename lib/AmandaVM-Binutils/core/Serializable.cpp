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
 * File:   Serializable.cpp
 * Author: Javier Marrero
 * 
 * Created on April 9, 2022, 4:06 PM
 */

#include <amanda-vm/Binutils/Serializable.h>
#include <amanda-vm/IO/ConsistentOutputStream.h>
#include <amanda-vm/IO/MemoryOutputStream.h>

// C++
#include <cstdlib>
#include <algorithm>

using namespace amanda::binutils;

Serializable::Serializable()
:
buffer((unsigned char*) std::calloc(DEFAULT_CAPACITY, sizeof (unsigned char))),
bufferLength(0),
capacity(DEFAULT_CAPACITY),
pointer(0)
{
    assert(buffer != NULL);

    serializers.reserve(2);
}

Serializable::~Serializable()
{
    for (std::vector<Serializer*>::const_iterator it = serializers.begin(),
         end = serializers.end(); it != end; ++it)
    {
        (*it)->release();
    }

    // Free the buffer
    if (buffer != NULL)
        free(buffer);
}

void Serializable::addSerializationHandler(Serializer* marshaller)
{
    assert(marshaller != NULL && "null pointer exception.");
    marshaller->grab();

    serializers.push_back(marshaller);
}

void Serializable::constructBinaryData()
{
}

const void* Serializable::getBinaryData()
{
    constructBinaryData();

    // Return the buffer as a raw memory block.
    return (const void*) buffer;
}

size_t Serializable::getBufferLength() const
{
    return bufferLength;
}

void Serializable::marshall() const
{
    for (std::vector<Serializer*>::const_iterator it = serializers.begin(),
         end = serializers.end(); it != end; ++it)
    {
        (*it)->marshall(this);
    }
}

void Serializable::marshallSingle(Serializer* marshaller)
{
    marshaller->marshall(this);
}

void Serializable::removeSerializationHandler(Serializer* marshaller)
{
    serializers.erase(std::find(serializers.begin(), serializers.end(), marshaller));
    marshaller->release();
}

void Serializable::resize(long long delta)
{
    // Update the capacity variable & realloc the buffer
    capacity += delta;

    // Resize the buffer
    buffer = (unsigned char*) std::realloc(buffer, capacity);
    assert(buffer != NULL && "Null pointer exception");
}

void Serializable::write(const void* data, size_t size, size_t count)
{
    assert(buffer != NULL && "Null pointer exception");
    assert(data != NULL && "Why?");

    // State variables
    const size_t totalSize = size * count;

    // Resize if necessary
    if (pointer + totalSize > capacity)
    {
        resize(((pointer + totalSize) - capacity) + (capacity * RESIZE_FACTOR));
    }

    // Write
    // BEWARE: Pointer arithmetic!!!!
    io::MemoryOutputStream      memoryStream(buffer + pointer);
    io::ConsistentOutputStream  objectStream(memoryStream);

    // Write
    objectStream.write(data, size, count);

    // Increase the pointer
    pointer += totalSize;

    // Update the buffer length variable
    bufferLength += totalSize;
}
