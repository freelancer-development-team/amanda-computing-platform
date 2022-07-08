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
 * File:   IllegalStateException.h
 * Author: Javier Marrero
 *
 * Created on June 22, 2022, 12:18 AM
 */

#ifndef ILLEGALSTATEEXCEPTION_H
#define ILLEGALSTATEEXCEPTION_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace vm
{

class IllegalStateException : public core::Exception
{
    AMANDA_OBJECT(IllegalStateException, core::Exception)
public:

    IllegalStateException(const core::String& message);
    virtual ~IllegalStateException() throw ();

} ;

}
}

#endif /* ILLEGALSTATEEXCEPTION_H */

