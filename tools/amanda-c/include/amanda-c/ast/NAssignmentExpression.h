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
 * File:   NAssignmentExpression.h
 * Author: Javier Marrero
 *
 * Created on March 22, 2022, 6:07 PM
 */

#ifndef NASSIGNMENTEXPRESSION_H
#define NASSIGNMENTEXPRESSION_H

#include <amanda-c/ast/NExpression.h>
#include <amanda-c/ast/NIdentifier.h>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NAssignmentExpression : public NExpression
{
    AMANDA_OBJECT(NAssignmentExpression, NExpression)

public:

    NAssignmentExpression(NIdentifier* lhs, NExpression* rhs);
    virtual ~NAssignmentExpression();
    
protected:

    core::StrongReference<NIdentifier> lhs;
    core::StrongReference<NExpression> rhs;
} ;

}
}
}

#endif /* NASSIGNMENTEXPRESSION_H */

