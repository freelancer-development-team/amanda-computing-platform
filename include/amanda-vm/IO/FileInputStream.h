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
 * File:   FileInputStream.h
 * Author: Javier Marrero
 *
 * Created on March 27, 2022, 1:03 AM
 */

#ifndef FILEINPUTSTREAM_H
#define FILEINPUTSTREAM_H

#include <amanda-vm/IO/File.h>
#include <amanda-vm/IO/InputStream.h>

namespace amanda
{
namespace io
{

class FileInputStream : public InputStream
{
    AMANDA_OBJECT(FileInputStream, InputStream)

public:

    FileInputStream(const File* file);
    FileInputStream(const File& file);
    virtual ~FileInputStream();

    virtual void        close() const;
    virtual int         read(void* buffer, size_t size, size_t count) const;
    virtual void        reset() const;
    virtual void        seek(uint64_t offset) const;
    virtual uint64_t    tell() const;
    
private:

    mutable const File* file;
    bool                inHeap;
} ;

}
}

#endif /* FILEINPUTSTREAM_H */

