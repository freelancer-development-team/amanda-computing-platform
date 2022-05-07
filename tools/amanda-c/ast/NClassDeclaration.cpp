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
 * File:   NClassDeclaration.cpp
 * Author: Javier Marrero
 * 
 * Created on March 22, 2022, 3:19 PM
 */

#include <amanda-c/ast/NClassDeclaration.h>
#include <amanda-c/ast/NClassFieldDeclaration.h>

using namespace amanda;
using namespace amanda::compiler::ast;

NClassDeclaration::AccessModifier NClassDeclaration::createAccessModifierFromString(const core::String& str)
{
    AccessModifier modifier = AM_Private;
    if (str.compare("public", false) == 0)
    {
        modifier = AM_Public;
    }
    else if (str.compare("protected", false) == 0)
    {
        modifier = AM_Protected;
    }
    else if (str.compare("private", false) == 0)
    {
        modifier = AM_Private;
    }
    return modifier;
}

NClassDeclaration::NClassDeclaration(const core::String& className)
:
className(className)
{
}

NClassDeclaration::~NClassDeclaration()
{
}

void NClassDeclaration::addClassSections(const ClassSectionList& list)
{
    for (ClassSectionList::const_iterator it = list.begin(); it != list.end(); ++it)
    {
        sections.push_back(*it);
    }
}

NClassDeclaration::AccessModifier NClassDeclaration::getAccessModifier() const
{
    return accessModifier;
}

unsigned NClassDeclaration::getDeclaredSectionsCount() const
{
    return sections.size();
}

unsigned NClassDeclaration::getTotalFieldCount() const
{
    unsigned count = 0;
    for (ClassSectionList::const_iterator it = sections.begin(); it != sections.end(); ++it)
    {
        ClassBodySection* section = *it;
        assert(section != NULL && "Null pointer exception");

        count += section->getDeclaredFieldsCount();
    }
    return count;
}

unsigned NClassDeclaration::getTotalMethodCount() const
{
    unsigned count = 0;
    for (ClassSectionList::const_iterator it = sections.begin(); it != sections.end(); ++it)
    {
        ClassBodySection* section = *it;
        assert(section != NULL && "Null pointer exception");

        count += section->getDeclaredMethodsCount();
    }
    return count;
}

void NClassDeclaration::setAccessModifier(const AccessModifier modifier)
{
    accessModifier = modifier;
}

core::String NClassDeclaration::toString() const
{
    unsigned fields = getTotalFieldCount();
    unsigned methods = getTotalMethodCount();

    core::String buffer(buildHeaderString());
    buffer.append("\nClass name: '").
            append(className).
            appendWithFormat("'. %u sections declared. %u fields. %u methods.",
                             getDeclaredSectionsCount(),
                             fields,
                             methods);

    return buffer;
}

/* ================= INTERNAL CLASS ========================================= */


NClassDeclaration::ClassBodySection::ClassBodySection(AccessModifier modifier)
:
accessModifier(modifier)
{
}

NClassDeclaration::ClassBodySection::~ClassBodySection()
{
}

NClassDeclaration::AccessModifier NClassDeclaration::ClassBodySection::getAccessModifier() const
{
    return accessModifier;
}

unsigned NClassDeclaration::ClassBodySection::getDeclaredFieldsCount() const
{
    unsigned count = 0;
    for (StatementList::const_iterator it = statements.begin();
         it != statements.end(); ++it)
    {
        const NStatement* statement = *it;
        assert(statement != NULL && "Null pointer exception");

        if (statement->is<NClassFieldDeclaration>()) count++;
    }
    return count;
}

unsigned NClassDeclaration::ClassBodySection::getDeclaredMethodsCount() const
{
    unsigned count = 0;
    for (StatementList::const_iterator it = statements.begin();
         it != statements.end(); ++it)
    {
        const NStatement* statement = *it;
        assert(statement != NULL && "Null pointer exception");

        ///TODO: Implement
    }
    return count;
}

void NClassDeclaration::ClassBodySection::setAccessModifier(AccessModifier modifier)
{
    accessModifier = modifier;
}

void NClassDeclaration::ClassBodySection::setStatements(const StatementList& statements)
{
    for (StatementList::const_iterator it = statements.begin(); it != statements.end(); ++it)
    {
        addStatement(*it);
    }
}

core::String NClassDeclaration::ClassBodySection::toString() const
{
    core::String buffer(buildHeaderString());
    buffer.appendWithFormat("Declared fields: %u.", getDeclaredFieldsCount());

    return buffer;
}

