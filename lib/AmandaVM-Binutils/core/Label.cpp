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
 * File:   Label.cpp
 * Author: Javier Marrero
 * 
 * Created on April 24, 2022, 1:26 PM
 */

#include <amanda-vm/Binutils/Label.h>
#include <amanda-vm/Binutils/Logging.h>

using namespace amanda;
using namespace amanda::binutils;

Label::Label(const core::String& symbolicName, vm::vm_address_t offset)
:
Instruction(vm::I_NOP, 0),
offset(offset),
symbolicName(symbolicName)
{
//    getPackageLogger().info("created label with name %s and offset %llu",
//                            symbolicName.toCharArray(), offset);
}

Label::~Label()
{
}

vm::vm_address_t Label::getOffset() const
{
    return offset;
}

const core::String& Label::getSymbolicName() const
{
    return symbolicName;
}

