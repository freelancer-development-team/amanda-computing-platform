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
 * File:   IllegalInstructionException.h
 * Author: Javier Marrero
 *
 * Created on June 20, 2022, 10:41 PM
 */

#ifndef ILLEGALINSTRUCTIONEXCEPTION_H
#define ILLEGALINSTRUCTIONEXCEPTION_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace vm
{

class IllegalInstructionException : public core::Exception
{
    AMANDA_OBJECT(IllegalInstructionException, core::Exception)
public:

    IllegalInstructionException(const core::String& message, int opcode);
    virtual ~IllegalInstructionException() throw ();

    int getOpcode() const;

private:

    int opcode;
} ;

}
}

#endif /* ILLEGALINSTRUCTIONEXCEPTION_H */

