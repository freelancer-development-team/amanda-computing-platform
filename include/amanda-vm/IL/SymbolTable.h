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
 * Created on February 24, 2022, 11:55 PM
 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <amanda-vm/Object.h>
#include <amanda-vm/String.h>
#include <amanda-vm/IL/Symbol.h>

#include <cstddef>
#include <map>

namespace amanda
{
namespace il
{

class SymbolTable : public core::Object
{
    AMANDA_OBJECT(SymbolTable, core::Object)
    
public:

    SymbolTable(const core::String& name);
    ~SymbolTable();

    bool    insert(Symbol* symbol);
    size_t  size() const;

    virtual core::String toString() const;

    Symbol* operator[](const core::String& name);

private:

    struct symbolComparator
    {
        bool operator()(const core::String& s1, const core::String& s2) const
        {
            return s1.compare(s2, true) < 0;
        }
    };

    core::String                                        name;
    std::map<core::String, Symbol*, symbolComparator>   hashMap;
} ;

}
}

#endif /* SYMBOLTABLE_H */

