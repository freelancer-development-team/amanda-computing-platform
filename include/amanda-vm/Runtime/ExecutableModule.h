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
 * File:   ExecutableModule.h
 * Author: Javier Marrero
 *
 * Created on June 18, 2022, 8:13 AM
 */

#ifndef EXECUTABLEMODULE_H
#define EXECUTABLEMODULE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Section.h>
#include <amanda-vm/Binutils/Symbol.h>
#include <amanda-vm/IO/InputStream.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Runtime/Procedure.h>

// C++
#include <map>

namespace amanda
{
namespace vm
{

class ModuleLoader;

class ExecutableModule : public core::Object
{
    AMANDA_OBJECT(ExecutableModule, core::Object)
public:

    // Friends
    friend class ModuleLoader;

    struct ExecutableHeader
    {
        vm::vm_byte_t   m_magic[4];
        vm::vm_qword_t  m_entry;
        vm::vm_qword_t  m_stab_offset;
        vm::vm_word_t   m_sh_entries;
        vm::vm_qword_t  m_sh_offset;
        vm::vm_qword_t  m_version;
    } __attribute__((packed));
    typedef struct ExecutableHeader ExecutableHeader;

    ExecutableModule(const core::String& name);
    virtual ~ExecutableModule();

    void                                        addSection(const core::String& name, const binutils::Section::SectionHeader& section);
    void                                        cacheLocalProcedure(const core::String& name, Procedure* proc);
    const binutils::Section::SectionHeader&     findSection(const core::String& name) const;
    const core::String                          findSymbolName(const vm::vm_qword_t offset) const;
    const binutils::Symbol::SymbolTableEntry*   findSymbol(const core::String& name, int type) const;
    const binutils::Symbol::SymbolTableEntry*   findSymbol(const vm::vm_dword_t index) const;
    const ExecutableHeader&                     getHeader() const;
    const vm::vm_size_t                         getSize() const;
    const vm::vm_size_t                         getSymbolCount() const;

private:

    typedef std::map<const vm::vm_dword_t, binutils::Symbol::SymbolTableEntry*> SymbolCache;

    static logging::Logger& LOGGER;

    static void swapEndianness(void* buffer, size_t size);

    std::map<const core::String, Procedure*>                            cachedProcedures;
    ExecutableHeader                                                    header;
    core::String                                                        name;
    std::map<core::String, binutils::Section::SectionHeader>            sections;
    vm::vm_size_t                                                       size;
    mutable SymbolCache                                                 symbols;

    bool    hasCachedSymbol(const vm::vm_dword_t index) const;

} ;

}
}

#endif /* EXECUTABLEMODULE_H */

