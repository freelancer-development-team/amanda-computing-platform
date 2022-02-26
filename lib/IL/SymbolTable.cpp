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
 * Created on February 24, 2022, 11:55 PM
 */

#include <amanda-vm/IL/SymbolTable.h>

#include <utility>

using amanda::il::SymbolTable;

using amanda::il::Symbol;
using amanda::core::String;

SymbolTable::SymbolTable(const core::String& name)
:
name(name)
{
}

SymbolTable::~SymbolTable()
{
    std::map<core::String, Symbol*, symbolComparator>::iterator iter;
    for (iter = hashMap.begin(); iter != hashMap.end(); iter++)
    {
        static_cast<Symbol*>(iter->second)->release();
    }
}

bool SymbolTable::insert(Symbol* symbol)
{
    bool result = false;
    if (symbol)
    {
        // The symbol table holds a reference to the symbol itself.
        symbol->grab();

        // Insert the symbol into the map.
        this->hashMap.insert(std::make_pair(symbol->getName(), symbol));

        // Return the result, the insertion must have been successful
        result = true;
    }
    return result;
}

size_t SymbolTable::size() const
{
    return hashMap.size();
}

String SymbolTable::toString() const
{
    String result("SYMBOL TABLE INSTANCE ");
    result.appendWithFormat("(0x%p): ", this).append(name).append('\n');

    std::map<core::String, Symbol*, symbolComparator>::const_iterator iter;
    for (iter = hashMap.begin(); iter != hashMap.end(); iter++)
    {
        Symbol* symbol = static_cast<Symbol*>(iter->second);
        
        result.appendWithFormat("SYMBOL INSTANCE (0x%p): name(%s)\n", 
                                symbol,
                                symbol->getName().toCharArray());
    }

    return result;
}

Symbol* SymbolTable::operator [](const String& name)
{
    return hashMap[name];
}
