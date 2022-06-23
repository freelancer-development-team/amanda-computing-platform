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
 * File:   ExecutableModule.cpp
 * Author: Javier Marrero
 * 
 * Created on June 18, 2022, 8:13 AM
 */

#include <amanda-vm/Runtime/ExecutableModule.h>
#include <amanda-vm/Binutils/Module.h>
#include <amanda-vm/IO/MemoryInputStream.h>
#include <amanda-vm/IO/ConsistentInputStream.h>

#include <cstring>

using namespace amanda;
using namespace amanda::vm;

// Using internals
using binutils::Section;
using binutils::Symbol;

logging::Logger& ExecutableModule::LOGGER = logging::Logger::getLogger("amanda.vm.ExecutableModule")->getReference();

void ExecutableModule::swapEndianness(void* buffer, size_t size)
{
    assert(buffer != NULL && "Null pointer exception.");

    char* data = (char*) buffer;
    for (size_t i = 0, j = (size - 1); i < (size / 2); ++i, --j)
    {
        char temporary = data[j];
        data[j] = data[i];
        data[i] = temporary;
    }
}

ExecutableModule::ExecutableModule(const core::String& name)
:
name(name),
size(0)
{
    std::memset(&header, 0, sizeof (header));   // Zero the header
}

ExecutableModule::~ExecutableModule()
{
    for (std::map<core::String, binutils::Section::SectionHeader>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        std::free((void*) it->second.address);
    }
}

void ExecutableModule::addSection(const core::String name, const binutils::Section::SectionHeader& section)
{
    sections.insert(std::make_pair(name, section));
}

const ExecutableModule::ExecutableHeader& ExecutableModule::getHeader() const
{
    return header;
}

const vm::vm_size_t ExecutableModule::getSize() const
{
    return size;
}

const binutils::Section::SectionHeader& ExecutableModule::findSection(const core::String& name) const
{
    return sections.at(name);
}

const core::String ExecutableModule::findSymbolName(const vm::vm_qword_t offset) const
{
    const char* buffer = (const char*) (findSection(STRINGS_SECTION_NAME).address + offset);
    core::String result(buffer);

    return result;
}

const binutils::Symbol::SymbolTableEntry* ExecutableModule::findSymbol(const core::String& name, int type) const
{
    const Symbol::SymbolTableEntry* result = NULL;
    AMANDA_SYNCHRONIZED(lock);
    {
        for (unsigned i = 0; i < getSymbolCount(); ++i)
        {
            const Symbol::SymbolTableEntry* local = findSymbol(i);
            if (local != NULL)
            {
                if (local->type == type && findSymbolName(local->name) == name)
                {
                    result = local;
                    break;
                }
            }
        }
    }
    AMANDA_DESYNCHRONIZED(lock);
    return result;
}

const binutils::Symbol::SymbolTableEntry* ExecutableModule::findSymbol(const vm::vm_dword_t index) const
{
    vm::vm_address_t address = findSection(SYMBOL_TABLE_SECTION_NAME).address;
    Symbol::SymbolTableEntry* entry = (Symbol::SymbolTableEntry*) (address + (index * sizeof (Symbol::SymbolTableEntry)));

    if (!io::ConsistentInputStream::isBigEndian())
    {
        swapEndianness(entry, sizeof (Symbol::SymbolTableEntry));
    }

    return entry;
}

const vm::vm_size_t ExecutableModule::getSymbolCount() const
{
    return findSection(SYMBOL_TABLE_SECTION_NAME).size / sizeof (Symbol::SymbolTableEntry);
}

