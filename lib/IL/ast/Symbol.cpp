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
 * File:   Symbol.cpp
 * Author: Javier Marrero
 * 
 * Created on February 24, 2022, 11:46 PM
 */

#include <amanda-vm/IL/Symbol.h>

using amanda::il::Symbol;
using amanda::core::String;

Symbol::Symbol(const core::String& name)
:
name(name)
{
}

Symbol::~Symbol()
{
}

const String& Symbol::getName() const
{
    return name;
}
