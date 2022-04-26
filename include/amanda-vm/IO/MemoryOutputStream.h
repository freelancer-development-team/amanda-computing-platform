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
 * File:   MemoryOutputStream.h
 * Author: Javier Marrero
 *
 * Created on April 9, 2022, 11:05 PM
 */

#ifndef MEMORYOUTPUTSTREAM_H
#define MEMORYOUTPUTSTREAM_H

#include <amanda-vm/IO/OutputStream.h>

namespace amanda
{
namespace io
{

class MemoryOutputStream : public OutputStream
{
public:

    MemoryOutputStream(const void* buffer, bool deleteOnClose = false, bool usesNewOperator = false);
    virtual ~MemoryOutputStream();

    virtual void    close() const;
    virtual void    flush() const;
    bool            isUsingNewOperator() const;
    virtual void    write(const void* data, size_t size) const;

private:

    mutable char*   buffer;
    const bool      deleteOnClose;
    mutable size_t  pointer;
    const bool      usesNewOperator;
} ;

}
}

#endif /* MEMORYOUTPUTSTREAM_H */

