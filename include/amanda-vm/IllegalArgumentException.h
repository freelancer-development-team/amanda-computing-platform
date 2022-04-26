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
 * File:   IllegalArgumentException.h
 * Author: Javier Marrero
 *
 * Created on April 17, 2022, 12:01 AM
 */

#ifndef ILLEGALARGUMENTEXCEPTION_H
#define ILLEGALARGUMENTEXCEPTION_H

#include <amanda-vm/Exception.h>

namespace amanda
{
namespace core
{

/**
 * An exception class representing exceptions thrown by methods given an incorrect
 * value for an argument. This is an unchecked exception (in this context means
 * that it must not be documented by the throwing function). However, all the
 * core library functions that deal with incorrect arguments either call assert
 * (if the condition is an invariant that has been violated) or throws an
 * exception of this very type.
 *
 * @author J. Marrero
 */
class IllegalArgumentException : public Exception
{
    AMANDA_OBJECT(IllegalArgumentException, Exception)
public:

    IllegalArgumentException(const String& message = "illegal argument.");
    virtual ~IllegalArgumentException() throw();
    
} ;

}
}

#endif /* ILLEGALARGUMENTEXCEPTION_H */

