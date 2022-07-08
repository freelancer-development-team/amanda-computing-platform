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
    T_GLOBAL = 262,                /* "global symbol declaration"  */
    T_LOCAL = 263,                 /* "local symbol declaration"  */
    T_WEAK = 264,                  /* "weak symbol declaration"  */
    T_NATIVE = 265,                /* "native symbol declaration"  */
    T_EXTERN = 266,                /* "extern symbol declaration"  */
    T_ADDRESS = 267,               /* "address pseudo-operator"  */
    T_BYTE = 268,                  /* "byte pseudo-operator"  */
    T_WORD = 269,                  /* "word pseudo-operator"  */
    T_LONG = 270,                  /* "long pseudo-operator"  */
    T_QUAD = 271,                  /* "quad pseudo-operator"  */
    T_FLOAT = 272,                 /* "float pseudo-operator"  */
    T_DOUBLE = 273,                /* "double pseudo-operator"  */
    T_UNICODE = 274,               /* "unicode pseudo-operator"  */
    T_ADD = 275,                   /* "add instruction"  */
    T_ALLOCA = 276,                /* "stack allocation instruction"  */
    T_CCALL = 277,                 /* "native call instruction"  */
    T_DELLOC = 278,                /* "heap deallocation instruction"  */
    T_DIV = 279,                   /* "div instruction"  */
    T_DUP = 280,                   /* "dup instruction"  */
    T_INVOKE = 281,                /* "call instruction"  */
    T_JF = 282,                    /* "jump-if-false instruction"  */
    T_JUMP = 283,                  /* "jump instruction"  */
    T_JT = 284,                    /* "jump-if-true instruction"  */
    T_LOAD = 285,                  /* "load instruction"  */
    T_ILOAD = 286,                 /* "load-by-index instruction"  */
    T_MALLOC = 287,                /* "heap allocation instruction"  */
    T_MOD = 288,                   /* "mod instruction"  */
    T_MUL = 289,                   /* "mul instruction"  */
    T_POP = 290,                   /* "pop instruction"  */
    T_PUSH = 291,                  /* "push instruction"  */
    T_RET = 292,                   /* "return instruction"  */
    T_SLOAD = 293,                 /* "stack memory load instruction"  */
    T_SUB = 294,                   /* "sub instruction"  */
    T_STORE = 295,                 /* "store instruction"  */
    T_SSTORE = 296,                /* "stack write instruction"  */
    T_B2W = 297,                   /* "byte-to-word instruction"  */
    T_B2L = 298,                   /* B2L  */
    T_B2Q = 299,                   /* B2Q  */
    T_B2F = 300,                   /* B2F  */
    T_B2D = 301,                   /* B2D  */
    T_W2L = 302,                   /* W2L  */
    T_W2Q = 303,                   /* "word-to-quad instruction"  */
    T_W2F = 304,                   /* W2F  */
    T_W2D = 305,                   /* W2D  */
    T_L2Q = 306,                   /* L2Q  */
    T_L2F = 307,                   /* L2F  */
    T_L2D = 308,                   /* L2D  */
    T_Q2F = 309,                   /* Q2F  */
    T_Q2D = 310,                   /* Q2D  */
    T_CEQ = 311,                   /* "compare-equals instruction"  */
    T_CNE = 312,                   /* "compare-non-equals instruction"  */
    T_CGT = 313,                   /* "compare-greater instruction"  */
    T_CLT = 314,                   /* "compare-lesser instruction"  */
    T_CGE = 315,                   /* "compare-greater-equals instruction"  */
    T_CLE = 316,                   /* "compare-lesser-equals instruction"  */
    T_IDENTIFIER = 317,            /* "identifier"  */
    T_INSTRUCTION_SUFFIX = 318,    /* "instruction suffix"  */
    T_STRING_LITERAL = 319,        /* "string literal"  */
    T_INTEGER_LITERAL = 320,       /* "integer literal"  */
    T_FP_LITERAL = 321,            /* "floating point literal"  */
    T_ADDRESS_CONSTANT = 322       /* "address constant"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 118 "specs/parser.y"

    amanda::core::String*                           string;
    unsigned char                                   character;
    unsigned long long                              integer;
    long double                                     fp_number;
    std::vector<amanda::binutils::Instruction*>*    instruction_list;
    amanda::binutils::Instruction*                  insn;
    amanda::binutils::Operand*                      operand;

#line 141 "assembler/AssemblerParser-Inc.h"

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
#line 86 "specs/parser.y"

    // Include the corresponding definitions
    #include <amanda-vm/TypeSystem.h>
    #include <amanda-vm/Binutils/package.hxx>

    // C++
    #include <vector>

#line 176 "assembler/AssemblerParser-Inc.h"

#endif /* !YY_YY_ASSEMBLER_ASSEMBLERPARSER_INC_H_INCLUDED  */
