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
 * File:   AssemblerParser.h
 * Author: Javier Marrero
 *
 * Created on April 2, 2022, 1:26 AM
 */

#ifndef ASSEMBLERPARSER_H
#define ASSEMBLERPARSER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/File.h>
#include <amanda-vm/IO/OutputStream.h>
#include <amanda-vm/Logging/Logger.h>
#include <amanda-vm/Binutils/Linker/BinaryObject.h>
#include <amanda-vm/Binutils/Linker/Section.h>

namespace amanda
{
namespace binutils
{
namespace as
{

/**
 * Represents a scanner-less parser for assembly source code. It eats textual
 * assembly representation and outputs machine code for the Amanda Virtual
 * Machine. As assembly is not type safe, analysis is quite limited in comparison
 * to the rest of parsers this project comes with. It is supposed that the
 * bulk of optimizations and analysis has been performed by previous stages
 * (including the intermediate representation hosted in the optimizer) and
 * therefore this assembler parser does not produces many optimizations.
 *
 * @author J. Marrero
 */
class AssemblerParser : public core::Object
{

    AMANDA_OBJECT(AssemblerParser, core::Object)
public:

    /** Non terminal tokens. */
    enum nonterminals
    {
        __MIN_NONTERMINAL_VALUE = 0xffff,
        INSTRUCTION_SEQUENCE
    } ;

    AssemblerParser(io::File* input, io::File* output);
    virtual ~AssemblerParser();

    virtual void generateCode(io::OutputStream& stream);
    virtual void parse();
    virtual void error(const core::String& message, ...);
    virtual void warn(const core::String& message, ...);

protected:

    /// This method is used to get 1 token lookahead.
    int lookAhead();

    /// This method returns the text stored in the scanner buffer.
    const char* text();

    /// Tokenize the input.
    int tokenize(bool override = false);

private:

    bool                                    feeding;
    core::StrongReference<io::File>         input;
    core::StrongReference<logging::Logger>  logger;
    core::StrongReference<ld::BinaryObject> object;
    core::StrongReference<io::File>         output;
    void*                                   scanner;
    int                                     token;
    
} ;

}
}
}

#endif /* ASSEMBLERPARSER_H */

