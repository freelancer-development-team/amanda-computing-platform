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
 * File:   Symbol.cpp
 * Author: Javier Marrero
 * 
 * Created on April 6, 2022, 8:16 PM
 */

#include <amanda-vm/Binutils/Linker/Symbol.h>

using namespace amanda;
using namespace amanda::binutils::ld;

Symbol::Symbol(const core::String& name)
:
name(name),
size(-1)
{
}

Symbol::~Symbol()
{
}

sdk_ullong_t Symbol::computeSize() const
{
    return 0ull;
}

const core::String& Symbol::getName() const
{
    return name;
}

const sdk_ullong_t Symbol::getSize() const
{
    return (size == (sdk_ullong_t) -1) ? computeSize() : size;
}

bool Symbol::is(const unsigned kind) const
{
    return kind == this->kind;
}
