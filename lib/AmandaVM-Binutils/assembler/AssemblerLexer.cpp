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
 * File:   AssemblerLexer.cpp
 * Author: Javier Marrero
 * 
 * Created on April 12, 2022, 12:24 AM
 */

#include <amanda-vm/Binutils/AssemblerLexer.h>
#include <amanda-vm/Binutils/package.hxx>

// Internal private API
#include "AssemblerParser-Inc.h"
#include "AssemblerLexer-Inc.h"

using namespace amanda;
using namespace amanda::binutils::as;

AssemblerLexer::AssemblerLexer(const AssemblerInputStream& stream)
:
inputStream(stream.second),
inputStreamName(stream.first),
tmpb(NULL)
{
    // Create the temporary stream used to hold strings.
    tmpb = new char[inputStream.length() + 1];
    memset(tmpb, 0, inputStream.length() + 1);

    yylex_init_extra(tmpb, &scanner);

    // Set the input buffer
    yy_scan_string(inputStream.toCharArray(), scanner);
}

AssemblerLexer::~AssemblerLexer()
{
    ///TODO: Delete buffer???
    yylex_destroy(scanner);

    delete[] tmpb;
}

const core::String& AssemblerLexer::getInputStreamName() const
{
    return inputStreamName;
}

const AssemblerLexer::opaque_scanner_t& AssemblerLexer::getScannerObject() const
{
    return scanner;
}



