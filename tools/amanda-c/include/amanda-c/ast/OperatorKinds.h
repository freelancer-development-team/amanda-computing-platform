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
 * File:   OperatorKinds.h
 * Author: Javier Marrero
 *
 * Created on March 21, 2022, 1:22 AM
 */

#ifndef OPERATORKINDS_H
#define OPERATORKINDS_H

namespace amanda
{
namespace compiler
{
namespace ast
{

typedef enum BinaryOperator
{
    // Comparison
    BO_Equals,
    BO_NotEquals,
    BO_Greater,
    BO_Lesser,
    BO_GreaterEquals,
    BO_LesserEquals,
    // Arithmetics
    BO_Sum,
    BO_Sub,
    BO_Mult,
    BO_Div,
    BO_Mod,
    // Logic
    BO_LogicAnd,
    BO_LogicOr,
    BO_LogicNot
} BinaryOperator;

typedef enum UnaryOperator
{
    UO_Negate
} UnaryOperator;

}
}
}

#endif /* OPERATORKINDS_H */

