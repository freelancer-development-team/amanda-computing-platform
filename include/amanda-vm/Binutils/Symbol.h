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
 * File:   Symbol.h
 * Author: Javier Marrero
 *
 * Created on April 11, 2022, 10:28 PM
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <amanda-vm/Binutils/Serializable.h>
#include <amanda-vm/Binutils/vm-types.h>
#include <amanda-vm/IO/OutputStream.h>

namespace amanda
{
namespace binutils
{

/**
 * A symbol is data within a section of the program identified by some abstract
 * name or address.
 * 
 */
class Symbol : public Serializable
{
    AMANDA_OBJECT(Symbol, Serializable)
public:

    /**
     * Represents an entry in the symbol table.
     */
    typedef struct SymbolTableEntry
    {
        vm::vm_dword_t      name;       /// Index of the same in the string table
        vm::vm_address_t    value;      /// Implementation dependent
        vm::vm_size_t       size;       /// Size
        vm::vm_byte_t       type;       /// Implementation defined
        vm::vm_byte_t       bind;       /// Bind class
        vm::vm_word_t       shndx;      /// Section index associated with the symbol
    } SymbolTableEntry;

    /*
     * Symbol bind classes.
     */
    enum
    {
        Bind_Local = 0,     /// Local symbol only defined within the module
        Bind_Global,        /// Global symbol
        Bind_Weak,          /// Lesses precedence global symbol
        Bind_LoProc = 13,   /// Reserved
        Bind_HiProc = 15    /// Reserved
    };

    /*
     * Symbol types.
     */
    enum
    {
        Type_None = 0,
        Type_Object,
        Type_Function,
        Type_Section,
        Type_LoProc = 13,
        Type_HiProc = 15,
    };

    static const SymbolTableEntry& getNullSymbolTableEntry();

    Symbol(const core::String& name);
    virtual ~Symbol();

    const SymbolTableEntry& getEntry() const;
    const core::String&     getName() const;
    virtual size_t          getSize() const;
    Symbol&                 setBindClass(vm::vm_byte_t bind);
    Symbol&                 setStringTableEntry(vm::vm_dword_t entry);
    Symbol&                 setSize(size_t size);
    Symbol&                 setType(vm::vm_byte_t type);
    
protected:

    SymbolTableEntry    entry;
    core::String        name;

    virtual void    marshallImpl(io::OutputStream& stream) const;

} ;

}
}

#endif /* SYMBOL_H */

