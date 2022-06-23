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
 * File:   ModuleLoader.cpp
 * Author: Javier Marrero
 *
 * Created on May 18, 2022, 9:43 PM
 */

#include <amanda-vm/Runtime/ModuleLoader.h>
#include <amanda-vm/Binutils/Section.h>
#include <amanda-vm/NIO/IOException.h>
#include <amanda-vm/Runtime/OutOfMemoryError.h>

// C++
#include <cerrno>

using namespace amanda;
using namespace amanda::vm;

logging::Logger& ModuleLoader::LOGGER = logging::Logger::getLogger("amanda.vm.ModuleLoader")->getReference();

ModuleLoader::ModuleLoader(MemoryAllocator& allocator)
:
allocator(allocator)
{
}

ModuleLoader::~ModuleLoader()
{
    // Release a reference to every module.
    for (ModuleMap::const_iterator it = modules.begin(),
         end = modules.end(); it != end; ++it)
    {
        assert(it->second != NULL && "Null pointer exception");
        it->second->release();
    }
}

ExecutableModule* ModuleLoader::load(const core::String& identifier, io::InputStream* stream)
{
    assert(stream != NULL && "Null pointer exception");

    ExecutableModule* result = new ExecutableModule(identifier);
    AMANDA_SYNCHRONIZED(lock);
    {
        // Create a local executable header
        ExecutableModule::ExecutableHeader header;
        std::memset(&header, 0, sizeof (header));

        // Reset the stream
        stream->reset();

        // Read the program header
        int phr_result = io::InputStream::NO_ERROR;
        stream->read(header.m_magic, VM_BYTE_SIZE, 4);
        stream->read(&header.m_entry, VM_QWORD_SIZE);
        stream->read(&header.m_stab_offset, VM_QWORD_SIZE);
        stream->read(&header.m_sh_entries, VM_WORD_SIZE);
        stream->read(&header.m_sh_offset, VM_QWORD_SIZE);
        stream->read(&header.m_version, VM_QWORD_SIZE);

        if (phr_result != io::InputStream::NO_ERROR)
        {
            LOGGER.error("read error while reading header of module <%s> (%s)",
                         identifier.toCharArray(), std::strerror(errno));
            throw nio::IOException(std::strerror(errno));
        }
        else
        {
            //TODO: Check for valid magic number

            // Now read and create the sections in memory
            LOGGER.trace("read program header for module <%s>:\n"
                         "  - magic number    : 0x%X%X%X%X\n"
                         "  - entry address   : 0x%.16llx\n"
                         "  - section table   : 0x%.16llx\n"
                         "  - section count   : 0x%.8x\n"
                         "  - stab offset     : 0x%.16llx\n"
                         "  - version number  : 0x%.16llx\n"
                         "         -- end of header data --",
                         identifier.toCharArray(),
                         header.m_magic[0], header.m_magic[1], header.m_magic[2], header.m_magic[3],
                         header.m_entry,
                         header.m_stab_offset,
                         header.m_sh_entries,
                         header.m_sh_offset,
                         header.m_version);
            // Copy the section
            std::memcpy(&result->header, &header, sizeof (header));

            // Now read the sections
            stream->seek(header.m_sh_offset);
            for (unsigned i = 0; i < header.m_sh_entries; ++i)
            {
                // Declare a section header and fill the data
                binutils::Section::SectionHeader sectionHeader = {0};
                stream->read(&sectionHeader, sizeof (sectionHeader), 1);

                // Buffer for the section name
                char sectionName[512] = {0};
                stream->pushOffset();
                {
                    stream->seek(sectionHeader.name + header.m_stab_offset);

                    unsigned j = 0;
                    char c = 0;
                    do
                    {
                        stream->read(&c, sizeof (char), 1);
                        sectionName[j++] = c;
                    }
                    while (c != '\0');
                }
                stream->popOffset();

                // Load the sections into memory from its respective layout
                // and add the descriptor to the executable module object
                if (sectionHeader.size > 0)
                {
                    void* data = std::calloc(sectionHeader.size, VM_BYTE_SIZE);
                    if (data == NULL)
                    {
                        throw OutOfMemoryError();
                    }
                    sectionHeader.address = reinterpret_cast<vm::vm_qword_t> (data);

                    // Copy the contents of the section to the allocated area
                    stream->pushOffset();
                    {
                        stream->seek(sectionHeader.offset);
                        if (stream->read(data, VM_BYTE_SIZE, sectionHeader.size) != io::InputStream::NO_ERROR)
                        {
                            throw nio::IOException(core::String::makeFormattedString("error reading module <%s> (%s)",
                                                                                     identifier.toCharArray(),
                                                                                     std::strerror(errno)));
                        }
                    }
                    stream->popOffset();
                }

                result->addSection(sectionName, sectionHeader);

                LOGGER.trace("section: <%s> (%s)\n"
                             "  - section size      : 0x%llx\n"
                             "  - section offset    : 0x%llx\n"
                             "  - section address   : 0x%llx\n"
                             "      -- end of section data --",
                             sectionName,
                             binutils::Section::sectionTypeToString(sectionHeader.type).toCharArray(),
                             sectionHeader.size,
                             sectionHeader.offset,
                             sectionHeader.address);
            }

            // Link external symbols

            // We've linked symbols, now produce a log output with every symbol
            // just for us to know
            {
                core::String symbols = core::String::makeFormattedString("last loaded module ('%s') available symbols are (%llu results):\n",
                                                                         result->name.toCharArray(),
                                                                         result->getSymbolCount());
                for (size_t index = 0, endIndex = result->getSymbolCount(); index < endIndex; ++index)
                {
                    const binutils::Symbol::SymbolTableEntry* sy = result->findSymbol(index);
                    core::String tableEntry = core::String::makeFormattedString("\tNAME: %-50s | INDEX: 0x%-16llx | TYPE: %-10s\n",
                                                                                result->findSymbolName(sy->name).toCharArray(),
                                                                                index,
                                                                                binutils::Symbol::getTypeStringFromValue(sy->type).toCharArray());
                    symbols.append(tableEntry);
                }
                LOGGER.debug(symbols);
            }
        }

        // Add to the module map & grab a reference
        result->grab();
        modules.insert(std::make_pair(identifier, result));
    }
    AMANDA_DESYNCHRONIZED(lock);
    return result;
}


