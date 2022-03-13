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
 * File:   NExpression.h
 * Author: Javier Marrero
 *
 * Created on March 12, 2022, 11:56 PM
 */

#ifndef NEXPRESSION_H
#define NEXPRESSION_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IL/AstNodeBase.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NExpression : public il::AstNodeBase
{
    AMANDA_OBJECT(NExpression, il::AstNodeBase)
    
public:

    
} ;

}
}
}

#endif /* NEXPRESSION_H */

