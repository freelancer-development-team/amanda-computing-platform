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
 * File:   SectionReader.h
 * Author: Javier Marrero
 *
 * Created on June 17, 2022, 10:51 AM
 */

#ifndef SECTIONREADER_H
#define SECTIONREADER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/ConsistentInputStream.h>
#include <amanda-vm/Binutils/Section.h>

namespace amanda
{
namespace binutils
{

class Module;

class SectionReader : public core::Object
{
    AMANDA_OBJECT(SectionReader, core::Object)
public:

    SectionReader(const io::ConsistentInputStream& reader, Section::SectionHeader& header,
                  const core::String& name);

    Section*    read();
    void        setOwningModule(const Module* module);

private:

    core::StrongReference<const Module> owner;
    const io::ConsistentInputStream&    reader;
    core::WeakReference<Section>        section;
    Section::SectionHeader&             sectionHeader;

} ;

}
}

#endif /* SECTIONREADER_H */

