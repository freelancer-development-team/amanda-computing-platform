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
 * File:   AssemblerParser.cpp
 * Author: Javier Marrero
 * 
 * Created on April 12, 2022, 2:10 AM
 */

#include <amanda-vm/Binutils/AssemblerParser.h>
#include <amanda-vm/Binutils/SyntaxError.h>

#include "AssemblerParser-Inc.h"

// C++ API
#include <cstring>

using namespace amanda;
using namespace amanda::binutils;
using namespace amanda::binutils::as;

AssemblerParser::AssemblerParser(const AssemblerInputStream& stream)
:
logger(logging::Logger::getLogger("amanda.binutils.as.AssemblerParser")),
scanner(stream)
{
    memset(&state, 0, sizeof (YYPSTATE));
}

Module* AssemblerParser::parse() const
{
    // Create the pointer that will hold the returned reference.
    Module* result = new Module(scanner.getInputStreamName());

    // Set the initial parser state.
    {
        state.currentSection = result->getSection(CODE_SECTION_NAME);
        state.currentFunction = NULL;

        // Validate initial status
        assert(state.currentSection != NULL && "Unable to query code section.");
    }

    try
    {
        // Parse the provided input buffer
        int parserResult = yyparse(scanner.getScannerObject(), (void**) &result, &state);
        assert(parserResult == 0 && result != NULL && "How did this happen???");

        // Perform semantic analysis of the module
        // Link local symbols first
        result->linkLocalSymbols();

    }
    catch (SyntaxError& ex)
    {
        // Report the error using the logger instance.
        logger->error("%s: %d:%d: %s",
                      scanner.getInputStreamName().toCharArray(),
                      ex.getLocation().first.row,
                      ex.getLocation().first.column,
                      ex.getMessage().toCharArray());

        // Re-throw the exception (someone else has to catch this.
        // We only wanted to report the error.
        throw SyntaxError(ex.getLocation(), ex.getMessage());
    }
    catch (core::Exception& ex)
    {
        // Report the error
        logger->error("%s: %s",
                      scanner.getInputStreamName().toCharArray(),
                      ex.getMessage().toCharArray());

        // Re-throw the exception.
        throw ex;
    }
    return result;
}

