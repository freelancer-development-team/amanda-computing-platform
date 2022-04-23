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

// C++ API
#include <cstdio>
#include <cstdlib>
#include <vector>

// Amanda API
#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/package.hxx>

// Internal API
#include "AssemblerParser-Inc.h"
#include "AssemblerLexer-Inc.h"

// Definition of yyerror
void yyerror(YYLTYPE* location, void* scanner, void** module, void* state, char const* message);

%}

// Requires Bison 2.7
%require "3.2"

%code
{
    // Use the corresponding namespaces.
    using namespace amanda;
    using namespace amanda::binutils;

    #define MODULE(m)   ((amanda::binutils::Module*) (m))
    #define STATE(s)    ((amanda::binutils::as::AssemblerParser::YYPSTATE*) (s))
}

%code provides
{
    // Include the corresponding definitions
    #include <amanda-vm/TypeSystem.h>
    #include <amanda-vm/Binutils/package.hxx>

    // C++
    #include <vector>
}

// Options
%defines "assembler/AssemblerParser-Inc.h"
%output "assembler/AssemblerParser-C.cpp"

%locations
%define api.header.include {"AssemblerParser-Inc.h"}
%define api.pure full
%define api.symbol.prefix {S_}
%define api.token.prefix {T_}
%define parse.error detailed
%define parse.lac full
%define lr.type ielr

// Lex & Parse parameters
%lex-param {yyscan_t& scanner}
%parse-param {void* scanner}
%parse-param {void** module}
%parse-param {void* state}

// Token semantic types & destructor for those types!!!
// Destructor declarations are essential. Please add a declaration for any
// pointer type
%union
{
    amanda::core::String*                           string;
    unsigned char                                   character;
    unsigned long long                              integer;
    long double                                     fp_number;
    std::vector<amanda::binutils::Instruction*>*    instruction_list;
    amanda::binutils::Instruction*                  insn;
}

%destructor { $$->release(); } <string>
%destructor { delete ($$);   } <instruction_list>

// Tokens
%token
    ATTRIBUTES  "attribute directive"
    DEF         "subroutine definition keyword"
    ENDEF       "end of subroutine"
    SECTION     "section directive"
    ;

// Instructions
%token
    POP         "pop instruction"
    PUSH        "push instruction"
    RET         "return instruction"
    ;

%token
    ';'     "semicolon delimiter"
    ;

// Token with semantic values
%token<string>      IDENTIFIER          "identifier";
%token<character>   INSTRUCTION_SUFFIX  "instruction suffix"
%token<string>      STRING_LITERAL      "string literal"
%token<integer>     INTEGER_LITERAL     "integer literal"
%token<fp_number>   FP_LITERAL          "floating point literal"

// Nonterminals
%type<instruction_list> instruction_sequence
%type<insn>             instruction zeroed_instruction unary_instruction label_declaration

%start compilation_unit
%%

compilation_unit
    : declarations
    ;

declarations
    : declaration
    | declarations declaration
    ;

declaration
    : section_declaration
    | function_declaration
    ;

// Declarations
section_declaration
    : SECTION STRING_LITERAL optional_attributes delimiter
                                                {
                                                    // Create a new section object
                                                    core::String sectionName($2->toCharArray());
                                                    Section* section = new Section(sectionName);

                                                    // Add the section to the module
                                                    MODULE(*module)->addSection(section);

                                                    // Set the section as the current section
                                                    STATE(state)->currentSection = MODULE(*module)->getSection(sectionName);

                                                    // Clean up
                                                    delete $2;
                                                }
    ;

function_declaration
    : DEF IDENTIFIER instruction_sequence ENDEF
                                                {
                                                    // Create a new function object
                                                    Function* function = new Function(*$2);

                                                    // Emit bytecode for that function
                                                    for (size_t i = 0; i < $3->size(); ++i)
                                                    {
                                                        function->emit($3->at(i));
                                                    }

                                                    // Add it to the current section & module
                                                    Section* cs = STATE(state)->currentSection;
                                                    Module* mod = MODULE(*module);

                                                    assert(cs != NULL && "current section is NULL?");
                                                    assert(mod != NULL && "module is NULL?");

                                                    mod->addSymbol(*function, *cs);

                                                    // Clean up
                                                    delete $2;
                                                    delete $3;
                                                }
    ;

// Secondary declarations
optional_attributes
    : attributes_declaration
    | %empty
    ;

attributes_declaration
    : ATTRIBUTES STRING_LITERAL delimiter
                                                {
                                                    // Clean up
                                                    delete $2;
                                                }
    ;

// Instructions
instruction_sequence
    : instruction                           { $$ = new std::vector<amanda::binutils::Instruction*>(); $$->push_back($1); }
    | instruction_sequence instruction      { $$ = $1; $$->push_back($2); }
    | %empty                                { $$ = new std::vector<amanda::binutils::Instruction*>(); }
    ;

instruction
    : zeroed_instruction delimiter
    | unary_instruction delimiter
    | label_declaration delimiter
    ;

zeroed_instruction
    : POP INSTRUCTION_SUFFIX                { $$ = new Instruction(AMANDA_VM_ENCODE_INSN(POP, B), 0); }
    | RET INSTRUCTION_SUFFIX                { $$ = new Instruction(AMANDA_VM_ENCODE_INSN(RET, B), 0); }
    ;

unary_instruction
    : PUSH INSTRUCTION_SUFFIX argument      { $$ = new Instruction(AMANDA_VM_ENCODE_INSN(PUSH, B), Instruction::getOperandSizeForSuffix($2)); }
    ;

label_declaration
    : IDENTIFIER ':'                        { $$ = NULL; delete $1; }
    ;

// Arguments
argument
    : IDENTIFIER
    | INTEGER_LITERAL
    | FP_LITERAL
    ;

// Misc
delimiter
    : ';'
    | %empty
    ;

%%

void yyerror(YYLTYPE* location, void* scanner, void** module, void* state, char const* message)
{
    // Just throw an exception that will be catch by the parser.
    // But first, create the location object.
    amanda::binutils::location_t loc =
        {
            {
                location->first_column,
                location->first_line
            },
            {
                location->last_column,
                location->last_line
            }
        };

    // Now throw the exception.
    throw amanda::binutils::SyntaxError(loc, core::String::makeFormattedString("%s. Got \"%s\"", message, yyget_text(scanner)));
}
