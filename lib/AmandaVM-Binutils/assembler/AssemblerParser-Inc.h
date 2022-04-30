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
    T_ADD = 262,                   /* "add instruction"  */
    T_DIV = 263,                   /* "div instruction"  */
    T_INVOKE = 264,                /* "call instruction"  */
    T_JF = 265,                    /* "jump-if-false instruction"  */
    T_JUMP = 266,                  /* "jump instruction"  */
    T_JT = 267,                    /* "jump-if-true instruction"  */
    T_MOD = 268,                   /* "mod instruction"  */
    T_MUL = 269,                   /* "mul instruction"  */
    T_POP = 270,                   /* "pop instruction"  */
    T_PUSH = 271,                  /* "push instruction"  */
    T_RET = 272,                   /* "return instruction"  */
    T_SUB = 273,                   /* "sub instruction"  */
    T_B2W = 274,                   /* "byte-to-word instruction"  */
    T_B2L = 275,                   /* B2L  */
    T_B2Q = 276,                   /* B2Q  */
    T_B2F = 277,                   /* B2F  */
    T_B2D = 278,                   /* B2D  */
    T_W2L = 279,                   /* W2L  */
    T_W2Q = 280,                   /* "word-to-quad instruction"  */
    T_W2F = 281,                   /* W2F  */
    T_W2D = 282,                   /* W2D  */
    T_L2Q = 283,                   /* L2Q  */
    T_L2F = 284,                   /* L2F  */
    T_L2D = 285,                   /* L2D  */
    T_Q2F = 286,                   /* Q2F  */
    T_Q2D = 287,                   /* Q2D  */
    T_CEQ = 288,                   /* "compare-equals instruction"  */
    T_CNE = 289,                   /* "compare-non-equals instruction"  */
    T_IDENTIFIER = 290,            /* "identifier"  */
    T_INSTRUCTION_SUFFIX = 291,    /* "instruction suffix"  */
    T_STRING_LITERAL = 292,        /* "string literal"  */
    T_INTEGER_LITERAL = 293,       /* "integer literal"  */
    T_FP_LITERAL = 294,            /* "floating point literal"  */
    T_ADDRESS_CONSTANT = 295       /* "address constant"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 113 "specs/parser.y"

    amanda::core::String*                           string;
    unsigned char                                   character;
    unsigned long long                              integer;
    long double                                     fp_number;
    std::vector<amanda::binutils::Instruction*>*    instruction_list;
    amanda::binutils::Instruction*                  insn;
    amanda::binutils::Operand*                      operand;

#line 114 "assembler/AssemblerParser-Inc.h"

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
#line 81 "specs/parser.y"

    // Include the corresponding definitions
    #include <amanda-vm/TypeSystem.h>
    #include <amanda-vm/Binutils/package.hxx>

    // C++
    #include <vector>

#line 149 "assembler/AssemblerParser-Inc.h"

#endif /* !YY_YY_ASSEMBLER_ASSEMBLERPARSER_INC_H_INCLUDED  */
