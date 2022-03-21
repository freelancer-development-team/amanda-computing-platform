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
 * File:   SyntaxException.h
 * Author: Javier Marrero
 *
 * Created on March 18, 2022, 12:42 AM
 */

#ifndef SYNTAXEXCEPTION_H
#define SYNTAXEXCEPTION_H

#include <amanda-vm/TypeSystem.h>

namespace amanda
{
namespace frontend
{

/**
 * This class represents parser errors raised as a result of a syntax error.
 */
class SyntaxException : public core::Exception
{
    AMANDA_OBJECT(SyntaxException, core::Exception)

public:

    SyntaxException(const core::String& msg);
    virtual ~SyntaxException() throw();

    virtual core::String toString() const;
} ;

}
}

#endif /* SYNTAXEXCEPTION_H */

