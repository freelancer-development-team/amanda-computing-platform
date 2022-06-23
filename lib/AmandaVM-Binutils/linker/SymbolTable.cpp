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
 * File:   SymbolTable.cpp
 * Author: Javier Marrero
 * 
 * Created on April 11, 2022, 11:01 PM
 */

#include <amanda-vm/Binutils/SymbolTable.h>
#include <amanda-vm/Binutils/Logging.h>

using namespace amanda;
using namespace amanda::binutils;

SymbolTable::SymbolTable(const core::String& name)
:
Section(name)
{
    setAttributes(Attr_Read);
    setType(Type_SymbolTable);

    // Reserve space
    ordererSymbols.reserve(25);
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
    ordererSymbols.push_back(symbol);

    // Increase the size
    setSize(symbols.size() * sizeof (Symbol::SymbolTableEntry));
}

void SymbolTable::constructBinaryData()
{
    for (SymbolVector::const_iterator it = ordererSymbols.begin(), end = ordererSymbols.end();
         it != end; ++it)
    {
        const Symbol* symbol =  (*it);
        assert(symbol != NULL && "Null pointer exception.");

        const Symbol::SymbolTableEntry entry = symbol->getEntry();

        // Serializable::write("!!", 1, 2);
        Serializable::write(&entry, sizeof (entry), 1);
        // Serializable::write("!!", 1, 2);
    }
}

unsigned SymbolTable::getIndexToSymbol(const core::String& name) const
{
    unsigned result = 0;
    if (hasSymbol(name))
    {
        const Symbol* object = getSymbol(name);

        bool found = false;
        for (SymbolVector::const_iterator it = ordererSymbols.begin(), end = ordererSymbols.end();
             it != end && !found; ++it)
        {
            if ((*it) == object)
            {
                found = true;
            }
            else
            {
                result++;
            }
        }
    }
    return result;
}

Symbol* SymbolTable::getSymbol(const core::String& name) const
{
    //TODO: Optimize this
    // We must have in account that finding is expensive. (I mean, not that
    // expensive, just log(n) but, we are duplicating the cost this way)

    Symbol* result = NULL;
    if (symbols.find(name) != symbols.end())
    {
        result = eliminateConstness(symbols.find(name)->second);
    }
    return result;
}

bool SymbolTable::hasSymbol(const core::String& name) const
{
    return symbols.find(name) != symbols.end();
}
