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
 * File:   Module.cpp
 * Author: Javier Marrero
 * 
 * Created on April 9, 2022, 3:55 PM
 */

#include <amanda-vm/Binutils/Module.h>
#include <amanda-vm/Binutils/SymbolTable.h>
#include <amanda-vm/Binutils/StringTable.h>
#include <amanda-vm/Binutils/Logging.h>
#include <amanda-vm/ADT/Collections.h>
#include <amanda-vm-c/sdk-version.h>

// C++
#include <cstring>

using namespace amanda;
using namespace amanda::binutils;

const vm::vm_byte_t Module::MAGIC_NUMBER[4] = {0x7F, '@', 'A', 'X'};

bool Module::checkMagicNumber(const io::InputStream& stream)
{
    vm::vm_byte_t tmp[5] = {0};
    uint64_t offset = stream.tell();

    stream.reset();
    stream.read(tmp, VM_BYTE_SIZE, 4);

    stream.seek(offset);
    return memcmp(tmp, MAGIC_NUMBER, 4) == 0;
}

core::String Module::decodeVersionFromTriplet(const version_triplet& triplet)
{
    core::String result(triplet.major);
    result.append('.').append(core::String(triplet.minor)).append('.').append(core::String(triplet.revision));

    return result;
}

Module::version_triplet Module::encodeVersionFromString(const core::String& version)
{
    version_triplet triplet;
    unsigned index = 0;

    std::vector<core::String> components = version.split(".");
    for (std::vector<core::String>::const_iterator it = components.begin(),
         end = components.end(); it != end; ++it)
    {
        unsigned number = (unsigned) atoi((*it).toCharArray());

        switch (index)
        {
            case 0:
                triplet.major = number;
                break;
            case 1:
                triplet.minor = number;
                break;
            case 2:
                triplet.revision = number;
                break;
        }
        index++;
    }

    return triplet;
}

Module::Module(const core::String& name)
:
compilerName("\r\namanda-binutils assembler version(" SDK_FULLVERSION_STRING ") built on '" __TIMESTAMP__ "'."),
name(name)
{
    // Initialize the rest of the fields
    entryPointAddress = 0;
    programHeaderOffset = 0;
    sectionHeaderEntries = 0;
    sectionHeaderOffset = 0;
    memset(&version, 0, sizeof (version_triplet));

    version = encodeVersionFromString(SDK_FULLVERSION_STRING);

    // Rest of the constructor logic
    sections.reserve(7);
    addSection(Section::makeSectionHeaderStringTableSection());
    addSection(Section::makeStringTableSection());
    addSection(Section::makeSymbolTableSection());
    addSection(Section::makeCodeSection());
    // addSection(Section::makeDataSection());
}

Module::~Module()
{
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        (*it)->release();
    }
}

void Module::addSymbol(Symbol& symbol, Section& section)
{
    // Grab a reference to the symbol table of the module & add the symbol.
    SymbolTable* symtab = &(getSection(SYMBOL_TABLE_SECTION_NAME)->cast<SymbolTable>());
    symtab->addSymbol(&symbol);

    // Write the symbol to the section
    StringTable* strtab = &(getSection(STRINGS_SECTION_NAME)->cast<StringTable>());
    vm::vm_qword_t position = strtab->addString(symbol.getName());
    symbol.setStringTableEntry((vm::vm_dword_t) position);

    // Add the symbol to the section
    section.addSymbol(&symbol);
}

void Module::addSection(Section* section)
{
    assert(section != NULL && "null pointer exception");
    // Check first if the vector contains a section with that name,
    // in order to know if we must merge
    bool contains = false;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end && !contains; ++it)
    {
        if ((*it)->getName() == section->getName())
        {
            contains = true;
        }
    }

    if (!contains)
    {
        StringTable* shstrtab = (StringTable*) getSection(SECTION_HEADERS_STRINGS_NAME);
        if (shstrtab != NULL)
        {
            // This means we are inserting a section just after creation of the
            // section table header string table, just as it should be.
            vm::vm_qword_t position = shstrtab->addString(section->getName());

            // Mark the position
            section->setNameIndex(position);
        }

        // Grab a reference to the section object & add it to the vector.
        section->grab();
        sections.push_back(section);
    }
    else
    {
        // Merge the section & delete the object.
        getSection(section->getName())->merge(section);
    }

    // Update the number of entries
    sectionHeaderEntries = sections.size();
}

size_t Module::calculateSectionsSize() const
{
    size_t result = 0;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        result += (*it)->getSize();
    }
    return result;
}

vm::vm_word_t Module::countSections() const
{
    return sectionHeaderEntries;
}

const Module::version_triplet& Module::getBinaryFormatVersion() const
{
    return version;
}

const core::String& Module::getCompilerName() const
{
    return compilerName;
}

vm::vm_qword_t Module::getEntryPointAddress() const
{
    return entryPointAddress;
}

Section* Module::getSection(const core::String& name) const
{
    Section* result = NULL;

    bool found = false;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end && !found; ++it)
    {
        if ((*it)->getName() == name)
        {
            found = true;
            result = *it;
        }
    }
    return result;
}

vm::vm_qword_t Module::getSectionHeaderOffset() const
{
    return sectionHeaderOffset;
}

bool Module::hasEntryPoint() const
{
    return entryPointAddress != 0;
}

bool Module::hasProgramHeader() const
{
    return programHeaderOffset != 0;
}

void Module::marshallImpl(io::OutputStream& stream) const
{
    /*
     * BINARY LAYOUT OF THE OBJECT/EXECUTABLE/LIBRARY FILE:
     *
     * + Magic number (4B)
     * + Entry point address (8B)
     * + Program header offset (8B)
     * + Section header table entries (2B)
     * + Section header offset (8B)
     * + Binary object version (8B) [As directed by the standard, not the compiler]
     * + Compiler message (90B)
     *
     * + Program header
     * + Sections
     * + Section header table
     */

    // Create the compiler message.
    vm::vm_byte_t message[88] = {0};
    memcpy(message, compilerName.toCharArray(), compilerName.length() < 88 ? compilerName.length() : 88);

    // Write the magic number.
    stream.write(MAGIC_NUMBER, VM_BYTE_SIZE, 4);
    stream.write(&entryPointAddress, VM_QWORD_SIZE);
    stream.write(&programHeaderOffset, VM_QWORD_SIZE);
    stream.write(&sectionHeaderEntries, VM_WORD_SIZE);
    stream.write(&sectionHeaderOffset, VM_QWORD_SIZE);
    stream.write(&version, VM_QWORD_SIZE);
    stream.write(message, VM_BYTE_SIZE, 88);
    stream.write("\x0d\0xa");

    stream.write("\nsections\n");   //TODO: COMMENT
    // Write every section.
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        Section* section = *it;
        stream.write(core::String::makeFormattedString("\n-- %s --\n", section->getName().toCharArray()).toCharArray());  //TODO: DEBUG PURPOSES ONLY!!!!!

        stream.write(section->getBinaryData(), VM_BYTE_SIZE, section->getBufferLength());
    }
    stream.write("\nend-sections\n");   //TODO: COMMENT

    // Write the section table
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        const Section::SectionHeader* header = (*it)->getSectionHeader();
        stream.write(header, sizeof (*header));
    }
}

void Module::setBinaryFormatVersion(const core::String& version)
{
    this->version = encodeVersionFromString(version);
}

void Module::setCompilerName(const core::String& name)
{
    this->compilerName = name;
}

