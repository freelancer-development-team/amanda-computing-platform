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
 * File:   ModuleReader.cpp
 * Author: Javier Marrero
 * 
 * Created on April 17, 2022, 2:36 PM
 */

#include <amanda-vm/Binutils/ModuleReader.h>
#include <amanda-vm/Binutils/InvalidFileFormatException.h>
#include <amanda-vm/Binutils/vm-types.h>

using namespace amanda;
using namespace amanda::binutils;

ModuleReader::ModuleReader(const core::String& name, io::InputStream& stream)
:
io::ConsistentInputStream(stream, io::ConsistentInputStream::BIG_ENDIAN),
name(name)
{
}

ModuleReader::~ModuleReader()
{
}

Module* ModuleReader::read() const
{
    Module* result = NULL;
    if (Module::checkMagicNumber(*this) == true)
    {
        result = new Module(name);

        // Read past the magic number
        seek(4);

        // Read the program header
        super::read(&result->entryPointAddress, VM_QWORD_SIZE);
        super::read(&result->programHeaderOffset, VM_QWORD_SIZE);
        super::read(&result->sectionHeaderEntries, VM_WORD_SIZE);
        super::read(&result->sectionHeaderOffset, VM_QWORD_SIZE);
        super::read(&result->version, sizeof(Module::version_triplet));

        // Read the compiler message
        vm::vm_byte_t message[89] = {0};
        super::read(message, VM_BYTE_SIZE, 88);
        result->compilerName = (const char*) message;

        
    }
    else
    {
        throw InvalidFileFormatException("invalid magic number.", name);
    }
    return result;
}

const core::String& ModuleReader::getName() const
{
    return name;
}

