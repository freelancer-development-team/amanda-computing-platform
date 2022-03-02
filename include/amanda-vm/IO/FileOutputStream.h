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
 * File:   FileOutputStream.h
 * Author: Javier Marrero
 *
 * Created on March 1, 2022, 1:46 AM
 */

#ifndef FILEOUTPUTSTREAM_H
#define FILEOUTPUTSTREAM_H

#include <amanda-vm/IO/OutputStream.h>

namespace amanda
{
namespace io
{

class FileOutputStream : public OutputStream
{
    AMANDA_OBJECT(FileOutputStream, OutputStream)

public:

    FileOutputStream(const File* file);
    virtual ~FileOutputStream();

    virtual void close();

protected:

    const File* file;
    
private:

    void releaseResource();
} ;

}
}

#endif /* FILEOUTPUTSTREAM_H */

