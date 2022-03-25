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

    // C++ API
    #include <vector>

    namespace amanda {
        namespace compiler
        {
            class Scanner;
            class CompilationContext;

            namespace ast
            {

            // Typedefs
            typedef std::vector<amanda::compiler::ast::NConditionalStatement*> ConditionalStatementList;

            }
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

    // Using declarations
    using namespace amanda;
    using namespace amanda::compiler::ast;

    // Class import
    using amanda::core::StrongReference;

}

/* =================== TOKENS WITH SEMANTIC VALUES ========================== */

%token<bool>                    BOOLEAN     "boolean literal"
%token<amanda::core::String>    INTEGER     "integer literal"
%token<amanda::core::String>    IDENTIFIER  "identifier"
%token EOF                      0           "end of file"

/* ================== NONTERMINALS WITH SEMANTIC VALUES ===================== */

%type<amanda::compiler::ast::NClassDeclaration::AccessModifier>     access_modifier
%type<amanda::compiler::ast::NAssignmentExpression*>                assignment_expression
%type<amanda::compiler::ast::NBinaryOperator*>                      binary_operator
%type<amanda::compiler::ast::NBoolean*>                             boolean_literal
%type<amanda::compiler::ast::NClassDeclaration*>                    class_declaration
%type<amanda::compiler::ast::NClassDeclaration::ClassSectionList*>  class_scope
%type<amanda::compiler::ast::NClassDeclaration::ClassBodySection*>  class_section
%type<amanda::compiler::ast::NStatement*>                           class_statement
%type<amanda::compiler::ast::StatementList*>                        class_statement_sequence
%type<amanda::compiler::ast::NCompilationUnit*>                     compilation_unit
%type<amanda::compiler::ast::NStatement*>                           compound_statement
%type<amanda::compiler::ast::NDeclaration*>                         declaration
%type<amanda::compiler::ast::NDeclarationBlock*>                    declarations
%type<amanda::compiler::ast::NExpression*>                          expression
%type<amanda::compiler::ast::ExpressionList*>                       expression_list
%type<amanda::compiler::ast::NExpressionStatement*>                 expression_statement
%type<amanda::compiler::ast::NClassFieldDeclaration*>               field_declaration
%type<amanda::compiler::ast::NForLoopStatement*>                    for_statement
%type<amanda::compiler::ast::NFunctionCall*>                        function_call
%type<amanda::compiler::ast::NFunctionDeclaration*>                 function_declaration
%type<amanda::compiler::ast::NIdentifier*>                          id
%type<amanda::compiler::ast::NConditionalStatement*>                if_statement
%type<amanda::compiler::ast::ConditionalStatementList>              multiple_else_if_clauses
%type<amanda::core::String>                                         name
%type<amanda::compiler::ast::NNamespaceDeclaration*>                namespace_declaration
%type<amanda::compiler::ast::NExpression*>                          numeric_literal
%type<amanda::compiler::ast::NExpression*>                          optional_expression
%type<amanda::core::String>                                         qualified_name
%type<amanda::compiler::ast::NReturnStatement*>                     return_statement
%type<amanda::core::String>                                         simple_name
%type<amanda::compiler::ast::NStatement*>                           simple_statement
%type<amanda::compiler::ast::NStatement*>                           statement
%type<amanda::compiler::ast::NBlock*>                               statement_sequence
%type<amanda::core::String>                                         type simple_type reference_type
%type<amanda::compiler::ast::NUsingDeclaration*>                    using_declaration
%type<amanda::compiler::ast::NVariableDeclaration*>                 variable_declaration
%type<amanda::compiler::ast::NWhileStatement*>                      while_statement

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
    EXCEPT      "except"
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
    TRY         "try"
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
    FLOAT       "float"
    DOUBLE      "double"
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
    NE  "'!='"
;

%token
    PLUSPLUS    "'++'"
    MINUSMINUS  "'--'"
;

// Single byte operators
%token '!' '#' '$' '%' '&' '(' ')' '*' '+' ',' '-' '.' '/' ':' ';' '<' '=' '>' '?' '[' ']' '^' '{' '|' '}' '~'

/* ==================== PRECEDENCE OF TERMINAL SYMBOLS ====================== */
// Operator precedence & associativity
// Includes ')' for casts and '[' for array indexing
%left EQ NE LE '<' GE '>'
%left '+' '-'
%left '*' '/'

/* ==================== PRECEDENCE OF NONTERMINALS ========================== */



/* ==================== PARSER ALGORITHM & TUNING =========================== */
// Parser LR algorithm
%define lr.type ielr

// Expects a given number of SR-Conflicts & set the start symbol
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

/* ========================= DECLARATIONS =================================== */

declaration
    : namespace_declaration { $$ = $1; }
    | using_declaration     { $$ = $1; }
    | class_declaration     { $$ = $1; }
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

using_declaration
    : USING name ';'        { $$ = new NUsingDeclaration($2); }
    ;

function_declaration
    : type IDENTIFIER '(' argument_list ')' '{' statement_sequence '}' { $$ = new NFunctionDeclaration($2, $7); }
    ;

class_declaration
    : access_modifier CLASS IDENTIFIER 
        '{'
            class_scope
        '}'
        {
            $$ = new NClassDeclaration($3);
            $$->addClassSections(*$5);

            // Set class properties
            $$->setAccessModifier($1);

            // Clean-up
            delete $5;
        }
    ;

class_scope
    : class_section                             { $$ = new NClassDeclaration::ClassSectionList(); $$->reserve(3); $$->push_back($1); }
    | class_scope class_section                 { $$ = $1; $$->push_back($2); }
    ;

class_section
    : access_modifier ':' class_statement_sequence
                                                {
                                                    $$ = new NClassDeclaration::ClassBodySection($1);
                                                    $$->setStatements(*$3);

                                                    // Clean-up the mess
                                                    delete $3;
                                                }
    ;

class_statement_sequence
    : %empty                                    { $$ = new StatementList(); }
    | class_statement                           { $$ = new StatementList(); $$->push_back($1); }
    | class_statement_sequence class_statement  { $$ = $1; $$->push_back($2); }
    ;

class_statement
    : field_declaration ';'                     { $$ = $1; }
    ;

field_declaration
    : type id           { $$ = new NClassFieldDeclaration($1, $2); }
    ;

/* ============================ Statements ================================== */
statement
    : simple_statement ';'
    | compound_statement
    ;

simple_statement
    : return_statement              { $$ = $1; }
    | expression_statement          { $$ = $1; }
    ;

compound_statement
    : if_statement                  { $$ = $1; }
    | for_statement                 { $$ = $1; }
    | while_statement               { $$ = $1; }
    ;

// These are the expressions allowed as
// statements
expression_statement
    : function_call                 { $$ = new NExpressionStatement($1); }
    | variable_declaration          { $$ = new NExpressionStatement($1); }
    | assignment_expression         { $$ = new NExpressionStatement($1); }
    ;

/* ======================== Simple statements =============================== */
return_statement
    : RETURN expression             { $$ = new NReturnStatement(); }
    | RETURN                        { $$ = new NReturnStatement(); }
    ;

/* ======================= Compound statements ============================== */
if_statement
    : IF '(' expression ')' '{' statement_sequence '}'
                                                        {
                                                            $$ = new NConditionalStatement($3, $6);
                                                        }

    | IF '(' expression ')' '{' statement_sequence '}' ELSE '{' statement_sequence '}'
                                                        {
                                                            $$ = new NConditionalStatement($3, $6); $$->addElseClause($10); 
                                                        }
    | IF '(' expression ')' '{' statement_sequence '}' multiple_else_if_clauses
                                                        {
                                                            $$ = new NConditionalStatement($3, $6);
                                                            $$->addMultipleElseIfClauses($8);
                                                        }
    | IF '(' expression ')' '{' statement_sequence '}' multiple_else_if_clauses ELSE '{' statement_sequence '}'
                                                        {
                                                            $$ = new NConditionalStatement($3, $6);
                                                            $$->addMultipleElseIfClauses($8);
                                                            $$->addElseClause($11);
                                                        }
    | IF '(' expression ')' statement
                                                        {
                                                            // Add a statement sequence
                                                            NBlock* block = new NBlock();
                                                            block->addStatement($5);

                                                            // Create the conditional statement
                                                            $$ = new NConditionalStatement($3, block);
                                                        }
    ;

multiple_else_if_clauses
    :   ELSE IF '(' expression ')' '{' statement_sequence '}'
                                                        {
                                                            $$.push_back(new NConditionalStatement($4, $7));
                                                        }
    |   multiple_else_if_clauses ELSE IF '(' expression ')' '{' statement_sequence '}'
                                                        {
                                                            $$ = $1;
                                                            $$.push_back(new NConditionalStatement($5, $8));
                                                        }
    ;

for_statement
    : FOR '(' optional_expression ';' expression ';' optional_expression ')' '{' statement_sequence '}'
                                                        {
                                                            $$ = new NForLoopStatement($3, $5, $7, $10);
                                                        }
    ;

while_statement
    : WHILE '(' expression ')' '{' statement_sequence '}'
                                                {
                                                    $$ = new NWhileStatement($3, $6);
                                                }
    | WHILE '(' expression ')' statement
                                                {
                                                    // Add a new scope to the while loop
                                                    NBlock* body = new NBlock();
                                                    body->addStatement($5);

                                                    $$ = new NWhileStatement($3, body);
                                                }
    ;

/* =========================== Expressions ================================== */
optional_expression
    : expression                                { $$ = $1; }
    | %empty                                    { $$ = NULL; }
    ;

expression
    : id                                        { $$ = $1; }
    | boolean_literal                           { $$ = $1; }
    | numeric_literal                           { $$ = $1; }
    | variable_declaration                      { $$ = $1; }
    | function_call                             { $$ = $1; }
    | binary_operator                           { $$ = $1; }
    | assignment_expression                     { $$ = $1; }
    | '(' expression ')'                        { $$ = $2; }
    ;

function_call
    : name '(' expression_list ')'  { $$ = new NFunctionCall($1); $$->addPassedArguments(*$3); delete $3; }
    ;

variable_declaration
    : type id                               { $$ = new NVariableDeclaration($1, $2); }
    | variable_declaration '=' expression   { $$ = $1; $$->setAssignmentExpression($3); }
    ;

assignment_expression
    : id '=' expression         { $$ = new NAssignmentExpression($1, $3); }
    ;

/* =================== Auxiliary declarations =============================== */
/* Identifier node */
id  : name                      { $$ = new NIdentifier($1); }
    ;

/* Numeric */
numeric_literal
    : INTEGER                   { $$ = new NInteger($1); }
    ;

/* Boolean */
boolean_literal
    : BOOLEAN                   { $$ = new NBoolean($1); }
    ;

/* Expression list */
expression_list
    : %empty                            { $$ = new ExpressionList();                    }
    | expression                        { $$ = new ExpressionList(); $$->push_back($1); }
    | expression_list ',' expression    { $$ = $1; $$->push_back($3);                   }
    ;

/* Blocks */
statement_sequence
    : %empty                        { $$ = new NBlock(); }
    | statement                     { $$ = new NBlock(); $$->addStatement($1); }
    | statement_sequence statement  { $$ = $1; $$->addStatement($2); }
    ;

/* Types */
type
    : simple_type
    | reference_type
    | type '[' ']'  { $$ = "Array@<"; $$.append($1).append(">"); }
    ;

simple_type
    : VOID      { $$ = "default-types::void"; }
    | BOOL      { $$ = "default-types::bool"; }
    | BYTE      { $$ = "default-types::byte"; }
    | SHORT     { $$ = "default-types::short"; }
    | INT       { $$ = "default-types::int"; }
    | LONG      { $$ = "default-types::long"; }
    | FLOAT     { $$ = "default-types::float"; }
    | DOUBLE    { $$ = "default-types::double"; }
    ;

reference_type
    : name
    | STRING    { $$ = "default-types::string"; }
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

/* ========================= Access modifiers =============================== */
access_modifier
    : PRIVATE       { $$ = NClassDeclaration::createAccessModifierFromString("private"); }
    | PROTECTED     { $$ = NClassDeclaration::createAccessModifierFromString("protected"); }
    | PUBLIC        { $$ = NClassDeclaration::createAccessModifierFromString("public"); }
    ;

/* Lists */
argument_list
    : %empty
    | type IDENTIFIER
    | argument_list ',' type IDENTIFIER
    ;

/* Operators */
binary_operator
    : expression '<' expression             { $$ = new NBinaryOperator(BO_Lesser, $1, $3); }
    | expression LE expression              { $$ = new NBinaryOperator(BO_LesserEquals, $1, $3); }
    | expression '>' expression             { $$ = new NBinaryOperator(BO_Greater, $1, $3); }
    | expression GE expression              { $$ = new NBinaryOperator(BO_GreaterEquals, $1, $3); }
    | expression EQ expression              { $$ = new NBinaryOperator(BO_Equals, $1, $3); }
    | expression NE expression              { $$ = new NBinaryOperator(BO_NotEquals, $1, $3); }
    | expression '+' expression             { $$ = new NBinaryOperator(BO_Sum, $1, $3); }
    | expression '-' expression             { $$ = new NBinaryOperator(BO_Sub, $1, $3); }
    | expression '/' expression             { $$ = new NBinaryOperator(BO_Div, $1, $3); }
    | expression '*' expression             { $$ = new NBinaryOperator(BO_Mult, $1, $3); }
    ;

%%
// ========================== EPILOGUE ====================================== //

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
