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
 * File:   StringTable.cpp
 * Author: Javier Marrero
 * 
 * Created on April 11, 2022, 8:29 PM
 */

#include <amanda-vm/Binutils/StringTable.h>
#include <amanda-vm/ADT/Collections.h>

using namespace amanda;
using namespace amanda::binutils;

StringTable::StringTable(const core::String& name)
:
Section(name),
lastIndex(0)
{
    // Reserve enough space for the first 5 strings.
    reserve(5);

    // Set some reserved values.
    setAttributes(Attr_Alloc | Attr_Read);
    setType(Type_StringTable);

    // Add the first entry that is reserved
    addString("");
}

vm::vm_qword_t StringTable::addString(const core::String& str)
{
    // Store the result for later use
    vm::vm_qword_t result = lastIndex;

    indexes.push_back(lastIndex);
    strings.push_back(str);

    // Update the last index count.
    lastIndex += str.length() + 2;

    return result;
}

void StringTable::constructBinaryData()
{
    for (std::vector<core::String>::const_iterator it = strings.begin(),
            end = strings.end(); it != end; ++it)
    {
        const core::String& str = *it;
        Serializable::write(str.toCharArray(), VM_BYTE_SIZE, str.length() + 1);

        header->size += (str.length() + 1);
    }
    setSize(header->size);
}

StringTable::TablePair StringTable::get(const unsigned position) const
{
    return std::make_pair(indexes.at(position), strings.at(position));
}

vm::vm_qword_t StringTable::getIndex(const core::String& str) const
{
    return indexes.at(adt::getPosition(strings, str));
}

const core::String& StringTable::getString(vm::vm_qword_t index) const
{
    return strings.at(adt::getPosition(indexes, index));
}

void StringTable::reserve(unsigned amount)
{
    indexes.reserve(amount);
    strings.reserve(amount);
}

