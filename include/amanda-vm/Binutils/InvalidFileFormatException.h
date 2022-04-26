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
 * File:   InvalidFileFormatException.h
 * Author: Javier Marrero
 *
 * Created on April 17, 2022, 2:53 PM
 */

#ifndef INVALIDFILEFORMATEXCEPTION_H
#define INVALIDFILEFORMATEXCEPTION_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace binutils
{

class InvalidFileFormatException : public core::Exception
{
    AMANDA_OBJECT(InvalidFileFormatException, core::Exception)
public:

    InvalidFileFormatException(const core::String& message = "Invalid file format.", const core::String& fileName = core::String::EMPTY);
    virtual ~InvalidFileFormatException() throw();

    const core::String& getFileName() const;

private:

    const core::String fileName;
} ;

}
}

#endif /* INVALIDFILEFORMATEXCEPTION_H */

