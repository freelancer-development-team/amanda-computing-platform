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
 * File:   Module.cpp
 * Author: Javier Marrero
 * 
 * Created on April 9, 2022, 3:55 PM
 */

#include <amanda-vm/Binutils/Module.h>
#include <amanda-vm/Binutils/SymbolTable.h>
#include <amanda-vm/Binutils/StringTable.h>
#include <amanda-vm/Binutils/Logging.h>
#include <amanda-vm/Binutils/LinkException.h>
#include <amanda-vm/Binutils/Function.h>
#include <amanda-vm/Binutils/Instruction.h>
#include <amanda-vm/ADT/Collections.h>
#include <amanda-vm-c/sdk-version.h>

// C++
#include <cstring>

using namespace amanda;
using namespace amanda::binutils;

const vm::vm_byte_t Module::MAGIC_NUMBER[4] = {0x7F, '@', 'A', 'X'};
const core::String Module::ENTRY_POINT_PROCEDURE_NAME = "@@main?A_string@!l32";

bool Module::checkMagicNumber(const io::InputStream& stream)
{
    vm::vm_byte_t tmp[5] = {0};
    uint64_t offset = stream.tell();

    stream.reset();
    stream.read(tmp, VM_BYTE_SIZE, 4);

    stream.seek(offset);
    return memcmp(tmp, MAGIC_NUMBER, 4) == 0;
}

core::String Module::decodeVersionFromTriplet(const version_triplet& triplet)
{
    core::String result(triplet.major);
    result.append('.').append(core::String(triplet.minor)).append('.').append(core::String(triplet.revision));

    return result;
}

Module::version_triplet Module::encodeVersionFromString(const core::String& version)
{
    version_triplet triplet;
    unsigned index = 0;

    std::vector<core::String> components = version.split(".");
    for (std::vector<core::String>::const_iterator it = components.begin(),
         end = components.end(); it != end; ++it)
    {
        unsigned number = (unsigned) atoi((*it).toCharArray());

        switch (index)
        {
            case 0:
                triplet.major = number;
                break;
            case 1:
                triplet.minor = number;
                break;
            case 2:
                triplet.revision = number;
                break;
        }
        index++;
    }

    return triplet;
}

Module::Module(const core::String& name)
:
compilerName("\r\namanda-binutils assembler version(" SDK_FULLVERSION_STRING ") built on '" __TIMESTAMP__ "'."),
name(name)
{
    // Initialize the rest of the fields
    entryPointAddress = 0;
    stringTableOffset = 0;
    sectionHeaderEntries = 0;
    sectionHeaderOffset = 0;
    memset(&version, 0, sizeof (version_triplet));

    version = encodeVersionFromString(SDK_FULLVERSION_STRING);

    // Rest of the constructor logic
    sections.reserve(7);
    addSection(Section::makeSectionHeaderStringTableSection());
    addSection(Section::makeStringTableSection());
    addSection(Section::makeSymbolTableSection());
    addSection(Section::makeCodeSection());
    addSection(Section::makeDataSection());
    addSection(Section::makeReadOnlyDataSection());
}

Module::~Module()
{
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        (*it)->release();
    }
}

void Module::addSymbol(Symbol& symbol, Section& section)
{
    // Grab a reference to the symbol table of the module & add the symbol.
    SymbolTable* symtab = &(getSection(SYMBOL_TABLE_SECTION_NAME)->cast<SymbolTable>());
    symtab->addSymbol(&symbol);

    // Write the symbol to the section
    StringTable* strtab = &(getSection(STRINGS_SECTION_NAME)->cast<StringTable>());
    vm::vm_qword_t position = strtab->addString(symbol.getName());
    symbol.setStringTableEntry((vm::vm_dword_t) position);

    // Add the symbol to the section
    section.addSymbol(&symbol);

    // Add the reference
    symbol.setModule(this);
    symbol.setSection(&section);
    symbol.setValue(section.getOffsetToSymbol(&symbol));

}

void Module::addSection(Section* section)
{
    assert(section != NULL && "null pointer exception");
    // Check first if the vector contains a section with that name,
    // in order to know if we must merge
    bool contains = false;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end && !contains; ++it)
    {
        if ((*it)->getName() == section->getName())
        {
            contains = true;
        }
    }

    if (!contains)
    {
        StringTable* shstrtab = (StringTable*) getSection(SECTION_HEADERS_STRINGS_NAME);
        if (shstrtab != NULL)
        {
            // This means we are inserting a section just after creation of the
            // section table header string table, just as it should be.
            vm::vm_qword_t position = shstrtab->addString(section->getName());

            // Mark the position
            section->setNameIndex(position);
        }

        // Grab a reference to the section object & add it to the vector.
        section->grab();
        sections.push_back(section);

        // Set ownership to this object
        section->setOwningModule(this);
    }
    else
    {
        // Merge the section & delete the object.
        getSection(section->getName())->merge(section);
    }

    // Update the number of entries
    sectionHeaderEntries = sections.size();
}

vm::vm_qword_t Module::calculateOffsetToSection(const core::String& name) const
{
    vm::vm_qword_t result = 0;

    bool found = false;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end && found == false; ++it)
    {
        if ((*it)->getName() == name)
        {
            found = true;
        }
        else
        {
            result += (*it)->getSize();
        }
    }
    return result;
}

size_t Module::calculateSectionHeaderTableSize() const
{
    return sectionHeaderEntries * sizeof (Section::SectionHeader);
}

size_t Module::calculateSectionsSize() const
{
    size_t result = 0;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        result += (*it)->getSize();
    }
    return result;
}

void Module::constructBinaryData()
{
    // Recalculate the data concerning sections
    sectionHeaderEntries = countSections();
    sectionHeaderOffset = OFFSETOF_PROGRAM_HEADER;

    // Offset to the string table
    stringTableOffset = OFFSETOF_PROGRAM_HEADER
            + calculateSectionHeaderTableSize()
            + calculateOffsetToSection(SECTION_HEADERS_STRINGS_NAME);

    // Calculate the offset to every section
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        vm::vm_address_t offset = OFFSETOF_PROGRAM_HEADER
                + calculateSectionHeaderTableSize()
                + calculateOffsetToSection((*it)->getName());

        // Set the corresponding offset
        Section* section = *it;
        section->setOffset(offset);
        if (!section->is<StringTable>() && !section->is<SymbolTable>())
        {
            section->setSize(section->calculateSize());
        }
    }
}

vm::vm_word_t Module::countSections() const
{
    return sectionHeaderEntries;
}

Symbol* Module::findSymbol(const core::String& name) const
{
    return getSection(SYMBOL_TABLE_SECTION_NAME)->cast<SymbolTable>().getSymbol(name);
}

const Module::version_triplet& Module::getBinaryFormatVersion() const
{
    return version;
}

const core::String& Module::getCompilerName() const
{
    return compilerName;
}

vm::vm_qword_t Module::getEntryPointAddress() const
{
    return entryPointAddress;
}

Section* Module::getSection(const core::String& name) const
{
    Section* result = NULL;

    bool found = false;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end && !found; ++it)
    {
        if ((*it)->getName() == name)
        {
            found = true;
            result = *it;
        }
    }
    return result;
}

vm::vm_qword_t Module::getSectionHeaderOffset() const
{
    return sectionHeaderOffset;
}

vm::vm_qword_t Module::getSectionOffset(const Section* section) const
{
    vm::vm_qword_t offset = 0;

    bool found = false;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end && !found; ++it)
    {
        if ((*it) == section)
        {
            found = true;
        }
        else
        {
            offset += (*it)->getSize();
        }
    }

    return offset;
}

vm::vm_qword_t Module::getSymbolIndex(const Symbol* symbol) const
{
    return this->getSymbolIndex(symbol->getName());
}

vm::vm_qword_t Module::getSymbolIndex(const core::String& name) const
{
    return getSection(SYMBOL_TABLE_SECTION_NAME)->cast<SymbolTable>().getIndexToSymbol(name);
}

bool Module::hasEntryPoint() const
{
    return entryPointAddress != 0;
}

bool Module::hasProgramHeader() const
{
    return stringTableOffset != 0;
}

bool Module::hasSymbolDefined(const core::String& name) const
{
    return getSection(SYMBOL_TABLE_SECTION_NAME)->cast<SymbolTable>().hasSymbol(name);
}

void Module::linkLocalSymbols()
{
    // Get some relevant information sections
    SymbolTable* symbolTable = (SymbolTable*) getSection(SYMBOL_TABLE_SECTION_NAME);

    // Write correct information for the program header.

    // Set the main symbol address
    if (symbolTable->getSymbol(ENTRY_POINT_PROCEDURE_NAME) != NULL)
    {
        const Symbol* entry = symbolTable->getSymbol(ENTRY_POINT_PROCEDURE_NAME);
        const Section* entrySection = entry->getSection();

        entryPointAddress = getSectionOffset(entrySection) + entrySection->getOffsetToSymbol(entry);

        // Resolve the entry point
        eliminateConstness(entry)->setResolved(true);
    }

    // For each section, check & resolve as appropriate
    unsigned sectionIdx = 0;
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it, ++sectionIdx)
    {
        Section* section = (*it);
        assert(section != NULL && "Null pointer exception");

        // Get the symbols
        const std::vector<Symbol*>& symbols = section->getSymbols();
        for (std::vector<Symbol*>::const_iterator it = symbols.begin(),
             end = symbols.end(); it != end; ++it)
        {
            Symbol* symbol = *it;
            assert(symbol != NULL && "Null pointer exception");

            // If the symbol is a function
            // run through each instruction referencing a symbol and attempt
            // to resolve the operand based in the address of the symbol.
            // If the symbol is undefined, throw a linker exception.
            if (symbol->is<Function>())
            {
                Function* function = (Function*) symbol;
                const std::deque<Instruction*> instructions = function->getInstructions();

                // Symbol header
                function->setValue(function->getSection()->getOffsetToSymbol(symbol));
                function->setSize(function->getSize());

                for (std::deque<Instruction*>::const_iterator it = instructions.begin(),
                     end = instructions.end(); it != end; ++it)
                {
                    Instruction* insn = (*it);
                    assert(insn != NULL && "Null pointer exception.");

                    if (insn->equals(AMANDA_VM_INSN_SINGLE(INVOKE))
                        || insn->equals(AMANDA_VM_ENCODE_INSN(PUSH, A))
                        || insn->equals(AMANDA_VM_INSN_SINGLE(CCALL))
                        || insn->equals(AMANDA_VM_INSN_SINGLE(LOAD))
                        || insn->equals(AMANDA_VM_INSN_SINGLE(ILOAD)))
                    {
                        if (insn->getOperand()->isSymbol() && !insn->getOperand()->isResolved())
                        {
                            const core::String& symbolName = insn->getOperand()->getSymbolicName();
                            Symbol* symbol = symbolTable->getSymbol(symbolName);

                            if (symbol != NULL)
                            {
                                Operand* operand = eliminateConstness(insn->getOperand());
                                if (symbol->isExternalSymbol() == false)
                                {
                                    // Resolve the jump to the local symbol
                                    operand->resolve(getSymbolIndex(symbol), VM_QWORD_SIZE);
                                    symbol->setResolved(true);
                                }
                            }
                            else
                            {
                                throw UndefinedSymbolError(section->getName(), symbolName);
                            }
                        }
                    }
                }
            }

            // Link
            if (!symbol->isExternalSymbol())
            {
                // 0xffddeecc00000000
                symbol->setValue(symbol->getSection()->getOffsetToSymbol(symbol));
                symbol->setSectionIndex(sectionIdx);
            }
        }
    }
}

void Module::mergeExternalModule(Module& external)
{
    for (std::vector<Section*>::const_iterator it = external.sections.begin(),
         end = external.sections.end(); it != end; ++it)
    {
        (*it)->grab();
        addSection((*it));
    }

    // Recalculate header parameters

    // Link local symbols
    linkLocalSymbols();
}

void Module::marshallImpl(io::OutputStream& stream) const
{
    // Synchronize
    AMANDA_SYNCHRONIZED(lock);

    /*
     * BINARY LAYOUT OF THE OBJECT/EXECUTABLE/LIBRARY FILE:
     *
     * + Magic number (4B)
     * + Entry point address (8B)
     * + Program header offset (8B)
     * + Section header table entries (2B)
     * + Section header offset (8B)
     * + Binary object version (8B) [As directed by the standard, not the compiler]
     * + Compiler message (90B)
     *
     * + Program header
     * + Sections
     * + Section header table
     */

    // Create the compiler message.
    vm::vm_byte_t message[88] = {0};
    std::memcpy(message, compilerName.toCharArray(), compilerName.length() < 88 ? compilerName.length() : 88);

    // Write the magic number.
    stream.write(MAGIC_NUMBER, VM_BYTE_SIZE, 4);
    stream.write(&entryPointAddress, VM_QWORD_SIZE);
    stream.write(&stringTableOffset, VM_QWORD_SIZE);
    stream.write(&sectionHeaderEntries, VM_WORD_SIZE);
    stream.write(&sectionHeaderOffset, VM_QWORD_SIZE);
    stream.write(&version, VM_QWORD_SIZE);
    stream.write(message, VM_BYTE_SIZE, 88);
    stream.write("\x0d\0x0a", VM_BYTE_SIZE, 2);

    // Write the section table
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        const Section::SectionHeader* header = (*it)->getSectionHeader();
        stream.write(header, sizeof (Section::SectionHeader));
    }

    //stream.write("\nsections\n");   //TODO: COMMENT
    // Write every section.
    for (std::vector<Section*>::const_iterator it = sections.begin(),
         end = sections.end(); it != end; ++it)
    {
        Section* section = *it;
        //stream.write(core::String::makeFormattedString("\n-- %s --\n", section->getName().toCharArray()).toCharArray());  //TODO: DEBUG PURPOSES ONLY!!!!!

        // We don't know why but we needed to store this data before writing.
        // Anyway, problem solved. Do not perform the call directly.
        const void* binaryData = section->getBinaryData();
        size_t binaryDataLength = section->getBufferLength();

        stream.write(binaryData, VM_BYTE_SIZE, binaryDataLength);
    }
    //stream.write("\nend-sections\n");   //TODO: COMMENT

    // Desynchronize
    AMANDA_DESYNCHRONIZED(lock);
}

void Module::setBinaryFormatVersion(const core::String& version)
{
    this->version = encodeVersionFromString(version);
}

void Module::setCompilerName(const core::String& name)
{
    this->compilerName = name;
}

