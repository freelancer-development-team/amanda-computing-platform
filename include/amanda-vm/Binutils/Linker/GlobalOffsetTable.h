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
 * File:   GlobalOffsetTable.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 9:18 PM
 */

#ifndef GLOBALOFFSETTABLE_H
#define GLOBALOFFSETTABLE_H

#include <amanda-vm/Binutils/Serializable.h>
#include <amanda-vm/Binutils/VirtualMachineSpecs.h>

#include <set>

namespace amanda
{
namespace binutils
{
namespace ld
{

/**
 * The global offset table is a data structure that handles dynamic symbol
 * resolution.
 */
class GlobalOffsetTable : public Serializable
{

    AMANDA_OBJECT(GlobalOffsetTable, Serializable)
public:

    /**
     * An entry in the Global Offset Table structure.
     */
    class Descriptor
    {
    public:

    private:
        
        vm::vm_address_t  loadedOffset;
        vm::vm_qword_t    symbolNameIndex;
    } ;

    /// A set of descriptor objects (the table itself)
    typedef std::set<Descriptor> DescriptorSet;

protected:

    DescriptorSet descriptors;
} ;

}
}
}

#endif /* GLOBALOFFSETTABLE_H */

