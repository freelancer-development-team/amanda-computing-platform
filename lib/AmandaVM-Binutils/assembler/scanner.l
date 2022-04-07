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

// Amanda API
#include <amanda-vm/TypeSystem.h>
#include <amanda-vm/Binutils/Assembler/AssemblerParser.h>
#include <amanda-vm/Binutils/Opcodes.h>

// C++ API
#include <cstring>

// Tokens
#include "_tokens.h"

using namespace amanda;
using namespace amanda::binutils::as;
using namespace amanda::vm;

// Declarations for the scanner
#define YY_NO_UNPUT 1
#define YY_USER_ACTION yycolumn++;

%}

 // Options
%option noyywrap
%option never-interactive
%option 8bit
%option full
%option batch
%option prefix="scanner_"
%option reentrant
%option yylineno
%option extra-type="amanda::binutils::as::AssemblerParser*"

 // Patterns
WhiteSpace          [ \t\v\f\r\n]
SingleLineComment   "#".*

Comments            {SingleLineComment}

Digit               [0-9]
HexDigit            [0-9A-Fa-f]
Integer             ({Digit}+)|("0"[xX]{HexDigit}+)

%x C_COMMENT
%x SINGLE_STRING

%%

{WhiteSpace}        { }
{Comments}          { }

"/*"                { BEGIN(C_COMMENT); }
<C_COMMENT>"*/"     { BEGIN(INITIAL); }
<C_COMMENT>\n       { }
<C_COMMENT>.        { }

 /* Literals */

\"                  { BEGIN(SINGLE_STRING); }
<SINGLE_STRING>{
    ([^\\\"]|\\.)*  { return TOKEN_STRING; }
    \"              { BEGIN(INITIAL); }
}

{Integer}           { return TOKEN_INTEGER; }

 /* Pseudo instructions */
".attributes"       { return TOKEN_ATTRIBUTES; }
".def"              { return TOKEN_DEF; }
".endef"            { return TOKEN_ENDEF; }
".section"          { return TOKEN_SECTION; }

 /* Instructions */
add                 { return TOKEN_ADD; }
sub                 { return TOKEN_SUB; }
mul                 { return TOKEN_MUL; }
div                 { return TOKEN_DIV; }
mod

push                { return TOKEN_PUSH; }
pop                 { return TOKEN_POP; }

ret                 { return TOKEN_RET; }

 /* Instruction suffixes */
b                   { return TOKEN_SUFFIX_BYTE; }
w                   { return TOKEN_SUFFIX_WORD; }
l                   { return TOKEN_SUFFIX_LONG; }
q                   { return TOKEN_SUFFIX_QUAD; }
f                   { return TOKEN_SUFFIX_FLOAT; }
d                   { return TOKEN_SUFFIX_DOUBLE; }

 /* Literal prefixes */
"$"

"@"[.A-Za-z0-9_@]+  { return TOKEN_IDENTIFIER; }

.                   { yyextra->error("unrecognized token: '%s'.", yytext); }

%%


