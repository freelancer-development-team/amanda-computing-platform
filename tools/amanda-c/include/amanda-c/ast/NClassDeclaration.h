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
 * File:   NClassDeclaration.h
 * Author: Javier Marrero
 *
 * Created on March 22, 2022, 3:19 PM
 */

#ifndef NCLASSDECLARATION_H
#define NCLASSDECLARATION_H

#include <amanda-c/ast/NDeclaration.h>
#include <amanda-c/ast/NBlock.h>

// C++ STL
#include <vector>

namespace amanda
{
namespace compiler
{
namespace ast
{

class NClassDeclaration : public NDeclaration
{
    AMANDA_OBJECT(NClassDeclaration, NDeclaration)

public:

    /**
     * This enumeration describes the tree possible access types. They are shared
     * amongst methods and classes, but their semantics differ.
     * <p>
     * If a method is declared public, then it is visible to outside users of the
     * class. If a method is declared protected, then it is only visible to
     * descendants of that class; and if declared private, then it is only
     * visible within the same class that declared the method.
     * <p>
     * If a class is declared public, it is visible across all the users of the
     * name space via explicit qualification or import. If protected, it is
     * visible only by members of the same name-space. If private, it is only
     * visible in the declaring translation unit.
     *
     * @author J. Marrero
     */
    typedef enum AccessModifier
    {
        AM_Public,
        AM_Protected,
        AM_Private
    } AccessModifier;

    /**
     * This internal class represents a class body section. The section can be
     * public, private or protected.
     * 
     */
    class ClassBodySection : public NBlock
    {
        AMANDA_OBJECT(ClassBodySection, NBlock)
        
    public:

        ClassBodySection(AccessModifier modifier = AM_Protected);
        virtual ~ClassBodySection();

        AccessModifier  getAccessModifier() const;
        unsigned        getDeclaredFieldsCount() const;
        unsigned        getDeclaredMethodsCount() const;
        void            setAccessModifier(AccessModifier modifier);
        void            setStatements(const StatementList& statements);
        
        virtual core::String toString() const;

    private:

        AccessModifier                  accessModifier;
    };

    /**
     * This is a representation of a list of class sections.
     */
    typedef std::vector<ClassBodySection*> ClassSectionList;

    static AccessModifier createAccessModifierFromString(const core::String& str);

    NClassDeclaration(const core::String& className);
    virtual ~NClassDeclaration();

    void                    addClassSections(const ClassSectionList& list);
    AccessModifier          getAccessModifier() const;
    unsigned                getDeclaredSectionsCount() const;
    unsigned                getTotalFieldCount() const;
    unsigned                getTotalMethodCount() const;
    void                    setAccessModifier(const AccessModifier modifier);
    virtual core::String    toString() const;

protected:

    AccessModifier      accessModifier;     /// The access modifier of the class (how much visible it is within the name-space)
    core::String        className;          /// The name of the class
    ClassSectionList    sections;           /// Class sections
    
} ;

}
}
}

#endif /* NCLASSDECLARATION_H */

