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
 * File:   NBoolean.h
 * Author: Javier Marrero
 *
 * Created on March 22, 2022, 6:17 PM
 */

#ifndef NBOOLEAN_H
#define NBOOLEAN_H

#include <amanda-c/ast/NExpression.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NBoolean : public NExpression
{
public:

    NBoolean(bool value);
    virtual ~NBoolean();
    
protected:

    bool value;
} ;

}
}
}

#endif /* NBOOLEAN_H */

