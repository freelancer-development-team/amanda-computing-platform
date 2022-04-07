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
 * File:   StringTable.cpp
 * Author: Javier Marrero
 * 
 * Created on March 24, 2022, 10:26 PM
 */

#include <amanda-vm/Binutils/Linker/StringTable.h>

using namespace amanda;
using namespace amanda::binutils::ld;

StringTable::StringTable()
{
    // Reserve initial space
    strings.reserve(25);
    indexes.reserve(25);

    // The first index in the string table points to an invalid entry with this
    // descriptive message.
    add("!I-N-V-A-L-I-D-E-N-T-R-Y?");
}

StringTable::~StringTable()
{
}

void StringTable::add(const core::String& str)
{
    if (indexes.empty())
    {
        indexes.push_back(0);
    }
    else
    {
        indexes.push_back(indexes.back() + strings.back().length() + 1);
    }

    // Now you can push the string
    strings.push_back(str);
}

vm::vm_qword_t StringTable::count() const
{
    return strings.size();
}

const core::String& StringTable::get(vm::vm_qword_t index) const
{
    core::String& result = amanda::eliminateConstness(strings[0]);

    bool found = false;
    for (unsigned i = 0; i < indexes.size() && !found; ++i)
    {
        if (index == indexes[i])
        {
            found = true;
            result = strings[i];
        }
    }

    return result;
}

vm::vm_qword_t StringTable::getIndex(const core::String& str)
{
    bool found = false;
    vm::vm_qword_t result = 0;
    
    for (unsigned i = 0; i < strings.size() && !found; ++i)
    {
        if (strings[i] == str)
        {
            result = indexes[i];
            found = true;
        }
    }
    
    return result;
}

void StringTable::marshall(io::OutputStream& stream)
{
    for (std::vector<core::String>::iterator it = strings.begin(), end = strings.end();
         it != end; ++it)
    {
        stream.write((*it).toCharArray(), sizeof(sdk_utf8_char_t), (*it).length() + 1);
    }
}
