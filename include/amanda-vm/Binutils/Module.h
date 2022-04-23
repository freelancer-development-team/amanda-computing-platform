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
 * File:   Module.h
 * Author: Javier Marrero
 *
 * Created on April 9, 2022, 3:55 PM
 */

#ifndef AMANDA_BINUTILS_MODULE_H
#define AMANDA_BINUTILS_MODULE_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/InputStream.h>
#include <amanda-vm/Binutils/vm-types.h>
#include <amanda-vm/Binutils/Serializable.h>
#include <amanda-vm/Binutils/Section.h>

#include <vector>

namespace amanda
{
namespace binutils
{

// Forward declarations
class ModuleReader;
class Symbol;

/**
 * Modules are basically a library of shared code that is ready to be deployed
 * in the Amanda Virtual Machine execution environment. There are two types of
 * modules: process modules (that contain a main function) and library modules.
 *
 * Modules contain code that is going to be executed by the virtual machine, but
 * they can virtually hold any type of information stored in binary format. The
 * executable format of the virtual machine knows about sections and will load
 * the data accordingly. The virtual machine byte-code is compiled at runtime by
 * the JIT-compilation framework of the environment.
 *
 * A module may consist of several object/source files and these object files in
 * turn may contain meta-data, resources or debug information. The binary format
 * is stored in network 'endianness' (big 'endian').
 *
 * Modules are also used before the final link stage as object files.
 *
 * @author J. Marrero
 */
class Module : public Serializable
{
    AMANDA_OBJECT(Module, Serializable)
public:

    // Friends
    friend class ModuleReader;

    /**
     * Represents a version number stored as a single 64-bit quad word. This
     * structure is encoded into the object file.
     */
    typedef struct version_triplet
    {
        vm::vm_word_t   major;
        vm::vm_word_t   minor;
        vm::vm_word_t   revision;
        vm::vm_word_t   _alignment;
    } version_triplet;

    static const vm::vm_byte_t MAGIC_NUMBER[4]; /// The magic number that must be present in every module.
    static const vm::vm_size_t SIZEOF_PROGRAM_HEADER = 128;  /// The program header is 128 bits long.

    static bool             checkMagicNumber(const io::InputStream& stream);
    static core::String     decodeVersionFromTriplet(const version_triplet& triplet);
    static version_triplet  encodeVersionFromString(const core::String& version);

    Module(const core::String& name);
    virtual ~Module();

    void                    addSymbol(Symbol& symbol, Section& section);
    void                    addSection(Section* section);
    size_t                  calculateSectionsSize() const;
    vm::vm_word_t           countSections() const;
    const version_triplet&  getBinaryFormatVersion() const;
    const core::String&     getCompilerName() const;
    vm::vm_qword_t          getEntryPointAddress() const;
    Section*                getSection(const core::String& name) const;
    vm::vm_qword_t          getSectionHeaderOffset() const;
    bool                    hasEntryPoint() const;
    bool                    hasProgramHeader() const;
    void                    setCompilerName(const core::String& name);
    void                    setBinaryFormatVersion(const core::String& version);

private:

    core::String            compilerName;
    vm::vm_qword_t          entryPointAddress;
    core::String            name;
    vm::vm_qword_t          programHeaderOffset;
    vm::vm_word_t           sectionHeaderEntries;
    vm::vm_qword_t          sectionHeaderOffset;
    std::vector<Section*>   sections;
    version_triplet         version;

    virtual void marshallImpl(io::OutputStream& stream) const;

} ;

}
}

#endif /* MODULE_H */

