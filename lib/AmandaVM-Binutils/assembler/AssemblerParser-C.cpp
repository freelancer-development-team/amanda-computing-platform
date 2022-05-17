/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "specs/parser.y"

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


#line 107 "assembler/AssemblerParser-C.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "AssemblerParser-Inc.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  S_YYEMPTY = -2,
  S_YYEOF = 0,                             /* "end of file"  */
  S_YYerror = 1,                           /* error  */
  S_YYUNDEF = 2,                           /* "invalid token"  */
  S_ATTRIBUTES = 3,                        /* "attribute directive"  */
  S_DEF = 4,                               /* "subroutine definition keyword"  */
  S_ENDEF = 5,                             /* "end of subroutine"  */
  S_SECTION = 6,                           /* "section directive"  */
  S_GLOBAL = 7,                            /* "global symbol declaration"  */
  S_LOCAL = 8,                             /* "local symbol declaration"  */
  S_WEAK = 9,                              /* "weak symbol declaration"  */
  S_NATIVE = 10,                           /* "native symbol declaration"  */
  S_EXTERN = 11,                           /* "extern symbol declaration"  */
  S_ADDRESS = 12,                          /* "address pseudo-operator"  */
  S_BYTE = 13,                             /* "byte pseudo-operator"  */
  S_WORD = 14,                             /* "word pseudo-operator"  */
  S_LONG = 15,                             /* "long pseudo-operator"  */
  S_QUAD = 16,                             /* "quad pseudo-operator"  */
  S_FLOAT = 17,                            /* "float pseudo-operator"  */
  S_DOUBLE = 18,                           /* "double pseudo-operator"  */
  S_UNICODE = 19,                          /* "unicode pseudo-operator"  */
  S_ADD = 20,                              /* "add instruction"  */
  S_ALLOC = 21,                            /* "allocation instruction"  */
  S_CCALL = 22,                            /* "native call instruction"  */
  S_DELLOC = 23,                           /* "deallocation instruction"  */
  S_DIV = 24,                              /* "div instruction"  */
  S_INVOKE = 25,                           /* "call instruction"  */
  S_JF = 26,                               /* "jump-if-false instruction"  */
  S_JUMP = 27,                             /* "jump instruction"  */
  S_JT = 28,                               /* "jump-if-true instruction"  */
  S_LOAD = 29,                             /* "load instruction"  */
  S_MOD = 30,                              /* "mod instruction"  */
  S_MUL = 31,                              /* "mul instruction"  */
  S_POP = 32,                              /* "pop instruction"  */
  S_PUSH = 33,                             /* "push instruction"  */
  S_RET = 34,                              /* "return instruction"  */
  S_SUB = 35,                              /* "sub instruction"  */
  S_STORE = 36,                            /* "store instruction"  */
  S_B2W = 37,                              /* "byte-to-word instruction"  */
  S_B2L = 38,                              /* B2L  */
  S_B2Q = 39,                              /* B2Q  */
  S_B2F = 40,                              /* B2F  */
  S_B2D = 41,                              /* B2D  */
  S_W2L = 42,                              /* W2L  */
  S_W2Q = 43,                              /* "word-to-quad instruction"  */
  S_W2F = 44,                              /* W2F  */
  S_W2D = 45,                              /* W2D  */
  S_L2Q = 46,                              /* L2Q  */
  S_L2F = 47,                              /* L2F  */
  S_L2D = 48,                              /* L2D  */
  S_Q2F = 49,                              /* Q2F  */
  S_Q2D = 50,                              /* Q2D  */
  S_CEQ = 51,                              /* "compare-equals instruction"  */
  S_CNE = 52,                              /* "compare-non-equals instruction"  */
  S_53_semicolon_delimiter_ = 53,          /* "semicolon delimiter"  */
  S_IDENTIFIER = 54,                       /* "identifier"  */
  S_INSTRUCTION_SUFFIX = 55,               /* "instruction suffix"  */
  S_STRING_LITERAL = 56,                   /* "string literal"  */
  S_INTEGER_LITERAL = 57,                  /* "integer literal"  */
  S_FP_LITERAL = 58,                       /* "floating point literal"  */
  S_ADDRESS_CONSTANT = 59,                 /* "address constant"  */
  S_60_ = 60,                              /* ':'  */
  S_61_ = 61,                              /* '['  */
  S_62_ = 62,                              /* ']'  */
  S_YYACCEPT = 63,                         /* $accept  */
  S_compilation_unit = 64,                 /* compilation_unit  */
  S_declarations = 65,                     /* declarations  */
  S_declaration = 66,                      /* declaration  */
  S_section_declaration = 67,              /* section_declaration  */
  S_function_declaration = 68,             /* function_declaration  */
  S_symbol_declaration = 69,               /* symbol_declaration  */
  S_native_symbol_declaration = 70,        /* native_symbol_declaration  */
  S_optional_attributes = 71,              /* optional_attributes  */
  S_attributes_declaration = 72,           /* attributes_declaration  */
  S_constant_declaration = 73,             /* constant_declaration  */
  S_instruction_sequence = 74,             /* instruction_sequence  */
  S_instruction = 75,                      /* instruction  */
  S_zeroed_instruction = 76,               /* zeroed_instruction  */
  S_unary_instruction = 77,                /* unary_instruction  */
  S_label_declaration = 78,                /* label_declaration  */
  S_argument = 79,                         /* argument  */
  S_branch_target = 80,                    /* branch_target  */
  S_address_constant = 81,                 /* address_constant  */
  S_delimiter = 82                         /* delimiter  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 41 "specs/parser.y"

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

#line 268 "assembler/AssemblerParser-C.cpp"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : S_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
      56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   221,   221,   225,   226,   230,   231,   232,   233,   234,
     239,   257,   286,   287,   288,   289,   296,   304,   305,   309,
     317,   318,   319,   320,   325,   326,   327,   331,   332,   333,
     337,   338,   339,   340,   341,   342,   343,   345,   346,   347,
     348,   349,   350,   354,   355,   356,   367,   368,   370,   372,
     374,   378,   382,   388,   395,   400,   401,   402,   403,   407,
     408,   412,   417,   418
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "attribute directive",
  "subroutine definition keyword", "end of subroutine",
  "section directive", "global symbol declaration",
  "local symbol declaration", "weak symbol declaration",
  "native symbol declaration", "extern symbol declaration",
  "address pseudo-operator", "byte pseudo-operator",
  "word pseudo-operator", "long pseudo-operator", "quad pseudo-operator",
  "float pseudo-operator", "double pseudo-operator",
  "unicode pseudo-operator", "add instruction", "allocation instruction",
  "native call instruction", "deallocation instruction", "div instruction",
  "call instruction", "jump-if-false instruction", "jump instruction",
  "jump-if-true instruction", "load instruction", "mod instruction",
  "mul instruction", "pop instruction", "push instruction",
  "return instruction", "sub instruction", "store instruction",
  "byte-to-word instruction", "B2L", "B2Q", "B2F", "B2D", "W2L",
  "word-to-quad instruction", "W2F", "W2D", "L2Q", "L2F", "L2D", "Q2F",
  "Q2D", "compare-equals instruction", "compare-non-equals instruction",
  "semicolon delimiter", "identifier", "instruction suffix",
  "string literal", "integer literal", "floating point literal",
  "address constant", "':'", "'['", "']'", "$accept", "compilation_unit",
  "declarations", "declaration", "section_declaration",
  "function_declaration", "symbol_declaration",
  "native_symbol_declaration", "optional_attributes",
  "attributes_declaration", "constant_declaration", "instruction_sequence",
  "instruction", "zeroed_instruction", "unary_instruction",
  "label_declaration", "argument", "branch_target", "address_constant",
  "delimiter", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    59,   308,   309,   310,   311,   312,   313,
      58,    91,    93
};
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      79,   -53,   -46,   -43,   -41,   -29,   -28,   -18,   -17,   -14,
     -13,     4,    61,    79,   -58,   -58,   -58,   -58,   -58,   -58,
      30,    67,    11,    14,    15,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,    22,    21,    25,    23,    37,    39,   -47,
     -19,   -47,    42,    44,    45,    46,    47,    48,   -58,   -58,
     -58,   -58,   -58,   -58,    49,    50,    51,    -5,   -58,    53,
      53,    53,    41,    53,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,    52,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -49,   -58,   -58,   -49,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,    53,   -58,    54,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     5,     6,     7,     8,     9,
      26,    18,     0,     0,     0,    16,    15,    20,    22,    23,
      21,     1,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,    38,
      39,    40,    41,    42,     0,     0,     0,     0,    24,    63,
      63,    63,     0,    63,    17,    12,    14,    13,    30,    50,
      43,    51,    33,    48,    60,     0,    46,    59,    45,    44,
      47,    52,    34,     0,    35,    36,     0,    31,    32,    54,
      11,    25,    62,    27,    28,    29,    63,    10,     0,    55,
      56,    57,    49,    58,    53,    19,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,    94,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,    55,   -58,   -58,   -58,    24,    72,   -38,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    16,    17,    18,    63,    64,
      19,    57,    58,    59,    60,    61,   102,    76,    77,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      90,    20,    79,    94,    95,    99,    97,    74,   100,   101,
      21,    22,    75,    23,    75,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    24,    25,    43,    44,    45,
      46,    47,    48,    49,    50,    78,    26,    51,    52,   105,
      27,    53,    75,    28,    29,   103,    54,    55,   103,    56,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      30,    31,    43,    44,    45,    46,    47,    48,    49,    50,
      62,    65,    51,    52,    66,    67,    53,    68,    69,    70,
      71,    54,    55,     1,    56,     2,     3,     4,     5,     6,
       7,     8,    72,    73,     9,    10,    81,    96,    11,    82,
      83,    84,    85,    86,    87,    88,    92,    32,     0,    98,
     104,    89,    91,    80,     0,     0,   106
};

static const yytype_int8 yycheck[] =
{
       5,    54,    40,    60,    61,    54,    63,    54,    57,    58,
      56,    54,    61,    54,    61,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    54,    54,    32,    33,    34,
      35,    36,    37,    38,    39,    54,    54,    42,    43,    96,
      57,    46,    61,    57,    57,    83,    51,    52,    86,    54,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      56,     0,    32,    33,    34,    35,    36,    37,    38,    39,
       3,    60,    42,    43,    60,    60,    46,    55,    57,    54,
      57,    51,    52,     4,    54,     6,     7,     8,     9,    10,
      11,    12,    55,    54,    15,    16,    54,    56,    19,    55,
      55,    55,    55,    55,    55,    55,    53,    13,    -1,    57,
      86,    60,    57,    41,    -1,    -1,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     6,     7,     8,     9,    10,    11,    12,    15,
      16,    19,    64,    65,    66,    67,    68,    69,    70,    73,
      54,    56,    54,    54,    54,    54,    54,    57,    57,    57,
      56,     0,    66,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    32,    33,    34,    35,    36,    37,    38,
      39,    42,    43,    46,    51,    52,    54,    74,    75,    76,
      77,    78,     3,    71,    72,    60,    60,    60,    55,    57,
      54,    57,    55,    54,    54,    61,    80,    81,    54,    81,
      80,    54,    55,    55,    55,    55,    55,    55,    55,    60,
       5,    75,    53,    82,    82,    82,    56,    82,    57,    54,
      57,    58,    79,    81,    79,    82,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    66,    66,
      67,    68,    69,    69,    69,    69,    70,    71,    71,    72,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    79,    79,    79,    80,
      80,    81,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       4,     4,     3,     3,     3,     2,     2,     1,     0,     3,
       2,     2,     2,     2,     1,     2,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     3,
       2,     2,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = T_YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == T_YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, scanner, module, state, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use T_YYerror or T_YYUNDEF. */
#define YYERRCODE T_YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner, module, state); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* scanner, void** module, void* state)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (module);
  YY_USE (state);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* scanner, void** module, void* state)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner, module, state);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, void* scanner, void** module, void* state)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner, module, state);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, module, state); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          goto yyexhaustedlab;                                          \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == S_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != S_YYerror && yysym != S_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = S_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != S_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void* scanner, void** module, void* state)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (module);
  YY_USE (state);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case S_IDENTIFIER: /* "identifier"  */
#line 130 "specs/parser.y"
            { ((*yyvaluep).string)->release(); }
#line 1585 "assembler/AssemblerParser-C.cpp"
        break;

    case S_STRING_LITERAL: /* "string literal"  */
#line 130 "specs/parser.y"
            { ((*yyvaluep).string)->release(); }
#line 1591 "assembler/AssemblerParser-C.cpp"
        break;

    case S_instruction_sequence: /* instruction_sequence  */
#line 131 "specs/parser.y"
            { delete (((*yyvaluep).instruction_list));   }
#line 1597 "assembler/AssemblerParser-C.cpp"
        break;

    case S_instruction: /* instruction  */
#line 128 "specs/parser.y"
            { ((*yyvaluep).insn)->release(); }
#line 1603 "assembler/AssemblerParser-C.cpp"
        break;

    case S_zeroed_instruction: /* zeroed_instruction  */
#line 128 "specs/parser.y"
            { ((*yyvaluep).insn)->release(); }
#line 1609 "assembler/AssemblerParser-C.cpp"
        break;

    case S_unary_instruction: /* unary_instruction  */
#line 128 "specs/parser.y"
            { ((*yyvaluep).insn)->release(); }
#line 1615 "assembler/AssemblerParser-C.cpp"
        break;

    case S_label_declaration: /* label_declaration  */
#line 128 "specs/parser.y"
            { ((*yyvaluep).insn)->release(); }
#line 1621 "assembler/AssemblerParser-C.cpp"
        break;

    case S_argument: /* argument  */
#line 129 "specs/parser.y"
            { ((*yyvaluep).operand)->release(); }
#line 1627 "assembler/AssemblerParser-C.cpp"
        break;

    case S_branch_target: /* branch_target  */
#line 129 "specs/parser.y"
            { ((*yyvaluep).operand)->release(); }
#line 1633 "assembler/AssemblerParser-C.cpp"
        break;

    case S_address_constant: /* address_constant  */
#line 129 "specs/parser.y"
            { ((*yyvaluep).operand)->release(); }
#line 1639 "assembler/AssemblerParser-C.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void* scanner, void** module, void* state)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = S_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = T_YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == T_YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= T_YYEOF)
    {
      yychar = T_YYEOF;
      yytoken = S_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == T_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = T_YYUNDEF;
      yytoken = S_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = T_YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 7: /* declaration: symbol_declaration  */
#line 232 "specs/parser.y"
                                                { MODULE(*module)->addSymbol(*(STATE(state)->currentObject), *(STATE(state)->currentSection)); }
#line 1956 "assembler/AssemblerParser-C.cpp"
    break;

  case 10: /* section_declaration: "section directive" "string literal" optional_attributes delimiter  */
#line 240 "specs/parser.y"
                                                {
                                                    // Create a new section object
                                                    core::String sectionName((yyvsp[-2].string)->toCharArray());
                                                    Section* section = new Section(sectionName);

                                                    // Add the section to the module
                                                    MODULE(*module)->addSection(section);

                                                    // Set the section as the current section
                                                    STATE(state)->currentSection = MODULE(*module)->getSection(sectionName);

                                                    // Clean up
                                                    delete (yyvsp[-2].string);
                                                }
#line 1975 "assembler/AssemblerParser-C.cpp"
    break;

  case 11: /* function_declaration: "subroutine definition keyword" "identifier" instruction_sequence "end of subroutine"  */
#line 258 "specs/parser.y"
                                                {
                                                    // Create a new function object
                                                    Function* function = new Function(*(yyvsp[-2].string));

                                                    // Emit bytecode for that function
                                                    for (size_t i = 0; i < (yyvsp[-1].instruction_list)->size(); ++i)
                                                    {
                                                        function->emit((yyvsp[-1].instruction_list)->at(i));
                                                    }

                                                    // Add it to the current section & module
                                                    Section* cs = STATE(state)->currentSection;
                                                    Module* mod = MODULE(*module);

                                                    assert(cs != NULL && "current section is NULL?");
                                                    assert(mod != NULL && "module is NULL?");

                                                    mod->addSymbol(*function, *cs);

                                                    // Clean up
                                                    delete (yyvsp[-2].string);
                                                    delete (yyvsp[-1].instruction_list);

                                                    // Reset the offset
                                                    STATE(state)->localOffset = 0;
                                                }
#line 2006 "assembler/AssemblerParser-C.cpp"
    break;

  case 12: /* symbol_declaration: "global symbol declaration" "identifier" ':'  */
#line 286 "specs/parser.y"
                            { STATE(state)->currentObject = new DataObject(*(yyvsp[-1].string), Symbol::Bind_Global); delete (yyvsp[-1].string); }
#line 2012 "assembler/AssemblerParser-C.cpp"
    break;

  case 13: /* symbol_declaration: "weak symbol declaration" "identifier" ':'  */
#line 287 "specs/parser.y"
                            { STATE(state)->currentObject = new DataObject(*(yyvsp[-1].string), Symbol::Bind_Weak); delete (yyvsp[-1].string); }
#line 2018 "assembler/AssemblerParser-C.cpp"
    break;

  case 14: /* symbol_declaration: "local symbol declaration" "identifier" ':'  */
#line 288 "specs/parser.y"
                            { STATE(state)->currentObject = new DataObject(*(yyvsp[-1].string), Symbol::Bind_Local); delete (yyvsp[-1].string); }
#line 2024 "assembler/AssemblerParser-C.cpp"
    break;

  case 15: /* symbol_declaration: "extern symbol declaration" "identifier"  */
#line 289 "specs/parser.y"
                            {
                                DataObject* externSymbol = new DataObject(*(yyvsp[0].string), Symbol::Bind_Extern); delete (yyvsp[0].string);
                                MODULE(*module)->addSymbol(*externSymbol, *(STATE(state)->currentSection));
                            }
#line 2033 "assembler/AssemblerParser-C.cpp"
    break;

  case 16: /* native_symbol_declaration: "native symbol declaration" "identifier"  */
#line 296 "specs/parser.y"
                            {
                                DataObject* nativeSymbol = new DataObject(*(yyvsp[0].string), Symbol::Bind_Native); delete (yyvsp[0].string);
                                MODULE(*module)->addSymbol(*nativeSymbol, *(STATE(state)->currentSection));
                            }
#line 2042 "assembler/AssemblerParser-C.cpp"
    break;

  case 19: /* attributes_declaration: "attribute directive" "string literal" delimiter  */
#line 310 "specs/parser.y"
                                                {
                                                    // Clean up
                                                    delete (yyvsp[-1].string);
                                                }
#line 2051 "assembler/AssemblerParser-C.cpp"
    break;

  case 20: /* constant_declaration: "address pseudo-operator" "integer literal"  */
#line 317 "specs/parser.y"
                                            { STATE(state)->currentObject->addData(&((yyvsp[0].integer)), VM_ADDRESS_SIZE);  }
#line 2057 "assembler/AssemblerParser-C.cpp"
    break;

  case 21: /* constant_declaration: "unicode pseudo-operator" "string literal"  */
#line 318 "specs/parser.y"
                                            { STATE(state)->currentObject->addUtf8Data((yyvsp[0].string)->toCharArray(), (yyvsp[0].string)->length()); }
#line 2063 "assembler/AssemblerParser-C.cpp"
    break;

  case 22: /* constant_declaration: "long pseudo-operator" "integer literal"  */
#line 319 "specs/parser.y"
                                            { STATE(state)->currentObject->addData(&((yyvsp[0].integer)), VM_DWORD_SIZE); }
#line 2069 "assembler/AssemblerParser-C.cpp"
    break;

  case 23: /* constant_declaration: "quad pseudo-operator" "integer literal"  */
#line 320 "specs/parser.y"
                                            { STATE(state)->currentObject->addData(&((yyvsp[0].integer)), VM_QWORD_SIZE); }
#line 2075 "assembler/AssemblerParser-C.cpp"
    break;

  case 24: /* instruction_sequence: instruction  */
#line 325 "specs/parser.y"
                                            { (yyval.instruction_list) = new std::vector<amanda::binutils::Instruction*>(); (yyval.instruction_list)->push_back((yyvsp[0].insn)); if (!((yyvsp[0].insn)->is<Label>())) STATE(state)->localOffset++; }
#line 2081 "assembler/AssemblerParser-C.cpp"
    break;

  case 25: /* instruction_sequence: instruction_sequence instruction  */
#line 326 "specs/parser.y"
                                            { (yyval.instruction_list) = (yyvsp[-1].instruction_list); (yyval.instruction_list)->push_back((yyvsp[0].insn)); if (!((yyvsp[0].insn)->is<Label>())) STATE(state)->localOffset++; }
#line 2087 "assembler/AssemblerParser-C.cpp"
    break;

  case 26: /* instruction_sequence: %empty  */
#line 327 "specs/parser.y"
                                            { (yyval.instruction_list) = new std::vector<amanda::binutils::Instruction*>(); }
#line 2093 "assembler/AssemblerParser-C.cpp"
    break;

  case 30: /* zeroed_instruction: "add instruction" "instruction suffix"  */
#line 337 "specs/parser.y"
                                            { (yyval.insn) = new Instruction(AMANDA_VM_INSN_FAMILY(ADD) + Instruction::getInstructionNumericSuffix((yyvsp[0].character)), 0); }
#line 2099 "assembler/AssemblerParser-C.cpp"
    break;

  case 31: /* zeroed_instruction: "compare-equals instruction" "instruction suffix"  */
#line 338 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(CEQ), (yyvsp[0].character)); }
#line 2105 "assembler/AssemblerParser-C.cpp"
    break;

  case 32: /* zeroed_instruction: "compare-non-equals instruction" "instruction suffix"  */
#line 339 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(CNE), (yyvsp[0].character)); }
#line 2111 "assembler/AssemblerParser-C.cpp"
    break;

  case 33: /* zeroed_instruction: "div instruction" "instruction suffix"  */
#line 340 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(DIV), (yyvsp[0].character)); }
#line 2117 "assembler/AssemblerParser-C.cpp"
    break;

  case 34: /* zeroed_instruction: "pop instruction" "instruction suffix"  */
#line 341 "specs/parser.y"
                                            { (yyval.insn) = new Instruction(AMANDA_VM_INSN_FAMILY(POP) + Instruction::getInstructionNumericSuffix((yyvsp[0].character)), 0); }
#line 2123 "assembler/AssemblerParser-C.cpp"
    break;

  case 35: /* zeroed_instruction: "return instruction" "instruction suffix"  */
#line 342 "specs/parser.y"
                                            { (yyval.insn) = new Instruction(AMANDA_VM_INSN_FAMILY(RET) + Instruction::getInstructionNumericSuffix((yyvsp[0].character)), 0); }
#line 2129 "assembler/AssemblerParser-C.cpp"
    break;

  case 36: /* zeroed_instruction: "sub instruction" "instruction suffix"  */
#line 343 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpInstruction(AMANDA_VM_INSN_FAMILY(SUB), (yyvsp[0].character)); }
#line 2135 "assembler/AssemblerParser-C.cpp"
    break;

  case 37: /* zeroed_instruction: "byte-to-word instruction"  */
#line 345 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(B2W)); }
#line 2141 "assembler/AssemblerParser-C.cpp"
    break;

  case 38: /* zeroed_instruction: B2L  */
#line 346 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(B2L)); }
#line 2147 "assembler/AssemblerParser-C.cpp"
    break;

  case 39: /* zeroed_instruction: B2Q  */
#line 347 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(B2Q)); }
#line 2153 "assembler/AssemblerParser-C.cpp"
    break;

  case 40: /* zeroed_instruction: W2L  */
#line 348 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(W2L)); }
#line 2159 "assembler/AssemblerParser-C.cpp"
    break;

  case 41: /* zeroed_instruction: "word-to-quad instruction"  */
#line 349 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(W2Q)); }
#line 2165 "assembler/AssemblerParser-C.cpp"
    break;

  case 42: /* zeroed_instruction: L2Q  */
#line 350 "specs/parser.y"
                                            { (yyval.insn) = as::createZeroOpNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(L2Q)); }
#line 2171 "assembler/AssemblerParser-C.cpp"
    break;

  case 43: /* unary_instruction: "native call instruction" "identifier"  */
#line 354 "specs/parser.y"
                                            { (yyval.insn) = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(CCALL)); Operand* operand = new Operand(*(yyvsp[0].string)); (yyval.insn)->setOperand(operand); delete (yyvsp[0].string); }
#line 2177 "assembler/AssemblerParser-C.cpp"
    break;

  case 44: /* unary_instruction: "jump instruction" address_constant  */
#line 355 "specs/parser.y"
                                            { (yyval.insn) = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(JMP)); (yyval.insn)->setOperand((yyvsp[0].operand)); }
#line 2183 "assembler/AssemblerParser-C.cpp"
    break;

  case 45: /* unary_instruction: "jump instruction" "identifier"  */
#line 356 "specs/parser.y"
                                            {
                                                (yyval.insn) = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(JMP));

                                                // Allocate the operand
                                                Operand* operand = new Operand(*(yyvsp[0].string));
                                                (yyval.insn)->setOperand(operand);

                                                // Clean up
                                                delete (yyvsp[0].string);
                                            }
#line 2198 "assembler/AssemblerParser-C.cpp"
    break;

  case 46: /* unary_instruction: "jump-if-false instruction" branch_target  */
#line 367 "specs/parser.y"
                                            { (yyval.insn) = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(JF)); (yyval.insn)->setOperand((yyvsp[0].operand)); }
#line 2204 "assembler/AssemblerParser-C.cpp"
    break;

  case 47: /* unary_instruction: "jump-if-true instruction" branch_target  */
#line 368 "specs/parser.y"
                                            { (yyval.insn) = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(JT)); (yyval.insn)->setOperand((yyvsp[0].operand)); }
#line 2210 "assembler/AssemblerParser-C.cpp"
    break;

  case 48: /* unary_instruction: "call instruction" "identifier"  */
#line 370 "specs/parser.y"
                                            { (yyval.insn) = as::createBranchInstruction(AMANDA_VM_INSN_SINGLE(INVOKE)); Operand* operand = new Operand(*(yyvsp[0].string)); (yyval.insn)->setOperand(operand); delete (yyvsp[0].string);}
#line 2216 "assembler/AssemblerParser-C.cpp"
    break;

  case 49: /* unary_instruction: "push instruction" "instruction suffix" argument  */
#line 372 "specs/parser.y"
                                            { (yyval.insn) = as::createUnaryInstruction(AMANDA_VM_INSN_FAMILY(PUSH), (yyvsp[-1].character)); (yyval.insn)->setOperand((yyvsp[0].operand)); }
#line 2222 "assembler/AssemblerParser-C.cpp"
    break;

  case 50: /* unary_instruction: "allocation instruction" "integer literal"  */
#line 374 "specs/parser.y"
                                            {
                                                (yyval.insn) = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(ALLOC), VM_QWORD_SIZE);
                                                Operand* operand = new Operand((yyvsp[0].integer)); (yyval.insn)->setOperand(operand);
                                            }
#line 2231 "assembler/AssemblerParser-C.cpp"
    break;

  case 51: /* unary_instruction: "deallocation instruction" "integer literal"  */
#line 378 "specs/parser.y"
                                            {
                                                (yyval.insn) = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(DELLOC), VM_QWORD_SIZE);
                                                Operand* operand = new Operand((yyvsp[0].integer)); (yyval.insn)->setOperand(operand);
                                            }
#line 2240 "assembler/AssemblerParser-C.cpp"
    break;

  case 52: /* unary_instruction: "load instruction" "identifier"  */
#line 382 "specs/parser.y"
                                            {
                                                (yyval.insn) = as::createUnaryNoSuffixInstruction(AMANDA_VM_INSN_SINGLE(LOAD), VM_ADDRESS_SIZE);

                                                Operand* operand = new Operand(*(yyvsp[0].string)); (yyval.insn)->setOperand(operand);
                                                delete (yyvsp[0].string);
                                            }
#line 2251 "assembler/AssemblerParser-C.cpp"
    break;

  case 53: /* unary_instruction: "store instruction" "instruction suffix" argument  */
#line 388 "specs/parser.y"
                                            {
                                                (yyval.insn) = as::createUnaryInstruction(AMANDA_VM_INSN_FAMILY(STORE), (yyvsp[-1].character));
                                                (yyval.insn)->setOperand((yyvsp[0].operand)); 
                                            }
#line 2260 "assembler/AssemblerParser-C.cpp"
    break;

  case 54: /* label_declaration: "identifier" ':'  */
#line 395 "specs/parser.y"
                                            { (yyval.insn) = new Label(*(yyvsp[-1].string), STATE(state)->localOffset); delete (yyvsp[-1].string); }
#line 2266 "assembler/AssemblerParser-C.cpp"
    break;

  case 55: /* argument: "identifier"  */
#line 400 "specs/parser.y"
                                            { (yyval.operand) = new Operand(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 2272 "assembler/AssemblerParser-C.cpp"
    break;

  case 56: /* argument: "integer literal"  */
#line 401 "specs/parser.y"
                                            { (yyval.operand) = new Operand((yyvsp[0].integer)); }
#line 2278 "assembler/AssemblerParser-C.cpp"
    break;

  case 57: /* argument: "floating point literal"  */
#line 402 "specs/parser.y"
                                            { (yyval.operand) = NULL; }
#line 2284 "assembler/AssemblerParser-C.cpp"
    break;

  case 60: /* branch_target: "identifier"  */
#line 408 "specs/parser.y"
                                            { (yyval.operand) = new Operand(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 2290 "assembler/AssemblerParser-C.cpp"
    break;

  case 61: /* address_constant: '[' "integer literal" ']'  */
#line 412 "specs/parser.y"
                                            { (yyval.operand) = new Operand((yyvsp[-1].integer), VM_QWORD_SIZE); }
#line 2296 "assembler/AssemblerParser-C.cpp"
    break;


#line 2300 "assembler/AssemblerParser-C.cpp"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == T_YYEMPTY ? S_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != T_YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, scanner, module, state, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner, module, state);
          yychar = T_YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += S_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == S_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner, module, state);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, module, state, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != T_YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, module, state);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner, module, state);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 421 "specs/parser.y"


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
