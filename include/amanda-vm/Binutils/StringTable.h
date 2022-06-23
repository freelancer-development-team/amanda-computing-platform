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
 * File:   StringTable.h
 * Author: Javier Marrero
 *
 * Created on April 11, 2022, 8:29 PM
 */

#ifndef STRINGTABLE_H
#define STRINGTABLE_H

#include <amanda-vm/Binutils/Section.h>

// C++ STL
#include <vector>

namespace amanda
{
namespace binutils
{

/**
 * A <code>StringTable</code> is an object representing a table of strings.
 * String tables are mutable only to insertion. No deletions are allowed once
 * a string is placed in the table.
 * 
 */
class StringTable : public Section
{
    AMANDA_OBJECT(StringTable, Section)
public:

    typedef std::pair<const vm::vm_qword_t, const core::String> TablePair;

    StringTable(const core::String& name);

    vm::vm_qword_t      addString(const core::String& str);
    virtual void        constructBinaryData();
    TablePair           get(const unsigned position) const;
    vm::vm_qword_t      getIndex(const core::String& str) const;
    const core::String& getString(vm::vm_qword_t index) const;
    void                reserve(unsigned amount);

protected:

    std::vector<vm::vm_qword_t> indexes;
    std::vector<core::String>   strings;

    virtual size_t      calculateSize() const;

private:

    vm::vm_qword_t lastIndex;
} ;

}
}

#endif /* STRINGTABLE_H */

