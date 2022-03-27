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
 * File:   StringTable.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 10:26 PM
 */

#ifndef STRINGTABLE_H
#define STRINGTABLE_H

#include <amanda-vm/Binutils/VirtualMachineSpecs.h>
#include <amanda-vm/Binutils/Serializable.h>
#include <amanda-vm/TypeSystem.h>

#include <vector>

namespace amanda
{
namespace binutils
{
namespace ld
{

/**
 * A string table is an associative container which associates integer indexes
 * to string references. Strings are kept in natural order, that is, the same
 * insertion order.
 */
class StringTable : public Serializable
{
    AMANDA_OBJECT(StringTable, Serializable)
    
public:
    
    StringTable();
    virtual ~StringTable();

    void            add(const core::String& str);
    vm::vm_qword_t  count() const;

private:

    std::vector<core::String>   strings;
    
} ;

}
}
}

#endif /* STRINGTABLE_H */

