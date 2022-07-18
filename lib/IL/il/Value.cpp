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
 * File:   Value.cpp
 * Author: Javier Marrero
 * 
 * Created on March 12, 2022, 3:36 PM
 */

#include <amanda-vm/IL/Value.h>
#include <amanda-vm/IL/ValueListener.h>
#include <amanda-vm/IL/ValueReferrer.h>

using namespace amanda;
using namespace amanda::il;

Value::Value(const Type* type, unsigned scid)
:
id(scid),
type(type)
{
    assert(type != NULL && "Null pointer exception");
}

Value::~Value()
{
    // Release a reference to the listeners
    for (ListenerList::const_iterator it = listeners.begin(), end = listeners.end();
         it != end; ++it)
    {
        (*it)->release();
    }

    // Release a reference to the users of this value
    for (ReferrerListConstIterator it = users.begin(), end = users.end(); it != end;
         ++it)
    {
        (*it)->release();
    }
}

void Value::clearMetadata()
{
}

CodeGenContext& Value::getContext() const
{
    return type->getContext();
}

const core::String& Value::getName() const
{
    return name;
}

unsigned Value::getNumberOfUsers() const
{
    return users.size();
}

const Type* Value::getType() const
{
    return type;
}

unsigned Value::getValueId() const
{
    return id;
}

bool Value::hasNUsesOrMore(const unsigned n) const
{
    return users.size() >= n;
}

bool Value::hasName() const
{
    return !name.isEmpty();
}

bool Value::hasValueListener() const
{
    return !listeners.empty();
}

bool Value::isUniquelyUsed() const
{
    return users.size() == 1;
}

bool Value::isUseListEmpty() const
{
    return users.empty();
}

bool Value::isUsed(const unsigned n) const
{
    return users.size() == n;
}

bool Value::isUsedInBasicBlock(const BasicBlock* basicBlock) const
{
    //TODO: Finish
    return false;
}

void Value::replaceAllUsesWith(Value* v)
{
    //TODO: Finish this
}

void Value::setName(const core::String& name)
{
    this->name = name;
}

void Value::takeName(Value* v)
{
    assert(this != v && "Attempted to take name from oneself");
    assert(v != NULL && "Null pointer exception");

    setName(v->getName());
    v->setName(core::String::EMPTY);
}















