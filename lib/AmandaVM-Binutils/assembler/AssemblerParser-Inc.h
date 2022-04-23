/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ASSEMBLER_ASSEMBLERPARSER_INC_H_INCLUDED
# define YY_YY_ASSEMBLER_ASSEMBLERPARSER_INC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_YYEMPTY = -2,
    T_YYEOF = 0,                   /* "end of file"  */
    T_YYerror = 256,               /* error  */
    T_YYUNDEF = 257,               /* "invalid token"  */
    T_ATTRIBUTES = 258,            /* "attribute directive"  */
    T_DEF = 259,                   /* "subroutine definition keyword"  */
    T_ENDEF = 260,                 /* "end of subroutine"  */
    T_SECTION = 261,               /* "section directive"  */
    T_POP = 262,                   /* "pop instruction"  */
    T_PUSH = 263,                  /* "push instruction"  */
    T_RET = 264,                   /* "return instruction"  */
    T_IDENTIFIER = 265,            /* "identifier"  */
    T_INSTRUCTION_SUFFIX = 266,    /* "instruction suffix"  */
    T_STRING_LITERAL = 267,        /* "string literal"  */
    T_INTEGER_LITERAL = 268,       /* "integer literal"  */
    T_FP_LITERAL = 269             /* "floating point literal"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "specs/parser.y"

    amanda::core::String*                           string;
    unsigned char                                   character;
    unsigned long long                              integer;
    long double                                     fp_number;
    std::vector<amanda::binutils::Instruction*>*    instruction_list;
    amanda::binutils::Instruction*                  insn;

#line 87 "assembler/AssemblerParser-Inc.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (void* scanner, void** module, void* state);
/* "%code provides" blocks.  */
#line 51 "specs/parser.y"

    // Include the corresponding definitions
    #include <amanda-vm/TypeSystem.h>
    #include <amanda-vm/Binutils/package.hxx>

    // C++
    #include <vector>

#line 122 "assembler/AssemblerParser-Inc.h"

#endif /* !YY_YY_ASSEMBLER_ASSEMBLERPARSER_INC_H_INCLUDED  */
