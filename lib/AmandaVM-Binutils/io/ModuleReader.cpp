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
 * File:   ModuleReader.cpp
 * Author: Javier Marrero
 * 
 * Created on April 17, 2022, 2:36 PM
 */

#include <amanda-vm/Binutils/ModuleReader.h>
#include <amanda-vm/Binutils/InvalidFileFormatException.h>
#include <amanda-vm/Binutils/vm-types.h>

// C/C++
#include <cstring>

using namespace amanda;
using namespace amanda::binutils;

const logging::Logger& ModuleReader::LOGGER = logging::Logger::getLogger("amanda.binutils.ModuleReader")->getConstReference();

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
    // Synchronize
    AMANDA_SYNCHRONIZED(lock);

    Module* result = NULL;
    if (Module::checkMagicNumber(*this) == true)
    {
        result = new Module(name);

        // Read past the magic number
        seek(4);

        // Read the program header
        super::read(&result->entryPointAddress, VM_QWORD_SIZE);
        super::read(&result->stringTableOffset, VM_QWORD_SIZE);
        super::read(&result->sectionHeaderEntries, VM_WORD_SIZE);
        super::read(&result->sectionHeaderOffset, VM_QWORD_SIZE);
        super::read(&result->version, sizeof (Module::version_triplet));

        // Read the compiler message
        vm::vm_byte_t message[89] = {0};
        super::read(message, VM_BYTE_SIZE, 88);
        result->compilerName = (const char*) message;

        // Read the sections table & other section information
        // not concerning section objects.
        LOGGER.trace("module has %d sections. The section table is at offset 0x%llx. String table at 0x%llx.",
                     result->sectionHeaderEntries, result->sectionHeaderOffset,
                     result->stringTableOffset);

        super::seek(result->sectionHeaderOffset);
        for (unsigned i = 0; i < result->sectionHeaderEntries; i++)
        {
            // As we read every section header table we shall create the
            // section
            Section::SectionHeader header;
            std::memset(&header, 0, sizeof (Section::SectionHeader));

            super::read(&header, sizeof (Section::SectionHeader));

            // Read the section name
            char    sectionName[512] = {0};
            size_t  sectionNameOffset = result->stringTableOffset + header.name;

            mark();
            {
                seek(sectionNameOffset);
                char c = '\0';
                unsigned i = 0;

                do
                {
                    super::read(&c, sizeof(char));
                    sectionName[i++] = c;
                } while (c != '\0');
            }
            seek(retrieve());

            // Trace
            LOGGER.trace("section with name <%s> and size 0x%llx of type <%s>",
                         sectionName,
                         header.size,
                         Section::sectionTypeToString(header.type).toCharArray());
        }
    }
    else
    {
        throw InvalidFileFormatException("invalid magic number.", name);
    }

    // Desynchronize and return
    AMANDA_DESYNCHRONIZED(lock);
    return result;
}

const core::String& ModuleReader::getName() const
{
    return name;
}

void ModuleReader::mark() const
{
    AMANDA_SYNCHRONIZED(lock);
    {
        uint64_t position = super::tell();
        LOGGER.trace("push: 0x%llx", position);

        records.push(position);
    }
    AMANDA_DESYNCHRONIZED(lock);
}

uint64_t ModuleReader::retrieve() const
{
    uint64_t result = 0;
    AMANDA_SYNCHRONIZED(lock);
    {
        result = records.top();
        LOGGER.trace("pop: 0x%llx", result);

        

        // Pop the data
        records.pop();
    }
    AMANDA_DESYNCHRONIZED(lock);
    return result;
}


