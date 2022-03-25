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
 * File:   Section.h
 * Author: Javier Marrero
 *
 * Created on March 24, 2022, 6:43 PM
 */

#ifndef SECTION_H
#define SECTION_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Serializable.h>

#include <map>

namespace amanda
{
namespace binutils
{
namespace ld
{

/**
 * A section represents a place in the object file that is manipulated as a
 * single entity. It contains a base address and the rest of addresses within
 * that section may be calculated via the section address + offset, where offset
 * is an unsigned integer.
 *
 * @author J. Marrero
 */
class Section : public Serializable
{

    AMANDA_OBJECT(Section, Serializable)
public:

    struct SectionOrderer
    {

        bool operator() (const core::String& str1, const core::String& str2) const
        {
            return str1.compare(str2) < 0;
        }
    } ;

    Section(const core::String& name);
    virtual ~Section();

    const core::String& getSectionName() const;

protected:

    core::String sectionName;
} ;

/*
 * Tables of sections.
 */
typedef std::map<core::String, Section*, Section::SectionOrderer> SectionTable;

}
}
}

#endif /* SECTION_H */

