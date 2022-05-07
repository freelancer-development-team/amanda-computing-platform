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
 * File:   Section.h
 * Author: Javier Marrero
 *
 * Created on April 9, 2022, 7:13 PM
 */

#ifndef AMANDA_BINUTILS_SECTION_H
#define AMANDA_BINUTILS_SECTION_H

#include <amanda-vm/Binutils/vm-types.h>
#include <amanda-vm/Binutils/Serializable.h>
#include <amanda-vm/Binutils/Symbol.h>

// C++
#include <vector>

namespace amanda
{
namespace binutils
{

class Module;

#define CODE_SECTION_NAME               ".code"
#define DATA_SECTION_NAME               ".data"
#define STRINGS_SECTION_NAME            ".strings"
#define SECTION_HEADERS_STRINGS_NAME    ".sh-strings"
#define SYMBOL_TABLE_SECTION_NAME       ".symbols"
#define RODATA_SECTION_NAME             ".rodata"

/**
 * A section is a segment of binary data that is loaded at runtime by the
 * virtual machine.
 */
class Section : public Serializable
{
public:

    /**
     * Represents a section header.
     */
    struct SectionHeader
    {
        vm::vm_qword_t  address;
        vm::vm_dword_t  flags;
        vm::vm_dword_t  name;
        vm::vm_qword_t  offset;
        vm::vm_qword_t  size;
        vm::vm_word_t   type;
    } __attribute__((packed));
    typedef struct SectionHeader SectionHeader;

    /**
     * Constants for the types of section.
     */
    enum
    {
        Type_Null = 0,          /// Inactive section
        Type_ProgramBits = 1,   /// Information with program defined semantics
        Type_SymbolTable = 2,   /// Symbol table
        Type_StringTable = 3,   /// String table
        Type_Note = 7,          /// Compiler notes
        Type_Debug = 8          /// Debug information
    } ;

    /**
     * Constants for the attributes flags.
     */
    enum
    {
        Attr_None = 0,      /// No attributes
        Attr_Write = 1,     /// Write permission
        Attr_Read = 2,      /// Read permission (almost always present)
        Attr_Alloc = 4,     /// Occupies memory at runtime
        Attr_Exec = 8       /// Execute permission
    } ;

    static const float RESIZE_FACTOR = 1.1f;

    static Section* makeCodeSection();
    static Section* makeDataSection();
    static Section* makeReadOnlyDataSection();
    static Section* makeDebugSection();
    static Section* makeSectionHeaderStringTableSection();
    static Section* makeStringTableSection();
    static Section* makeSymbolTableSection();

    Section(const core::String& name);
    virtual ~Section();

    virtual void                addSymbol(const Symbol* symbol);
    virtual void                constructBinaryData();
    bool                        canExecute() const;
    bool                        canWrite() const;
    virtual bool                equals(const core::Object* object);
    const core::String&         getName() const;
    SectionHeader               getNullSectionHeader() const;
    size_t                      getOffsetToSymbol(const Symbol* symbol) const;
    const Module*               getOwningModule() const;
    const SectionHeader*        getSectionHeader() const;
    size_t                      getSize() const;
    const std::vector<Symbol*>& getSymbols() const;
    virtual void                merge(const Section* section);
    void                        setAttributes(unsigned attributes);
    void                        setNameIndex(const vm::vm_qword_t index);
    void                        setOwningModule(Module* module);
    void                        setType(unsigned type);

    bool operator== (const Section* section) const;

    template <typename T>
    void write(const T* data, size_t count = 1)
    {
        write(data, sizeof (T), count);
    }

    template <typename T>
    void write(const T& data, size_t count = 1)
    {
        write(&data, sizeof (T), count);
    }

protected:

    virtual size_t  calculateSize() const;
    virtual void    setSize(size_t size);

private:

    SectionHeader*              header;
    core::String                name;
    Module*                     owner;
    std::vector<Symbol*>        symbols;

    virtual void    marshallImpl(io::OutputStream& stream) const;

} ;

}
}

#endif /* SECTION_H */

