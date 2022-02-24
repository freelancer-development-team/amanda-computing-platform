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
 * File:   Object.cpp
 * Author: Javier Marrero
 * 
 * Created on February 13, 2022, 2:26 PM
 */

#include <amanda-vm/Object.h>

#include <string.h>
#include <stdint.h>

using amanda::core::Object;
using amanda::core::String;
using amanda::core::Class;

/* OBJECT */
Class& Object::getClass()
{
    static Class _class("amanda::core::Object", NULL);
    return _class;
}

Object::Object()
{
}

Object::Object(const Object& original)
{
}

Object::~Object()
{
}

Object* Object::clone()
{
    return new Object(*this);
}

bool Object::equals(const Object* object)
{
    return this == object;
}

int Object::hashCode()
{
    int hash = 0;

    uint8_t* mem = (uint8_t*) this;
    for (size_t i = 0; i < sizeof (i); i++)
    {
        uint8_t c = *mem++;

        hash += c;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

String Object::toString() const
{
    return getClass().getName();
}

bool Object::operator ==(const Object& rhs)
{
    return equals(&rhs);
}

bool Object::operator ==(const Object* rhs)
{
    return equals(rhs);
}
