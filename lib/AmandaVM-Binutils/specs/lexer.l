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

// Amanda API
#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/package.hxx>

using namespace amanda;
using namespace amanda::binutils;

// Internal API
#include "AssemblerParser-Inc.h"

// Definitions
#define YY_NO_UNPUT 1
#define YY_USER_ACTION \
    yylloc->first_line = yylloc->last_line; \
    yylloc->first_column = yylloc->last_column; \
    \
    for (unsigned i = 0; yytext[i] != '\0'; ++i) \
    { \
        if (yytext[i] == '\n') \
        { \
            yylloc->last_line++; \
            yylloc->last_column = 0; \
        } \
        else \
        { \
            yylloc->last_column++; \
        } \
    }

// Prototypes
namespace amanda
{
    namespace binutils
    {
        namespace as
        {

            /**
             * Make a location object from a YYLTYPE pointer.
             */
            location_t makeLocation(YYLTYPE* locp);

            /**
             * Creates a new <code>String</code> object instance and returns
             * a pointer to it.
             */
            core::String* makeString(const char* cStr);

            unsigned long long parseIntegerLiteral(const char* literal);
        }
    }
}

// Macros
#define SAVE_STRING()   yylval->string = amanda::binutils::as::makeString(yytext)
#define SAVE_CHAR()     yylval->character = *yytext;
#define SAVE_INT()      yylval->integer = amanda::binutils::as::parseIntegerLiteral(yytext + 1)
#define SAVE_ADDR()     yylval->integer = amanda::binutils::as::parseIntegerLiteral(yytext)

%}

 // Options
%option full
%option noyywrap
%option never-interactive
%option reentrant
%option yylineno
%option 8bit
%option bison-bridge
%option bison-locations
%option extra-type="char*"

%option outfile="assembler/AssemblerLexer-C.cpp"
%option header-file="assembler/AssemblerLexer-Inc.h"

 // Lexical classes
Letter      [A-Za-z]
Digit       [0-9]
HexDigit    [0-9A-Fa-f]
OctDigit    [0-7]

Comment     "#"[^\n]*
WhiteSpace  [ \t\v\f\r\n]

Identifier  [.@]?({Letter}|[_@.?!~$]|{Digit}|("::"))+

Byte        b8
Word        w16
Long        l32
Quad        q64
Float       f32
Double      d64
Pointer     a64
Nil         v0

InstructionSuffix   ({Byte}|{Word}|{Long}|{Quad}|{Float}|{Double}|{Pointer}|{Nil})

DecimalInteger  "-"?({Digit})+
HexadecimalInt  ({HexDigit})+
BinaryInt       "0b"[0-1]+

IntegerLiteral  ({DecimalInteger}|("0x"{HexadecimalInt})|({BinaryInt}))
Integer         "$"({IntegerLiteral})
Address         {IntegerLiteral}

 // States
%x C_COMMENT
%x STRING

%%
                            char* string_buf_ptr = NULL;

 /* Ignore */
{WhiteSpace}
{Comment}

 /* C-style comments: ignored */
"/*"                        { BEGIN(C_COMMENT); }
<C_COMMENT>"*/"             { BEGIN(INITIAL); }
<C_COMMENT>\n               { }
<C_COMMENT>.                { }
<C_COMMENT><<EOF>>          { 
                                location_t loc = as::makeLocation(yylloc); 
                                throw SyntaxError(loc, "reached end of file while still reading a comment");
                            }

 /* String literal */
\"                          {
                                string_buf_ptr = yyextra;
                                BEGIN(STRING);
                            }
<STRING>\"                  {
                                BEGIN(INITIAL);
                                *string_buf_ptr = '\0';

                                yylval->string = amanda::binutils::as::makeString(yyextra);
                                return T_STRING_LITERAL;
                            }
<STRING>\n                  { throw SyntaxError(as::makeLocation(yylloc), "unterminated string constant"); }
<STRING><<EOF>>             { throw SyntaxError(as::makeLocation(yylloc), "unterminated string constant & end of file reached"); }
<STRING>\\[0-7]{1,3}        {
                                // Octal escape sequence
                                int result = ' ';
                                sscanf(yytext + 1, "%o", &result);
                                if (result > 0xFF)
                                {
                                    throw SyntaxError(as::makeLocation(yylloc), "constant is out of bounds");
                                }

                                *string_buf_ptr++ = result;
                            }
<STRING>\\[0-9]+            { throw SyntaxError(as::makeLocation(yylloc), "bad escape sequence in string literal."); }
<STRING>\\n                 { *string_buf_ptr++ = '\n'; }
<STRING>\\t                 { *string_buf_ptr++ = '\t'; }

<STRING>\\(.|\n)            { *string_buf_ptr++ = yytext[1]; }
<STRING>[^\\\n\"]+          {
                                char* yptr = yytext;

                                while (*yptr)
                                    *string_buf_ptr++ = *yptr++;
                            }

 /* Pseudo-instructions */

".attributes"               { return T_ATTRIBUTES; }
".def"                      { return T_DEF; }
".endef"                    { return T_ENDEF; }
".section"                  { return T_SECTION; }
".global"                   { return T_GLOBAL; }
".local"                    { return T_LOCAL; }
".weak"                     { return T_WEAK; }
".native"                   { return T_NATIVE; }
".extern"                   { return T_EXTERN; }

".address"                  { return T_ADDRESS; }
".byte"                     { return T_BYTE; }
".word"                     { return T_WORD; }
".long"                     { return T_LONG; }
".quad"                     { return T_QUAD; }
".float"                    { return T_FLOAT; }
".double"                   { return T_DOUBLE; }
".unicode"                  { return T_UNICODE; }

 /* Instructions */
"b2w"                       { return T_B2W; }
"b2l"                       { return T_B2L; }
"b2q"                       { return T_B2Q; }
"b2f"                       { return T_B2F; }
"b2d"                       { return T_B2D; }

"w2l"                       { return T_W2L; }
"w2q"                       { return T_W2Q; }
"w2f"                       { return T_W2F; }
"w2d"                       { return T_W2D; }

"l2q"                       { return T_L2Q; }
"l2f"                       { return T_L2F; }
"l2d"                       { return T_L2D; }

"q2f"                       { return T_Q2F; }
"q2d"                       { return T_Q2D; }

"add"                       { return T_ADD; }
"sub"                       { return T_SUB; }
"mul"                       { return T_MUL; }
"div"                       { return T_DIV; }
"mod"                       { return T_MOD; }

"invoke"                    { return T_INVOKE; }
"ccall"                     { return T_CCALL; }

"alloc"                     { return T_ALLOCA; }
"malloc"                    { return T_MALLOC; }
"delloc"                    { return T_DELLOC; }
"iload"                     { return T_ILOAD; }
"load"                      { return T_LOAD; }
"sload"                     { return T_SLOAD; }
"store"                     { return T_STORE; }
"sstore"                    { return T_SSTORE; }

"ceq"                       { return T_CEQ; }
"cne"                       { return T_CNE; }
"cgt"                       { return T_CGT; }
"clt"                       { return T_CLT; }
"cge"                       { return T_CGE; }
"cle"                       { return T_CLE; }

"pop"                       { return T_POP; }
"push"                      { return T_PUSH; }
"dup"                       { return T_DUP; }

"jmp"                       { return T_JUMP; }
"jt"                        { return T_JT; }
"jf"                        { return T_JF; }
"ret"                       { return T_RET; }

 /* Operators */
"["                         { return '['; }
"]"                         { return ']'; }
"$"                         { return '$'; }

 /* Suffixes */
{InstructionSuffix}         { SAVE_CHAR(); return T_INSTRUCTION_SUFFIX; }

 /* Literals */

{Integer}                   { SAVE_INT(); return T_INTEGER_LITERAL; }
{Address}                   { SAVE_ADDR(); return T_ADDRESS_CONSTANT; }
{Identifier}                { SAVE_STRING(); return T_IDENTIFIER; }

 /* Delimiters */
";"                         { return ';'; }
":"                         { return ':'; }

 /* Error because of unmatched character */
.           {
                /*
                 * Raise a syntax error because of unrecognized token.
                 * 1. Get the location
                 * 2. Throw the exception.
                 */
                location_t loc = {{yylloc->first_column, yylloc->first_line}, {yylloc->last_column, yylloc->last_line}};               
                throw SyntaxError(loc, core::String::makeFormattedString("unrecognized token '%s'.", yytext));
            }

%%

using namespace amanda;
using namespace amanda::binutils;
using namespace amanda::binutils::as;

location_t amanda::binutils::as::makeLocation(YYLTYPE* locp)
{
    location_t loc = {{locp->first_column, locp->first_line}, {locp->last_column, locp->last_line}};
    return loc;
}

core::String* amanda::binutils::as::makeString(const char* cStr)
{
    return new core::String(cStr);
}

unsigned long long amanda::binutils::as::parseIntegerLiteral(const char* literal)
{
    return core::UBigLong(literal).get();
}

