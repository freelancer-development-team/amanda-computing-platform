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
 * File:   SymbolTable.h
 * Author: Javier Marrero
 *
 * Created on April 11, 2022, 11:01 PM
 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <amanda-vm/Binutils/Section.h>
#include <amanda-vm/Binutils/Symbol.h>

// C++ STL
#include <map>
#include <vector>

namespace amanda
{
namespace binutils
{

/**
 * The symbol table is the section that holds all the symbol & relocation data.
 */
class SymbolTable : public Section
{
    AMANDA_OBJECT(SymbolTable, Section)
public:

    SymbolTable(const core::String& name);
    virtual ~SymbolTable();

    virtual void        addSymbol(const Symbol* symbol);
    virtual void        constructBinaryData();
    virtual unsigned    getIndexToSymbol(const core::String& name) const;
    virtual Symbol*     getSymbol(const core::String& name) const;
    virtual bool        hasSymbol(const core::String& name) const;

protected:

    typedef std::map<core::String, const Symbol*, core::AlphabeticalOrderComparator> SymbolMap;
    typedef std::vector<const Symbol*> SymbolVector;

    /// The symbols
    SymbolVector    orderedSymbols;
    SymbolMap       symbols;
} ;

}
}

#endif /* SYMBOLTABLE_H */

