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
 * File:   BinaryBuffer.h
 * Author: Javier Marrero
 *
 * Created on February 26, 2022, 9:09 AM
 */

#ifndef BINARYBUFFER_H
#define BINARYBUFFER_H

#include <amanda-vm-c/sdk-assert-helper.h>
#include <amanda-vm/Object.h>

#include <cassert>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>

namespace amanda
{
namespace adt
{

/**
 * A binary buffer is a representation of an extendable memory area, fillable
 * with data. It can grow to accommodate for insertions and deletions.
 * This class shouldn't be inherited, with its destructor being not virtual
 * in purpose.
 * <p>
 * By default, it allocates a page of memory (4096 bytes). It stores the contents
 * of the buffer in a byte array that can grow. It can export its data,
 * just notice that the buffer is not zero terminated, and therefore a size
 * parameter must be passed by reference.
 * 
 */
class BinaryBuffer : public core::Object
{

    AMANDA_OBJECT(BinaryBuffer, core::Object)

public:

    BinaryBuffer()
    :
    capacity(0x1000),
    watermark(0),
    buffer((uint8_t*) calloc(capacity, sizeof (uint8_t)))
    {
        assert(buffer != NULL
               && ASSERT_MESSAGE("could not allocate the buffer."));
    }

    ~BinaryBuffer()
    {
        if (buffer != NULL)
            free(buffer);
    }

    uint8_t* exportBinaryData(size_t* size) const
    {
        *size = watermark;
        

        return buffer;
    }

    size_t size() const
    {
        return watermark;
    }

    size_t write(void* data, size_t size)
    {
        uint8_t* data_p = (uint8_t*) data;

        if (watermark + size > capacity)
        {
            capacity += size + (capacity * 0.4f);
            buffer = (uint8_t*) realloc(buffer, capacity * sizeof (uint8_t));

            assert(buffer != NULL
                   && ASSERT_MESSAGE("could not reallocate buffer."));
        }

        size_t i;
        for (i = watermark; i < (watermark + size); i++)
        {
            buffer[i] = *data_p++;
        }

        watermark = i;
        return i;
    }

private:

    size_t      capacity;
    size_t      watermark;
    uint8_t*    buffer;

} ;

}
}

#endif /* BINARYBUFFER_H */

