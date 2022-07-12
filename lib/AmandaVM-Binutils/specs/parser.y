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

    namespace amanda
    {
        namespace binutils
        {
            namespace as
            {

                inline Instruction* createZeroOpInstruction(const unsigned opcode, const char suffix)
                {
                    return new Instruction(opcode + Instruction::getInstructionNumericSuffix(suffix), 0);
                }

                inline Instruction* createZeroOpNoSuffixInstruction(const unsigned opcode)
                {
                    return new Instruction(opcode, 0);
                }

                inline Instruction* createUnaryInstruction(const unsigned opcode, const char suffix)
                {
                    return new Instruction(opcode + Instruction::getInstructionNumericSuffix(suffix), Instruction::getOperandSizeForSuffix(suffix));
                }

                inline Instruction* createUnaryNoSuffixInstruction(const unsigned opcode, const unsigned size)
                {
                    return new Instruction(opcode, size);
                }

                inline Instruction* createBranchInstruction(const unsigned opcode)
                {
                    return new Instruction(opcode, VM_QWORD_SIZE);
                }
            }
        }
    }
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
    amanda::binutils::Operand*                      operand;
}

%destructor { $$->release(); } <insn>
%destructor { $$->release(); } <operand>
%destructor { $$->release(); } <string>
%destructor { delete ($$);   } <instruction_list>

// Tokens
%token
    ATTRIBUTES  "attribute directive"
    DEF         "subroutine definition keyword"
    ENDEF       "end of subroutine"
    SECTION     "section directive"
    GLOBAL      "global symbol declaration"
    LOCAL       "local symbol declaration"
    WEAK        "weak symbol declaration"
    NATIVE      "native symbol declaration"
    EXTERN      "extern symbol declaration"
    ;

%token
    ADDRESS     "address pseudo-operator"
    BYTE        "byte pseudo-operator"
    WORD        "word pseudo-operator"
    LONG        "long pseudo-operator"
    QUAD        "quad pseudo-operator"
    FLOAT       "float pseudo-operator"
    DOUBLE      "double pseudo-operator"
    UNICODE     "unicode pseudo-operator"
    ;

// Instructions
%token
    ADD         "add instruction"
    ALLOCA      "stack allocation instruction"
    CCALL       "native call instruction"
    DELLOC      "heap deallocation instruction"
    DIV         "div instruction"
    DUP         "dup instruction"
    INVOKE      "call instruction"
    JF          "jump-if-false instruction"
    JUMP        "jump instruction"
    JT          "jump-if-true instruction"
    LOAD        "load instruction"
    ILOAD       "load-by-index instruction"
    MALLOC      "heap allocation instruction"
    MOD         "mod instruction"
    MUL         "mul instruction"
    POP         "pop instruction"
    PUSH        "push instruction"
    RET         "return instruction"
    SLOAD       "stack memory load instruction"
    SUB         "sub instruction"
    STORE       "store instruction"
    SSTORE      "stack write instruction"
    ;

%token
    B2W         "byte-to-word instruction"
    B2L
    B2Q
    B2F
    B2D
    W2L
    W2Q         "word-to-quad instruction"
    W2F
    W2D
    L2Q
    L2F
    L2D
    Q2F
    Q2D
    ;

%token
    CEQ         "compare-equals instruction"
    CNE         "compare-non-equals instruction"
    CGT         "compare-greater instruction"
    CLT         "compare-lesser instruction"
    CGE         "compare-greater-equals instruction"
    CLE         "compare-lesser-equals instruction"
    ;

%token
    ';'         "semicolon delimiter"
    ;

// Token with semantic values
%token<string>      IDENTIFIER          "identifier";
%token<character>   INSTRUCTION_SUFFIX  "instruction suffix"
%token<string>      STRING_LITERAL      "string literal"
%token<integer>     INTEGER_LITERAL     "integer literal"
%token<fp_number>   FP_LITERAL          "floating point literal"
%token<integer>     ADDRESS_CONSTANT    "address constant"

// Nonterminals
%type<operand>          argument address_constant branch_target
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
    | symbol_declaration                        { MODULE(*module)->addSymbol(*(STATE(state)->currentObject), *(STATE(state)->currentSection)); }
    | native_symbol_declaration
    | constant_declaration
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

                                                    // Reset the offset
                                                    STATE(state)->localOffset = 0;
                                                }

symbol_declaration
    : GLOBAL IDENTIFIER ':' { STATE(state)->currentObject = new DataObject(*$2, Symbol::Bind_Global); delete $2; }
    | WEAK IDENTIFIER ':'   { STATE(state)->currentObject = new DataObject(*$2, Symbol::Bind_Weak); delete $2; }
    | LOCAL IDENTIFIER ':'  { STATE(state)->currentObject = new DataObject(*$2, Symbol::Bind_Local); delete $2; }
    | EXTERN IDENTIFIER     {
                                DataObject* externSymbol = new DataObject(*$2, Symbol::Bind_Extern); delete $2;
                                MODULE(*module)->addSymbol(*externSymbol, *(STATE(state)->currentSection));
                            }
    ;

native_symbol_declaration
    : NATIVE IDENTIFIER     {
                                DataObject* nativeSymbol = new DataObject(*$2, Symbol::Bind_Native); delete $2;
                                MODULE(*module)->addSymbol(*nativeSymbol, *(STATE(state)->currentSection));
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

constant_declaration
    : ADDRESS INTEGER_LITERAL               { STATE(state)->currentObject->addData(&($2), VM_ADDRESS_SIZE);  }
    | UNICODE STRING_LITERAL                { STATE(state)->currentObject->addUtf8Data($2->toCharArray(), $2->length() + 1); }
    | LONG INTEGER_LITERAL                  { STATE(state)->currentObject->addData(&($2), VM_DWORD_SIZE); }
    | QUAD INTEGER_LITERAL                  { STATE(state)->currentObject->addData(&($2), VM_QWORD_SIZE); }
    ;

// Instructions
instruction_sequence
    : instruction                           { $$ = new std::vector<amanda::binutils::Instruction*>(); $$->push_back($1); if (!($1->is<Label>())) STATE(state)->localOffset += $1->getSize(); }
    | instruction_sequence instruction      { $$ = $1; $$->push_back($2); if (!($2->is<Label>())) STATE(state)->localOffset += $2->getSize(); }
    | %empty                                { $$ = new std::vector<amanda::binutils::Instruction*>(); }
    ;

instruction
    : zeroed_instruction delimiter
    | unary_instruction delimiter
    | label_declaration delimiter
    ;

zeroed_instruction
    : ADD INSTRUCTION_SUFFIX                { $$ = new Instruction(AMANDA_VM_INSN_FAMILY(ADD) + Instruction::getInstructionNumericSuffix($2), 0); }
    | CEQ INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(CEQ), $2); }
    | CNE INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(CNE), $2); }
    | CGT INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(CGT), $2); }
    | CLT INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(CLT), $2); }
    | CGE INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(CGE), $2); }
    | CLE INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(CLE), $2); }
    | DIV INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(DIV), $2); }
    | DUP INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(DUP), $2); }
    | MUL INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(MUL), $2); }
    | POP INSTRUCTION_SUFFIX                { $$ = new Instruction(AMANDA_VM_INSN_FAMILY(POP) + Instruction::getInstructionNumericSuffix($2), 0); }
    | RET INSTRUCTION_SUFFIX                { $$ = new Instruction(AMANDA_VM_INSN_FAMILY(RET) + Instruction::getInstructionNumericSuffix($2), 0); }
    | SUB INSTRUCTION_SUFFIX                { $$ = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(SUB), $2); }
    // Conversion instructions
    | B2W                                   { $$ = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(B2W)); }
    | B2L                                   { $$ = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(B2L)); }
    | B2Q                                   { $$ = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(B2Q)); }
    | W2L                                   { $$ = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(W2L)); }
    | W2Q                                   { $$ = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(W2Q)); }
    | L2Q                                   { $$ = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(L2Q)); }
    ;

unary_instruction
    : CCALL IDENTIFIER                      { $$ = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(CCALL)); Operand* operand = new Operand(*$2); $$->setOperand(operand); delete $2; }
    | JUMP address_constant                 { $$ = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(JMP)); $$->setOperand($2); }
    | JUMP IDENTIFIER                       {
                                                $$ = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(JMP));

                                                // Allocate the operand
                                                Operand* operand = new Operand(*$2);
                                                $$->setOperand(operand);

                                                // Clean up
                                                delete $2;
                                            }
    // Branch
    | JF branch_target                      { $$ = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(JF)); $$->setOperand($2); }
    | JT branch_target                      { $$ = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(JT)); $$->setOperand($2); }
    // Invoke
    | INVOKE IDENTIFIER                     { $$ = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(INVOKE)); Operand* operand = new Operand(*$2); $$->setOperand(operand); delete $2;}
    // Stack
    | PUSH INSTRUCTION_SUFFIX argument      { $$ = as::createUnaryInstruction(AMANDA_VM_INSN_FAMILY(PUSH), $2); $$->setOperand($3); }
    // Memory management
    | ALLOCA INTEGER_LITERAL                {
                                                $$ = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(ALLOCA), VM_QWORD_SIZE);
                                                Operand* operand = new Operand($2); $$->setOperand(operand);
                                            }
    | DELLOC                                {
                                                $$ = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(DELLOC));
                                            }
    | MALLOC INTEGER_LITERAL                {
                                                $$ = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(MALLOC), VM_QWORD_SIZE);
                                                Operand* operand = new Operand($2); $$->setOperand(operand);
                                            }
    | LOAD INTEGER_LITERAL                  {
                                                $$ = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(LOAD), VM_QWORD_SIZE);
                                                Operand* operand = new Operand($2); $$->setOperand(operand);
                                            }
    | ILOAD IDENTIFIER                      {
                                                $$ = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(ILOAD), VM_ADDRESS_SIZE);
                                                Operand* operand = new Operand(*$2); $$->setOperand(operand);
                                                delete $2;
                                            }
    | SLOAD INTEGER_LITERAL                 {
                                                $$ = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(SLOAD), VM_ADDRESS_SIZE);
                                                Operand* operand = new Operand($2); $$->setOperand(operand);
                                            }
    | STORE INSTRUCTION_SUFFIX argument     {
                                                $$ = as::createUnaryInstruction(AMANDA_VM_INSN_FAMILY(STORE), $2);
                                                $$->setOperand($3); 
                                            }
    | SSTORE INTEGER_LITERAL                {
                                                $$ = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(SSTORE), VM_ADDRESS_SIZE);
                                                Operand* operand = new Operand($2); $$->setOperand(operand);
                                            }
    ;

label_declaration
    : IDENTIFIER ':'                        { $$ = new Label(*$1, STATE(state)->localOffset); delete $1; }
    ;

// Arguments
argument
    : IDENTIFIER                            { $$ = new Operand(*$1); delete $1; }
    | INTEGER_LITERAL                       { $$ = new Operand($1); }
    | FP_LITERAL                            { $$ = NULL; }
    | address_constant                      
    ;

branch_target
    : address_constant
    | IDENTIFIER                            { $$ = new Operand(*$1); delete $1; }
    ;

address_constant
    : '[' INTEGER_LITERAL ']'               { $$ = new Operand($2, VM_QWORD_SIZE); }
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
