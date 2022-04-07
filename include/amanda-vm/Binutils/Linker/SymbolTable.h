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
 * File:   SymbolTable.h
 * Author: Javier Marrero
 *
 * Created on April 7, 2022, 3:11 AM
 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <amanda-vm/Binutils/Linker/Section.h>
#include <amanda-vm/Binutils/Linker/Symbol.h>

namespace amanda
{
namespace binutils
{
namespace ld
{

/**
 * The symbol table is an especial section inside of the object file.
 */
class SymbolTable : public Section
{
    AMANDA_OBJECT(SymbolTable, Section)
public:

    SymbolTable();
    
    virtual void marshall(io::OutputStream& stream);

} ;

}
}
}

#endif /* SYMBOLTABLE_H */

