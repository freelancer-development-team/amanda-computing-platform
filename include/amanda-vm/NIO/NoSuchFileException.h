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
 * File:   NoSuchFileException.h
 * Author: Javier Marrero
 *
 * Created on May 22, 2022, 9:51 AM
 */

#ifndef NOSUCHFILEEXCEPTION_H
#define NOSUCHFILEEXCEPTION_H

#include <amanda-vm/NIO/IOException.h>

namespace amanda
{
namespace nio
{

/**
 * This exception is thrown when an access to a nonexistent file is performed.
 */
class NoSuchFileException : public IOException
{
    AMANDA_OBJECT(NoSuchFileException, IOException)
public:

    NoSuchFileException(const core::String& file);
    virtual ~NoSuchFileException() throw();

    const core::String& getFileName() const;

private:

    core::String file;
} ;

}
}

#endif /* NOSUCHFILEEXCEPTION_H */

