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
 * File:   NInteger.h
 * Author: Javier Marrero
 *
 * Created on March 21, 2022, 1:55 AM
 */

#ifndef NINTEGER_H
#define NINTEGER_H

#include <amanda-c/ast/NExpression.h>

/* Use the maximum size integer available on the platform. */
#include <stdint.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NInteger : public NExpression
{
    AMANDA_OBJECT(NInteger, NExpression)

public:

    NInteger(const core::String& literal);
    virtual ~NInteger();

    bool isSigned() const;

protected:

    core::String    literal;
    bool            signedInteger;

    union
    {
        uintmax_t   unsignedVariant;
        intmax_t    signedVariant;
    } data;

} ;

}
}
}

#endif /* NINTEGER_H */

