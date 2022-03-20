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
#include <amanda-vm/Frontend/SyntaxException.h>

%}

// Bison generator language & version options
%require "3.2"
%skeleton "lalr1.cc"
%language "c++"

// Instrument the parser for debugging
///TODO: Keep an eye on this
%define parse.trace

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
%parse-param {amanda::compiler::CompilationContext& compiler}
%parse-param {amanda::compiler::Scanner& lexer}

// Generate prefix for token types
%define api.token.prefix {TOKEN_}

/* ========================================================================== */

// The code to include with Parser.h
%code requires {

    #include <amanda-vm/TypeSystem.h>
    #include <amanda-c/ast-package.h>

    namespace amanda {
        namespace compiler
        {
            class Scanner;
            class CompilationContext;
        }
    }
}

// The code to include with Parser.cpp
%code {

    // Amanda Compiler API
    #include <amanda-vm/TypeSystem.h>
    #include <amanda-c/Scanner.h>
    #include <amanda-c/CompilationContext.h>
    #include <amanda-c/ast-package.h>

    // C++ standard API
    #include <vector>
    #include <list>
    #include <map>

    #undef yylex
    #define yylex lexer.lex

    using namespace amanda;
    using namespace amanda::compiler::ast;

    using amanda::core::StrongReference;
}

/* =================== TOKENS WITH SEMANTIC VALUES ========================== */

%token<amanda::core::String>    INTEGER     "integer literal"
%token<amanda::core::String>    IDENTIFIER  "identifier"
%token EOF                      0           "end of file"

/* ================== NONTERMINALS WITH SEMANTIC VALUES ===================== */

%type<amanda::compiler::ast::NCompilationUnit*>         compilation_unit
%type<amanda::compiler::ast::NDeclaration*>             declaration
%type<amanda::compiler::ast::NDeclarationBlock*>        declarations
%type<amanda::compiler::ast::NFunctionDeclaration*>     function_declaration
%type<amanda::core::String>                             name
%type<amanda::compiler::ast::NNamespaceDeclaration*>    namespace_declaration
%type<amanda::core::String>                             qualified_name
%type<amanda::core::String>                             simple_name

/* ============================ KEYWORDS ==================================== */

%token
    AND         "and"
    AS          "as"
    BREAK       "break"
    CASE        "case"
    CLASS       "class"
    DELETE      "delete"
    DO          "do"
    ELSE        "else"
    FOR         "for"
    IF          "if"
    IS          "is"
    INTERFACE   "interface"
    NAMESPACE   "namespace"
    NEW         "new"
    NOT         "not"
    OR          "or"
    PRIVATE     "private"
    PROTECTED   "protected"
    PUBLIC      "public"
    RETURN      "return"
    SWITCH      "switch"
    USING       "using"
    WHILE       "while"
;

%token
    BOOL        "bool"
    BYTE        "byte"
    SHORT       "short"
    INT         "int"
    LONG        "long"
    USHORT      "ushort"
    UINT        "uint"
    ULONG       "ulong"
    STRING      "string"
    CHAR        "char"
    VOID        "void"
;

/* ============================ OPERATORS =================================== */

// Multibyte operator
%token
    SCOPE_OP "'::'"
;

// Single byte operator
%token
    LE  "'<='"
    GE  "'>='"
    EQ  "'=='"
    NEQ "'!='"
;

%token
    PLUSPLUS    "'++'"
    MINUSMINUS  "'--'"
;

// Single byte operators
%token '!' '#' '$' '%' '&' '(' ')' '*' '+' ',' '-' '.' '/' ':' ';' '<' '=' '>' '?' '[' ']' '^' '{' '|' '}' '~'

// Operator precedence & associativity
// Includes ')' for casts and '[' for array indexing


// Parser algorithm
%define lr.type ielr

// Expects a given number of SR-Conflicts & set the start symbol
%expect 24
%start compilation_unit

%%

/* Start symbol & top-level grammar */
compilation_unit
    : declarations  {
                        NCompilationUnit* unit = new NCompilationUnit(lexer.filename.c_str());
                        assert($1 != NULL && "Null pointer exception.");

                        unit->addDeclarations($1);

                        // Set the parse tree to the compiler.
                        compiler.setAbstractSyntaxTree(unit);

                        // Assign the semmantic value to the accept rule
                        $$ = unit;
                    }
    ;

/* Declarations */
declarations
    : %empty                    { $$ = new NDeclarationBlock(); }
    | declaration               { $$ = new NDeclarationBlock(); $$->addDeclaration($1); }
    | declarations declaration  { $$ = $1; $$->addDeclaration($2); }
    ;

declaration
    : namespace_declaration { $$ = $1; }
    | function_declaration  { $$ = $1; }
    ;

namespace_declaration
    : NAMESPACE IDENTIFIER '{' declarations '}' { $$ = new NNamespaceDeclaration($2); $$->addDeclarations($4); }
    | NAMESPACE name ';' declarations           {
                                                    // This is gonna be the last generated namespace when
                                                    // we call the function
                                                    NNamespaceDeclaration* last = NULL;
                                                    NNamespaceDeclaration* parent = buildNamespacesByQualifiedName($2, last);

                                                    assert(last != NULL && "Null pointer exception");
                                                    assert(parent != NULL && "Null pointer exception");

                                                    $$ = parent; last->addDeclarations($4);
                                                }
    ;

function_declaration
    : type IDENTIFIER '(' argument_list ')' '{' '}' { $$ = new NFunctionDeclaration($2); }
    ;

/* Auxiliary declarations */
/* Types */
type
    : simple_type
    | reference_type
    | type '[' ']'
    ;

simple_type
    : VOID
    | BOOL
    | INT
    | STRING
    ;

reference_type
    : name
    ;

/* Names */
name
    : simple_name
    | qualified_name
    ;

simple_name
    : IDENTIFIER
    ;

qualified_name
    : IDENTIFIER SCOPE_OP IDENTIFIER        { $$.append($1).append("::").append($3); }
    | qualified_name SCOPE_OP IDENTIFIER    { $$ = $1; $$.append("::").append($3); }
    ;

/* Lists */
argument_list
    : %empty
    | type IDENTIFIER
    | argument_list ',' type IDENTIFIER
    ;

%%

static unsigned getDigitCount(int number)
{
    unsigned digitCount = 1;
    int tmp = number;

    while (tmp / 10 > 0)
    {
        digitCount++;
        tmp /= 10;
    }

    return digitCount;
}

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
    int l_start = loc.begin.line;
    int l_end = loc.end.line;
    int c_start = loc.begin.column;
    int c_end = loc.end.column;

    core::String line(lexer.matcher().line().c_str());
    line.replace("\t", makePadding(8));

    core::String lineAndError(
                    makePadding(
                        getDigitCount(l_start)
                        + getDigitCount(l_end)
                        + getDigitCount(c_start)
                        + getDigitCount(c_end)
                        + 5));
    lineAndError.append(line).append('\n');
    lineAndError.appendWithFormat(" %d:%d-%d:%d ",
                                    l_start, c_start,
                                    l_end, c_end);

    lineAndError.append(makePadding(c_start)).append("\033[35m");
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
    lineAndError.append("\033[0m");

    io::console().err.println(lineAndError);
    throw amanda::frontend::SyntaxException("syntax error.");
}
