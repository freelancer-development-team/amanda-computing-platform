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
 * File:   Section.cpp
 * Author: Javier Marrero
 * 
 * Created on April 9, 2022, 7:13 PM
 */

#include <amanda-vm/Binutils/Section.h>
#include <amanda-vm/Binutils/StringTable.h>
#include <amanda-vm/Binutils/SymbolTable.h>
#include <amanda-vm/Binutils/Function.h>
#include <amanda-vm/Binutils/Logging.h>
#include <amanda-vm/Binutils/vm-types.h>
#include <amanda-vm/IO/MemoryOutputStream.h>
#include <amanda-vm/IO/ConsistentOutputStream.h>

// C
#include <stdlib.h>


using namespace amanda;
using namespace amanda::binutils;

Section* Section::makeCodeSection()
{
    Section* section = new Section(CODE_SECTION_NAME);
    section->header->flags = Attr_Alloc | Attr_Exec | Attr_Read;

    return section;
}

Section* Section::makeDataSection()
{
    Section* section = new Section(DATA_SECTION_NAME);
    section->header->flags = Attr_Alloc | Attr_Read | Attr_Write;

    return section;
}

Section* Section::makeStringTableSection()
{
    return new StringTable(STRINGS_SECTION_NAME);
}

Section* Section::makeSectionHeaderStringTableSection()
{
    StringTable* shstrtab = new StringTable(SECTION_HEADERS_STRINGS_NAME);
    shstrtab->setNameIndex(shstrtab->addString(SECTION_HEADERS_STRINGS_NAME));

    // Return the section header string table
    return shstrtab;
}

Section* Section::makeSymbolTableSection()
{
    return new SymbolTable(SYMBOL_TABLE_SECTION_NAME);
}

Section::Section(const core::String& name)
:
header(new SectionHeader()),
name(name)
{
    memset(header, 0, sizeof(*header));
}

Section::~Section()
{
    for (unsigned i = 0; i < symbols.size(); ++i)
    {
        symbols.at(i)->release();
    }
    delete header;
}

void Section::addSymbol(const Symbol* symbol)
{
    assert(symbol != NULL && "Null pointer exception.");

    if (symbol->is<Function>() && !canExecute())
    {
        getPackageLogger().warn("added executable symbol to a non executable section. (symbol '%s' to section '%s')",
                                symbol->getName().toCharArray(), getName().toCharArray());
    }

    // Grab a reference to the symbol.
    symbol->grab();
    symbols.push_back(eliminateConstness(symbol));

    // Update the size.
    // setSize(calculateSize());
}

size_t Section::calculateSize() const
{
    size_t result = 0;
    for (std::vector<Symbol*>::const_iterator it = symbols.begin(),
            end = symbols.end(); it != end; ++it)
    {
        result += (*it)->getSize();
    }
    return result;
}

bool Section::canExecute() const
{
    return this->header->flags & Attr_Exec;
}

bool Section::canWrite() const
{
    return header->flags & Attr_Write;
}

bool Section::equals(const core::Object* object)
{
    bool result = false;
    if (object->is<Section>())
    {
        Section* rhs = (Section*) object;
        result = (rhs->getName() == getName());
    }
    return result;
}

const core::String& Section::getName() const
{
    return name;
}

Section::SectionHeader Section::getNullSectionHeader() const
{
    SectionHeader header;
    header.address = 0;
    header.flags = 0;
    header.offset = 0;
    header.type = Type_Null;
    header.size = 0;

    return header;
}

const Section::SectionHeader* Section::getSectionHeader() const
{
    return header;
}

size_t Section::getSize() const
{
    return header->size;
}

void Section::merge(const Section* section)
{
    if (section != NULL && (this != section))
    {
        // Write the binary data but also get any symbol
        // write((eliminateConstness(section))->getBinaryData(), VM_BYTE_SIZE, section->getSize());

        // Transpose the symbols
        for (std::vector<Symbol*>::const_iterator it = section->symbols.begin(),
                end = section->symbols.end(); it != end; ++it)
        {
            const Symbol* symbol = (*it);
            addSymbol(symbol);
        }

        // Release a reference to the object (possibly deleting it)
        section->release();

        // Set the size by calculating
        setSize(calculateSize());
    }
}

void Section::marshallImpl(io::OutputStream& stream) const
{
    Section* self = (Section*) eliminateConstness(this);
    stream.write(self->getBinaryData(), VM_BYTE_SIZE, getSize());
}

void Section::setAttributes(unsigned attributes)
{
    header->flags = attributes;
}

void Section::setNameIndex(const vm::vm_qword_t index)
{
    header->name = (vm::vm_dword_t) index;
}

void Section::setSize(size_t size)
{
    header->size = size;
}

void Section::setType(unsigned type)
{
    header->type = type;
}

bool Section::operator ==(const Section* section) const
{
    return section->getName() == getName();
}
