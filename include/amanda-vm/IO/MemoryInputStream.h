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
 * File:   MemoryInputStream.h
 * Author: Javier Marrero
 *
 * Created on June 12, 2022, 11:55 PM
 */

#ifndef MEMORYINPUTSTREAM_H
#define MEMORYINPUTSTREAM_H

#include <amanda-vm/IO/InputStream.h>

namespace amanda
{
namespace io
{

class MemoryInputStream : public InputStream
{
    AMANDA_OBJECT(MemoryInputStream, InputStream)
public:

    MemoryInputStream(void* data, bool owner = false, bool cmem = true);
    virtual ~MemoryInputStream();

    virtual void close() const;

    virtual void reset() const;
    virtual void seek(uint64_t offset) const;
    virtual uint64_t tell() const;


private:

    char*           buffer;
    mutable size_t  currentOffset;
    bool            owns;
    bool            useMalloc;
} ;

}
}

#endif /* MEMORYINPUTSTREAM_H */

