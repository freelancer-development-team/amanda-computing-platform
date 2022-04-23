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
 * File:   AssemblerLexer.h
 * Author: Javier Marrero
 *
 * Created on April 12, 2022, 12:24 AM
 */

#ifndef ASSEMBLERLEXER_H
#define ASSEMBLERLEXER_H

#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Input.h>

namespace amanda
{
namespace binutils
{
namespace as
{

/**
 * The <code>AssemblerLexer</code> class creates objects capable of setting up
 * the initial state required by the <i>Lex</i> generated lexical scanner,
 * which is in turn used by the <i>Bison</i> generated parser to scan the
 * assembly source code. The scanner supports input from several sources, be it
 * a <code>io::File</code> object or a memory region. The necessary functions
 * to provide this class with the input it needs are supplied in the <code>
 * Input.h</code> file.
 * <p>
 * This class is put in another 'namespace' since its definition is not precisely
 * concern of the binary utilities library. It could have been done an internal
 * header, but there's no need to hide it generally speaking.
 *
 * @author J. Marrero
 */
class AssemblerLexer : public core::Object
{
    AMANDA_OBJECT(AssemblerLexer, core::Object)
public:

    typedef void* opaque_scanner_t;

    AssemblerLexer(const AssemblerInputStream& stream);
    virtual ~AssemblerLexer();

    const core::String&     getInputStreamName() const;
    const opaque_scanner_t& getScannerObject() const;

private:

    core::String inputStream;
    core::String inputStreamName;

    opaque_scanner_t    scanner;
    char*               tmpb;
} ;

}
}
}

#endif /* ASSEMBLERLEXER_H */

