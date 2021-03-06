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
 * Created on April 11, 2022, 10:28 PM
 */

#include <amanda-vm/Binutils/Symbol.h>
#include <amanda-vm/Binutils/Module.h>
#include <amanda-vm/IO/MemoryOutputStream.h>
#include <amanda-vm/IO/ConsistentOutputStream.h>

using namespace amanda;
using namespace amanda::binutils;

const core::String Symbol::getBindStringFromValue(int bind)
{
    core::String result("UNKNOWN");
    switch (bind)
    {
        case Bind_Extern:
            result = "EXTERN";
            break;
        case Bind_Global:
            result = "GLOBAL";
            break;
        case Bind_Local:
            result = "LOCAL";
            break;
        case Bind_Native:
            result = "NATIVE";
            break;
        case Bind_Weak:
            result = "WEAK";
            break;
    }
    return result;
}

const core::String Symbol::getTypeStringFromValue(int type)
{
    core::String result("UNKNOWN");
    switch (type)
    {
        case Type_Function:
            result = "FUNCTION";
            break;
        case Type_Object:
            result = "DATA OBJECT";
            break;
    }
    return result;
}

const Symbol::SymbolTableEntry& Symbol::getNullSymbolTableEntry()
{
    static bool initialized = false;
    static SymbolTableEntry entry;

    if (!initialized)
    {
        memset(&entry, 0, sizeof (entry));

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

bool Symbol::equals(const Object* object)
{
    bool result = false;
    if (object != NULL && object->is<Symbol>())
    {
        const Symbol* symbol = static_cast<const Symbol*> (object);
        result = (symbol->getName() == this->getName())
                && (symbol->getEntry().bind == this->getEntry().bind)
                && (symbol->getEntry().type == this->getEntry().type);
    }
    else
    {
        result = (this == object);
    }
    return result;
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

bool Symbol::isNativeProcedure() const
{
    return entry.bind == Bind_Native;
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

Symbol& Symbol::setSectionIndex(unsigned index)
{
    this->entry.shndx = index;

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

Symbol& Symbol::setValue(vm::vm_address_t value)
{
    this->entry.value = value;
    return *this;
}

void Symbol::marshallImpl(io::OutputStream& stream) const
{
    stream.write(&entry, sizeof (entry));
}
