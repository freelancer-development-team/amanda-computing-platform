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
 * File:   ConsistentOutputStream.h
 * Author: Javier Marrero
 *
 * Created on March 27, 2022, 12:25 AM
 */

#ifndef CONSISTENTOUTPUTSTREAM_H
#define CONSISTENTOUTPUTSTREAM_H

#include <amanda-vm/IO/OutputStream.h>

namespace amanda
{
namespace io
{

class ConsistentOutputStream : public OutputStream
{
    AMANDA_OBJECT(ConsistentOutputStream, OutputStream)
public:

    ConsistentOutputStream(const OutputStream& stream);
    virtual ~ConsistentOutputStream();

    virtual void close() const;
    virtual void write(const char* data) const;
    virtual void write(const void* data, size_t size) const;

private:

    const OutputStream& stream;
} ;

}
}

#endif /* CONSISTENTOUTPUTSTREAM_H */

