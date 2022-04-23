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
 * File:   SymbolTable.cpp
 * Author: Javier Marrero
 * 
 * Created on April 11, 2022, 11:01 PM
 */

#include <amanda-vm/Binutils/SymbolTable.h>

using namespace amanda;
using namespace amanda::binutils;

SymbolTable::SymbolTable(const core::String& name)
:
Section(name)
{
    setAttributes(Attr_Read);
    setType(Type_StringTable);
}

SymbolTable::~SymbolTable()
{
    for (std::map<core::String, const Symbol*>::const_iterator it = symbols.begin(),
         end = symbols.end(); it != end; ++it)
    {
        assert(it->second != NULL && "Null pointer exception.");

        // Release the previously grabbed reference.
        it->second->release();
    }
}

void SymbolTable::addSymbol(const Symbol* symbol)
{
    assert(symbol != NULL && "Null pointer exception.");

    // Own a reference to the object for all the life-cycle of this class.
    symbol->grab();

    // Add the symbol.
    symbols.insert(std::make_pair(symbol->getName(), symbol));

    // Increase the size
    setSize(getSize() + sizeof(Symbol::SymbolTableEntry));
}
