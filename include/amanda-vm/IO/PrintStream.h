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
 * File:   PrintStream.h
 * Author: Javier Marrero
 *
 * Created on February 15, 2022, 12:31 AM
 */

#ifndef PRINTSTREAM_H
#define PRINTSTREAM_H

#include <amanda-vm/Object.h>
#include <amanda-vm/io/File.h>

#include <cstdarg>

namespace amanda
{
namespace io
{

class PrintStream : public amanda::core::Object
{
    AMANDA_OBJECT(PrintStream, amanda::core::Object)
    
public:

    PrintStream(File* file);
    virtual ~PrintStream();

    virtual bool println(const core::String& fmt, ...);
    virtual bool printf(const core::String& fmt, ...);

protected:

    File* file;
} ;

}
}

#endif /* PRINTSTREAM_H */

