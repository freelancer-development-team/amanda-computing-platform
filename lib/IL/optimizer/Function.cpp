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
 * File:   Function.cpp
 * Author: Javier Marrero
 * 
 * Created on July 13, 2022, 10:12 PM
 */

#include <amanda-vm/IL/Function.h>

using namespace amanda;
using namespace amanda::il;

Function* Function::create(const Type* type, const core::String& name, Module* m)
{
    return new Function(type, name, m);
}

Function::Function(const Type* type, const core::String& name, Module* m)
:
Value(type, 0)
{
}

Function::~Function()
{
}

void Function::deleteBody() const
{
}

BasicBlock& Function::front()
{
    return basicBlocks.front()->getReference();
}

const BasicBlock& Function::front() const
{
    return basicBlocks.front()->getConstReference();
}

const BasicBlockList& Function::getBasicBlockList() const
{
    return basicBlocks;
}

BasicBlock& Function::getEntryBlock() const
{
    return basicBlocks.front()->getReference();
}

const Type* Function::getReturnType() const
{
    return getType();
}

bool Function::hasReturnValue() const
{
    return returns;
}

bool Function::isDeclaration() const
{
    //FIXME: Re-work
    return false;
}

bool Function::isThrowingExceptions() const
{
    return throwsExceptions;
}

bool Function::isVariadicFunction() const
{
    return variadic;
}

void Function::removeFromParent()
{
}

void Function::setReturns(bool returns)
{
    this->returns = returns;
}

void Function::setThrowsExceptions(bool throws)
{
    this->throwsExceptions = throws;
}




















