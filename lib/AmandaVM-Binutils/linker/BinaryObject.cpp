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
 * File:   BinaryObject.cpp
 * Author: Javier Marrero
 * 
 * Created on March 24, 2022, 11:07 PM
 */

#include <amanda-vm/Binutils/Linker/BinaryObject.h>
#include <amanda-vm/ADT/Collections.h>

#include <amanda-vm/Binutils/Linker/SymbolTable.h>

using namespace amanda;
using namespace amanda::binutils::ld;

BinaryObject::BinaryObject(io::File* file, const core::String& moduleName)
:
file(file),
header(new ImageHeader()),
name(moduleName),
stringTable(new StringTable())
{
    assert(!this->file.isNull() && "Bad pointer");

    // Initialize the program header to the default values.
    header->setHeaderSize(ImageHeader::IMAGE_HEADER_SIZEOF);

    // Initialize the symbol table section
    addSection(new SymbolTable());
}

BinaryObject::~BinaryObject()
{
    for (SectionTable::const_iterator it = sections.begin(), end = sections.end();
         it != end; ++it)
    {
        it->second->release();
    }
}

void BinaryObject::addSection(Section* section)
{
    assert(section != NULL && "Bad pointer");
    if (adt::containsKey(sections, section->getSectionName()))
    {
        Section* merger = sections.find(section->getSectionName())->second;
        assert(merger != NULL && "Null pointer exception.");

        merger->merge(section);
    }
    else
    {
        // Grab a reference to the section!!
        section->grab();

        sections.insert(std::make_pair(section->getSectionName(), section));
        stringTable->add(section->getSectionName());
    }
}

unsigned BinaryObject::countSections()
{
    return sections.size();
}

const core::String& BinaryObject::getName() const
{
    return name;
}

const Section* BinaryObject::getSection(const core::String& name) const
{
    const Section* result = NULL;

    SectionTable::const_iterator it = sections.find(name);
    if (it != sections.end())
    {
        result = it->second;
    }

    return result;
}

const SectionTable& BinaryObject::getSections() const
{
    return sections;
}

void BinaryObject::marshall(io::OutputStream& stream)
{
    /* First task:
     *
     *  - Gather, validate & update necessary data to perform marshalling!
     */
    {
        // Header
        header->setSectionNamesIndex(countSections() + 1);
    }

    // Write the header to the output stream
    header->marshall(stream);

    // Program header table

    // Write all the sections
    for (SectionTable::iterator it = sections.begin(), end = sections.end();
         it != end; ++it)
    {
        Section* section = it->second;
        assert(section != NULL && "Null pointer exception.");

        section->marshall(stream);
    }

    // Write the string table
    stringTable->marshall(stream);

    // Write now the section table.
    {
        vm::vm_qword_t secix = 0;

        /* The section table contains section pointers, but the pointer holds
         * brute data and no information as itself. We must decode each entry
         * and write the appropriate content to the stream.
         * Entries goes like this:
         *
         *  - section index (8B)
         *  - name index (in the string table) (8B)
         *  - capabilities (4B)
         *  - address (8B)
         *  - size (8B)
         *  
         */
        for (SectionTable::iterator it = sections.begin(), end = sections.end();
             it != end; ++it, ++secix)
        {
            Section* section = it->second;
            assert(section != NULL && "Null pointer exception");

            vm::vm_qword_t strtix = stringTable->getIndex(section->getSectionName());
            vm::vm_dword_t caps = section->getCapabilities();

            stream.write(&secix, sizeof(secix));
            stream.write(&strtix, sizeof(vm::vm_qword_t));
            stream.write(&caps, sizeof(vm::vm_dword_t));
            ///TODO: Finish this
        }
    }
}




