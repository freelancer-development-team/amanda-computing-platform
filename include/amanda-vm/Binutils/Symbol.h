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

// Forward declared
class Module;
class Section;

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
    struct SymbolTableEntry
    {
        vm::vm_dword_t      name;       /// Index of the name in the string table
        vm::vm_address_t    value;      /// Implementation dependent
        vm::vm_size_t       size;       /// Size
        vm::vm_byte_t       type;       /// Implementation defined
        vm::vm_byte_t       bind;       /// Bind class
        vm::vm_dword_t      flags;      /// Flags
        vm::vm_dword_t      shndx;      /// Section index associated with the symbol
        vm::vm_dword_t      padding;    /// Reserved for alignment
    } __attribute__((packed));
    typedef struct SymbolTableEntry SymbolTableEntry;

    /*
     * Symbol bind classes.
     */
    enum
    {
        Bind_Local = 0,     /// Local symbol only defined within the module
        Bind_Global = 1,    /// Global symbol
        Bind_Weak = 2,      /// Lesses precedence global symbol
        Bind_Extern = 3,
        Bind_Native = 4,
        Bind_LoProc = 13,   /// Reserved
        Bind_HiProc = 15    /// Reserved
    };

    /*
     * Symbol types.
     */
    enum
    {
        Type_None = 0,      /// No symbol type
        Type_Object = 1,    /// Object (raw data)
        Type_Function = 2,  /// Function (procedure)
        Type_Section = 3,   /// Section (sections are symbols... so it seems)
        Type_LoProc = 13,   /// Reserved
        Type_HiProc = 15,   /// Reserved
    };

    /*
     * Symbol flags
     */
    static const vm::vm_dword_t Flag_Resolved =     0x1;
    static const vm::vm_dword_t Flag_Unresolved =   ~(Flag_Resolved);

    static const core::String       getTypeStringFromValue(int type);
    static const SymbolTableEntry&  getNullSymbolTableEntry();

    Symbol(const core::String& name);
    virtual ~Symbol();

    const SymbolTableEntry& getEntry() const;
    const Module*           getModule() const;
    const core::String&     getName() const;
    const Section*          getSection() const;
    virtual size_t          getSize() const;
    bool                    isExternalSymbol() const;
    bool                    isNativeProcedure() const;
    bool                    isResolved() const;
    Symbol&                 setBindClass(vm::vm_byte_t bind);
    Symbol&                 setModule(Module* module);
    Symbol&                 setResolved(bool resolved);
    Symbol&                 setSection(Section* section);
    Symbol&                 setStringTableEntry(vm::vm_dword_t entry);
    Symbol&                 setSize(size_t size);
    Symbol&                 setType(vm::vm_byte_t type);
    Symbol&                 setValue(vm::vm_address_t value);
    
protected:

    SymbolTableEntry    entry;
    Module*             module;
    core::String        name;
    Section*            section;

    virtual void    marshallImpl(io::OutputStream& stream) const;

} ;

}
}

#endif /* SYMBOL_H */

