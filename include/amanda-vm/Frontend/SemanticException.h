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
 * File:   SemanticException.h
 * Author: Javier Marrero
 *
 * Created on March 23, 2022, 1:14 AM
 */

#ifndef SEMANTICEXCEPTION_H
#define SEMANTICEXCEPTION_H

#include <amanda-vm/Exception.h>

namespace amanda
{
namespace frontend
{

/**
 * Semantic exceptions are exceptions throw by the semantic analysis phase of
 * the compiler.
 *
 * @author J. Marrero
 */
class SemanticException : public core::Exception
{
    AMANDA_OBJECT(SemanticException, core::Exception)

public:

    SemanticException(const core::String& msg);
    virtual ~SemanticException() throw();
} ;

}
}

#endif /* SEMANTICEXCEPTION_H */

