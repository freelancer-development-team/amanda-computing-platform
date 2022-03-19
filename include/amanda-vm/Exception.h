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
 * File:   Exception.h
 * Author: Javier Marrero
 *
 * Created on March 2, 2022, 12:37 PM
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <amanda-vm/Object.h>
#include <amanda-vm/Interface.h>

#include <exception>
#include <stdexcept>

namespace amanda
{
namespace core
{

/**
 * An exception represents an exceptional condition in the execution of the
 * program. Amanda makes wide use of the C++ exception handling facilities in
 * order to avoid cluttering and spaghetti code. Exceptions improve readability
 * and maintainability; and we do not support the claim that they are extremely
 * expensive. Sure they do incur in some runtime overhead, but it is normally
 * not noticeable.
 * <p>
 * Please, make use of the exception handling mechanism in a C++ idiomatic way.
 * Do not attempt to make this mechanism a glorified return, or a Java exception.
 */
class Exception : public Object, private std::exception
{
    AMANDA_OBJECT(Exception, Object)

public:

    Exception(const core::String& message);
    virtual ~Exception() throw();

    virtual const core::String& getMessage() const;

    virtual String toString() const;

private:

    core::String message;
} ;

}
}

#endif /* EXCEPTION_H */

