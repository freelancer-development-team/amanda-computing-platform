%{
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

/// AMANDA-PL LANGUAGE SPECIFICATION
///
/// The following GNU Bison specification is the formal specification for the
/// syntax of the Amanda Programming Language, a project belonging to the
/// Amanda Computing Platform.
/// This document is written in standard notation for Bison specifications,
/// a modified form of the EBNF notation. The syntactic groupings are organized,
/// please, do not get them out of order.
///

// C++ API
#include <cstdio>
#include <cstdlib>

// Compiler APIs
#include <amanda-c/Messages.h>

// Amanda APIs
#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/IO/Console.h>

%}

// Bison generator language & version options
%require "3.2"
%skeleton "lalr1.cc"
%language "c++"

// Parser class: amanda::compiler::DefaultParser
%define api.namespace       {amanda::compiler}
%define api.parser.class    {DefaultParser}

// Use C++ variants and generate make<TOKEN> constructors
%define api.value.type          variant
%define api.token.constructor

// Enable Bison locations
%locations
%define api.location.file       "../include/amanda-c/ParserLocations.h"
%define api.location.include    {<amanda-c/ParserLocations.h>}

// Bison error reporting
%define parse.error detailed
%define parse.lac   full

// Pass scanner object to the parse function
%parse-param {amanda::compiler::Scanner& lexer}

// Generate prefix for token types
%define api.token.prefix {TOKEN_}

/* ========================================================================== */

// The code to include with Parser.h
%code requires {

    #include <amanda-vm/TypeSystem.h>

    namespace amanda {
    namespace compiler 
    {
        class Scanner;
    }
    }
}

// The code to include with Parser.cpp
%code {

    // Amanda Compiler API
    #include <amanda-vm/TypeSystem.h>
    #include <amanda-c/Scanner.h>

    // C++ standard API
    #include <iostream>

    #undef yylex
    #define yylex lexer.lex
}

/* =================== TOKENS WITH SEMANTIC VALUES ========================== */

%token<amanda::core::String>    IDENTIFIER  "identifier"
%token EOF                      0           "end of file"

/* ================== NONTERMINALS WITH SEMANTIC VALUES ===================== */

/* ============================ KEYWORDS ==================================== */

%token
    AND         "and"
    CLASS       "class"
    NAMESPACE   "namespace"
    WHILE       "while"
;

%%

program : %empty
        ;

%%

static amanda::core::String makePadding(unsigned size)
{
    char buffer[size + 1] = {0};
    memset(buffer, ' ', size);

    return amanda::core::String(buffer);
}

void amanda::compiler::DefaultParser::error(const location& loc, const std::string& msg)
{
    log::error("%s:%d:%d: %s.",
                loc.begin.filename->c_str(),
                loc.begin.line, loc.begin.column,
                msg.c_str());

    // Print the line & error
    core::String lineAndError(makePadding(10));
    lineAndError.append(lexer.text()).append('\n');
    lineAndError.appendWithFormat(" %d:%d-%d:%d ",
                                    loc.begin.line, loc.begin.column,
                                    loc.end.line, loc.end.column);

    unsigned dt = (loc.end.column - loc.begin.column);
    for (unsigned i = 0; i <= dt; i++)
    {
        if (i == 0)
        {
            lineAndError.append('^');
        }
        else if (i == dt)
        {
            lineAndError.append('^');
        }
        else
        {
            lineAndError.append('~');
        }
    }

    io::console().err.println(lineAndError);
}
