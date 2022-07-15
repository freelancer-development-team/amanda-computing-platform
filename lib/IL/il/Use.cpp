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
 * File:   Use.cpp
 * Author: Javier Marrero
 * 
 * Created on July 14, 2022, 12:53 PM
 */

#include <amanda-vm/IL/Use.h>
#include <amanda-vm/IL/ValueReferrer.h>
#include <amanda-vm/IL/Value.h>

using namespace amanda;
using namespace amanda::il;

Use::Use()
:
referrer(NULL),
value(NULL)
{
}

Use::~Use()
{

}

Value* Use::get() const
{
    return value;
}

ValueReferrer* Use::getReferrer() const
{
    return referrer;
}

Value* Use::operator ->()
{
    return value;
}

const Value* Use::operator ->() const
{
    return value;
}

Value* Use::operator =(Value* rhs)
{
    set(rhs);
    return rhs;
}

const Use& Use::operator =(const Use& rhs)
{
    set(rhs.value);
    return *this;
}

void Use::set(Value* v)
{
    value = v;
}

void Use::swap(Use& rhs)
{
    // Store old values
    Value* tempValue = rhs.value;
    ValueReferrer* tempReferrer = rhs.referrer;

    // Copy to rhs
    rhs.referrer = this->referrer;
    rhs.value = this->value;

    // Copy to own
    this->value = tempValue;
    this->referrer = tempReferrer;
}









