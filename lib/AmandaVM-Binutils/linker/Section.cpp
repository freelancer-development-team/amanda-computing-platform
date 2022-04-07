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
 * Created on March 24, 2022, 6:43 PM
 */

#include <amanda-vm/Binutils/Linker/Section.h>

using namespace amanda;
using namespace amanda::binutils::ld;

unsigned Section::capabilitiesFromString(const core::String& attributes)
{
    unsigned result = 0;
    if (attributes.contains('r', false))
    {
        result |= Section::READ;
    }
    if (attributes.contains('w', false))
    {
        result |= Section::WRITE;
    }
    if (attributes.contains('x', false))
    {
        result |= Section::EXECUTE;
    }
    return result;
}

core::String Section::stringFromCapabilities(const unsigned capabilities)
{
    core::String result("");
    if (capabilities & Section::READ)
        result += "r";
    if (capabilities & Section::WRITE)
        result += "w";
    if (capabilities & Section::EXECUTE)
        result += "x";
    return result;
}

Section::Section(const core::String& name)
:
capabilities(READ | WRITE | EXECUTE),
sectionName(name)
{
    // There are sections with default capabilities, such as code & data sections
    if (name == ".code")
    {
        capabilities = READ | EXECUTE;
    }
    if (name == ".data")
    {
        capabilities = READ | WRITE;
    }
    if (name == ".strings-pool")
    {
        capabilities = READ;
    }
    if (name == ".symbol-table")
    {
        capabilities = READ;
    }
}

Section::~Section()
{
    for (std::map<core::String, Symbol*>::iterator it = symbols.begin(), end = symbols.end();
         it != end; ++it)
    {
        it->second->release();
    }
}

void Section::addSymbol(Symbol* symbol)
{
    assert(symbol != NULL && "Null pointer exception.");
    symbol->grab();

    symbols.insert(std::make_pair(symbol->getName(), symbol));
}

unsigned Section::getCapabilities() const
{
    return capabilities;
}

const core::String& Section::getSectionName() const
{
    return sectionName;
}

bool Section::hasCapability(unsigned cap) const
{
    return capabilities & cap;
}

void Section::marshall(io::OutputStream& stream)
{
    std::map<core::String, Symbol*>::iterator it, end;
    for (it = symbols.begin(), end = symbols.end(); it != end; ++it)
    {
        assert(it->second != NULL && "Null pointer exception!");
        
        it->second->marshall(stream);
    }
}

Section& Section::merge(Section* section)
{
    // Invariant pre-conditions
    assert(section != NULL && "Null pointer passed when section was expected.");

    // If we are merging with ourselves, don't do anything.
    if (section != this)
    {
        // Merge whatever data is in the merged section.
        for (std::map<core::String, Symbol*>::iterator it = section->symbols.begin(),
                end = section->symbols.end(); it != end; ++it)
        {
            addSymbol(it->second);
        }

        // Delete the merged section and assign the pointer to this.
        delete section;
        section = this;
    }

    // Return a reference to this object.
    return *this;
}

void Section::setCapabilities(unsigned newCaps)
{
    capabilities = newCaps;
}




