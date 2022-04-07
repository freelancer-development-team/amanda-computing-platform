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
 * File:   Stream.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 1:37 AM
 */

#ifndef STREAM_H
#define STREAM_H

#include <amanda-vm/Object.h>
#include <amanda-vm/IO/File.h>
#include <amanda-vm/IO/Closeable.h>

#include <cstdio>

namespace amanda
{
namespace io
{

/**
 * This is the base class for any stream. It presents a consistent interface
 * to be used by writer objects.
 */
class OutputStream : extends core::Object, implements Closeable
{
    AMANDA_OBJECT(OutputStream, core::Object)

public:

    OutputStream();
    virtual ~OutputStream();

    virtual void flush() const;
    virtual void write(const char* data) const;
    virtual void write(const void* data, size_t size) const;
    virtual void write(const void* data, size_t size, size_t count) const;
} ;

}
}

#endif /* STREAM_H */

