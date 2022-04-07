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
 * File:   BinaryObject.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 11:07 PM
 */

#ifndef BINARYOBJECT_H
#define BINARYOBJECT_H

#include <amanda-vm/Binutils/Serializable.h>
#include <amanda-vm/Binutils/Linker/GlobalOffsetTable.h>
#include <amanda-vm/Binutils/Linker/ImageHeader.h>
#include <amanda-vm/Binutils/Linker/Section.h>
#include <amanda-vm/Binutils/Linker/StringTable.h>

namespace amanda
{
namespace binutils
{
namespace ld
{

/**
 * This class represents objects files that may be loaded and inspected at
 * runtime, and modified, read meta-data and perform other operations in.
 *
 * @author J. Marrero
 */
class BinaryObject : public Serializable
{
    AMANDA_OBJECT(BinaryObject, Serializable)
public:

    BinaryObject(io::File* file, const core::String& moduleName);
    virtual ~BinaryObject();

    void                addSection(Section* section);
    unsigned            countSections();
    const core::String& getName() const;
    const Section*      getSection(const core::String& name) const;
    const SectionTable& getSections() const;
    virtual void        marshall(io::OutputStream& stream);
    
private:

    core::StrongReference<io::File>             file;
    core::StrongReference<GlobalOffsetTable>    globalOffsetTable;
    core::StrongReference<ImageHeader>          header;
    core::String                                name;
    SectionTable                                sections;
    core::StrongReference<StringTable>          stringTable;
    
} ;

}
}
}

#endif /* BINARYOBJECT_H */

