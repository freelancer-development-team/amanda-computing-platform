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
 * File:   ValueReferrer.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 3:57 PM
 */

#include <amanda-vm/IL/ValueReferrer.h>
#include <amanda-vm/IL/Value.h>

// C++
#include <cstdarg>
#include <algorithm>

using namespace amanda;
using namespace amanda::il;

UseList ValueReferrer::buildOperandList(unsigned numOperands, ...)
{
    UseList result;
    va_list va;
    va_start(va, numOperands);
    for (unsigned i = 0; i < numOperands; ++i)
    {
        result.push_back(va_arg(va, Use));
    }
    va_end(va);
    return result;
}

ValueReferrer::ValueReferrer(const Type* type, unsigned vty)
:
Value(type, vty)
{
}

ValueReferrer::ValueReferrer(const Type* type, unsigned vty, const UseList& operandList)
:
Value(type, vty)
{
    // Reserve space and copy the vector
    this->operandList.reserve(operandList.size());
    std::copy(operandList.begin(), operandList.end(), this->operandList.begin());
}

ValueReferrer::~ValueReferrer()
{
}

unsigned ValueReferrer::getNumberOfOperands() const
{
    return operandList.size();
}

Value* ValueReferrer::getOperand(unsigned i) const
{
    return operandList.at(i).get();
}

const UseList& ValueReferrer::getOperandList() const
{
    return operandList;
}

Use& ValueReferrer::getOperandUse(unsigned i)
{
    return operandList.at(i);
}

void ValueReferrer::replaceUsesOfWith(Value* from, Value* to)
{
    if (from == to) return;

    for (unsigned i = 0; i < getNumberOfOperands(); ++i)
    {
        if (getOperand(i) == from)
        {
            setOperand(i, to);
        }
    }
}

void ValueReferrer::setOperand(unsigned i, Value* v)
{
    assert(i < operandList.size() && "Out of range!!");
    operandList[i] = v;
}








