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
 * Created on April 11, 2022, 10:28 PM
 */

#include <amanda-vm/Binutils/Symbol.h>
#include <amanda-vm/Binutils/Module.h>
#include <amanda-vm/IO/MemoryOutputStream.h>
#include <amanda-vm/IO/ConsistentOutputStream.h>

using namespace amanda;
using namespace amanda::binutils;

const Symbol::SymbolTableEntry& Symbol::getNullSymbolTableEntry()
{
    static bool initialized = false;
    static SymbolTableEntry entry;

    if (!initialized)
    {
        memset(&entry, 0, sizeof(entry));

        entry.name = 0;
        entry.value = 0;
        entry.size = 0;
        entry.type = Type_None;
        entry.bind = Bind_Local;
        entry.shndx = 0;
        entry.flags &= Flag_Unresolved;

        // Set the initialized flag to true.
        initialized = true;
    }

    return entry;
}

Symbol::Symbol(const core::String& name)
:
entry(getNullSymbolTableEntry()),
module(NULL),
name(name)
{
}

Symbol::~Symbol()
{
}

const Symbol::SymbolTableEntry& Symbol::getEntry() const
{
    return entry;
}

const Module* Symbol::getModule() const
{
    return module;
}

const core::String& Symbol::getName() const
{
    return name;
}

const Section* Symbol::getSection() const
{
    return section;
}

size_t Symbol::getSize() const
{
    return this->entry.size;
}

bool Symbol::isExternalSymbol() const
{
    return entry.bind == Bind_Extern;
}

bool Symbol::isResolved() const
{
    return entry.flags & Flag_Resolved;
}

Symbol& Symbol::setBindClass(vm::vm_byte_t bind)
{
    this->entry.bind = bind;
    return *this;
}

Symbol& Symbol::setModule(Module* module)
{
    // Set the module
    this->module = module;
    
    return *this;
}

Symbol& Symbol::setResolved(bool resolved)
{
    if (resolved)
    {
        entry.flags |= Flag_Resolved;
    }
    else
    {
        entry.flags &= Flag_Unresolved;
    }
    return *this;
}

Symbol& Symbol::setSection(Section* section)
{
    // Set the section
    this->section = section;
    
    return *this;
}

Symbol& Symbol::setStringTableEntry(vm::vm_dword_t entry)
{
    this->entry.name = entry;
    return *this;
}

Symbol& Symbol::setSize(size_t size)
{
    this->entry.size = size;
    return *this;
}

Symbol& Symbol::setType(vm::vm_byte_t type)
{
    this->entry.type = type;
    return *this;
}

void Symbol::marshallImpl(io::OutputStream& stream) const
{
    stream.write(&entry, sizeof (entry));
}
