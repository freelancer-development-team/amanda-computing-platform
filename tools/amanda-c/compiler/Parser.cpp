// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "specs/grammar.y"

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


#line 83 "compiler/Parser.cpp"


#include "Parser.h"


// Unqualified %code blocks.
#line 94 "specs/grammar.y"


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

#line 112 "compiler/Parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 53 "specs/grammar.y"
namespace amanda { namespace compiler {
#line 205 "compiler/Parser.cpp"

  /// Build a parser object.
  DefaultParser::DefaultParser (amanda::compiler::CompilationContext& compiler_yyarg, amanda::compiler::Scanner& lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      compiler (compiler_yyarg),
      lexer (lexer_yyarg)
  {}

  DefaultParser::~DefaultParser ()
  {}

  DefaultParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  DefaultParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  DefaultParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  DefaultParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  DefaultParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  DefaultParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  DefaultParser::symbol_kind_type
  DefaultParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  DefaultParser::stack_symbol_type::stack_symbol_type ()
  {}

  DefaultParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression_list: // expression_list
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::ExpressionList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NBinaryOperator* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NCompilationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NConditionalStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NDeclarationBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NExpressionStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NFunctionCall* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NFunctionDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NIdentifier* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NNamespaceDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return_statement: // return_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NReturnStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NUsingDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.YY_MOVE_OR_COPY< amanda::core::String > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  DefaultParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression_list: // expression_list
        value.move< amanda::compiler::ast::ExpressionList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.move< amanda::compiler::ast::NBinaryOperator* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.move< amanda::compiler::ast::NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.move< amanda::compiler::ast::NCompilationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< amanda::compiler::ast::NConditionalStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< amanda::compiler::ast::NDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< amanda::compiler::ast::NDeclarationBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.move< amanda::compiler::ast::NExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.move< amanda::compiler::ast::NExpressionStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< amanda::compiler::ast::NFunctionCall* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.move< amanda::compiler::ast::NFunctionDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.move< amanda::compiler::ast::NIdentifier* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        value.move< amanda::compiler::ast::NNamespaceDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return_statement: // return_statement
        value.move< amanda::compiler::ast::NReturnStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< amanda::compiler::ast::NStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.move< amanda::compiler::ast::NUsingDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.move< amanda::compiler::ast::NWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< amanda::core::String > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  DefaultParser::stack_symbol_type&
  DefaultParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression_list: // expression_list
        value.copy< amanda::compiler::ast::ExpressionList* > (that.value);
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.copy< amanda::compiler::ast::NBinaryOperator* > (that.value);
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.copy< amanda::compiler::ast::NBlock* > (that.value);
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.copy< amanda::compiler::ast::NCompilationUnit* > (that.value);
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.copy< amanda::compiler::ast::NConditionalStatement* > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< amanda::compiler::ast::NDeclaration* > (that.value);
        break;

      case symbol_kind::S_declarations: // declarations
        value.copy< amanda::compiler::ast::NDeclarationBlock* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.copy< amanda::compiler::ast::NExpression* > (that.value);
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.copy< amanda::compiler::ast::NExpressionStatement* > (that.value);
        break;

      case symbol_kind::S_function_call: // function_call
        value.copy< amanda::compiler::ast::NFunctionCall* > (that.value);
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.copy< amanda::compiler::ast::NFunctionDeclaration* > (that.value);
        break;

      case symbol_kind::S_id: // id
        value.copy< amanda::compiler::ast::NIdentifier* > (that.value);
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        value.copy< amanda::compiler::ast::NNamespaceDeclaration* > (that.value);
        break;

      case symbol_kind::S_return_statement: // return_statement
        value.copy< amanda::compiler::ast::NReturnStatement* > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.copy< amanda::compiler::ast::NStatement* > (that.value);
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.copy< amanda::compiler::ast::NUsingDeclaration* > (that.value);
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.copy< amanda::compiler::ast::NWhileStatement* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.copy< amanda::core::String > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  DefaultParser::stack_symbol_type&
  DefaultParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression_list: // expression_list
        value.move< amanda::compiler::ast::ExpressionList* > (that.value);
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.move< amanda::compiler::ast::NBinaryOperator* > (that.value);
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.move< amanda::compiler::ast::NBlock* > (that.value);
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.move< amanda::compiler::ast::NCompilationUnit* > (that.value);
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< amanda::compiler::ast::NConditionalStatement* > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< amanda::compiler::ast::NDeclaration* > (that.value);
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< amanda::compiler::ast::NDeclarationBlock* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.move< amanda::compiler::ast::NExpression* > (that.value);
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.move< amanda::compiler::ast::NExpressionStatement* > (that.value);
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< amanda::compiler::ast::NFunctionCall* > (that.value);
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.move< amanda::compiler::ast::NFunctionDeclaration* > (that.value);
        break;

      case symbol_kind::S_id: // id
        value.move< amanda::compiler::ast::NIdentifier* > (that.value);
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        value.move< amanda::compiler::ast::NNamespaceDeclaration* > (that.value);
        break;

      case symbol_kind::S_return_statement: // return_statement
        value.move< amanda::compiler::ast::NReturnStatement* > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< amanda::compiler::ast::NStatement* > (that.value);
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.move< amanda::compiler::ast::NUsingDeclaration* > (that.value);
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.move< amanda::compiler::ast::NWhileStatement* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< amanda::core::String > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  DefaultParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  DefaultParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  DefaultParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  DefaultParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  DefaultParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  DefaultParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  DefaultParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  DefaultParser::debug_level_type
  DefaultParser::debug_level () const
  {
    return yydebug_;
  }

  void
  DefaultParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  DefaultParser::state_type
  DefaultParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  DefaultParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  DefaultParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  DefaultParser::operator() ()
  {
    return parse ();
  }

  int
  DefaultParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    /// Discard the LAC context in case there still is one left from a
    /// previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
           goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
           goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expression_list: // expression_list
        yylhs.value.emplace< amanda::compiler::ast::ExpressionList* > ();
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        yylhs.value.emplace< amanda::compiler::ast::NBinaryOperator* > ();
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        yylhs.value.emplace< amanda::compiler::ast::NBlock* > ();
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        yylhs.value.emplace< amanda::compiler::ast::NCompilationUnit* > ();
        break;

      case symbol_kind::S_if_statement: // if_statement
        yylhs.value.emplace< amanda::compiler::ast::NConditionalStatement* > ();
        break;

      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< amanda::compiler::ast::NDeclaration* > ();
        break;

      case symbol_kind::S_declarations: // declarations
        yylhs.value.emplace< amanda::compiler::ast::NDeclarationBlock* > ();
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        yylhs.value.emplace< amanda::compiler::ast::NExpression* > ();
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        yylhs.value.emplace< amanda::compiler::ast::NExpressionStatement* > ();
        break;

      case symbol_kind::S_function_call: // function_call
        yylhs.value.emplace< amanda::compiler::ast::NFunctionCall* > ();
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        yylhs.value.emplace< amanda::compiler::ast::NFunctionDeclaration* > ();
        break;

      case symbol_kind::S_id: // id
        yylhs.value.emplace< amanda::compiler::ast::NIdentifier* > ();
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        yylhs.value.emplace< amanda::compiler::ast::NNamespaceDeclaration* > ();
        break;

      case symbol_kind::S_return_statement: // return_statement
        yylhs.value.emplace< amanda::compiler::ast::NReturnStatement* > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        yylhs.value.emplace< amanda::compiler::ast::NStatement* > ();
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        yylhs.value.emplace< amanda::compiler::ast::NUsingDeclaration* > ();
        break;

      case symbol_kind::S_while_statement: // while_statement
        yylhs.value.emplace< amanda::compiler::ast::NWhileStatement* > ();
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        yylhs.value.emplace< amanda::core::String > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // compilation_unit: declarations
#line 234 "specs/grammar.y"
                    {
                        NCompilationUnit* unit = new NCompilationUnit(lexer.filename.c_str());
                        assert(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > () != NULL && "Null pointer exception.");

                        unit->addDeclarations(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > ());

                        // Set the parse tree to the compiler.
                        compiler.setAbstractSyntaxTree(unit);

                        // Assign the semmantic value to the accept rule
                        yylhs.value.as < amanda::compiler::ast::NCompilationUnit* > () = unit;
                    }
#line 1017 "compiler/Parser.cpp"
    break;

  case 3: // declarations: %empty
#line 250 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = new NDeclarationBlock(); }
#line 1023 "compiler/Parser.cpp"
    break;

  case 4: // declarations: declaration
#line 251 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = new NDeclarationBlock(); yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > ()->addDeclaration(yystack_[0].value.as < amanda::compiler::ast::NDeclaration* > ()); }
#line 1029 "compiler/Parser.cpp"
    break;

  case 5: // declarations: declarations declaration
#line 252 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = yystack_[1].value.as < amanda::compiler::ast::NDeclarationBlock* > (); yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > ()->addDeclaration(yystack_[0].value.as < amanda::compiler::ast::NDeclaration* > ()); }
#line 1035 "compiler/Parser.cpp"
    break;

  case 6: // declaration: namespace_declaration
#line 256 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NNamespaceDeclaration* > (); }
#line 1041 "compiler/Parser.cpp"
    break;

  case 7: // declaration: using_declaration
#line 257 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NUsingDeclaration* > (); }
#line 1047 "compiler/Parser.cpp"
    break;

  case 8: // declaration: function_declaration
#line 258 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NFunctionDeclaration* > (); }
#line 1053 "compiler/Parser.cpp"
    break;

  case 9: // namespace_declaration: "namespace" "identifier" '{' declarations '}'
#line 262 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > () = new NNamespaceDeclaration(yystack_[3].value.as < amanda::core::String > ()); yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > ()->addDeclarations(yystack_[1].value.as < amanda::compiler::ast::NDeclarationBlock* > ()); }
#line 1059 "compiler/Parser.cpp"
    break;

  case 10: // namespace_declaration: "namespace" name ';' declarations
#line 263 "specs/grammar.y"
                                                {
                                                    // This is gonna be the last generated namespace when
                                                    // we call the function
                                                    NNamespaceDeclaration* last = NULL;
                                                    NNamespaceDeclaration* parent = buildNamespacesByQualifiedName(yystack_[2].value.as < amanda::core::String > (), last);

                                                    assert(last != NULL && "Null pointer exception");
                                                    assert(parent != NULL && "Null pointer exception");

                                                    yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > () = parent; last->addDeclarations(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > ());
                                                }
#line 1075 "compiler/Parser.cpp"
    break;

  case 11: // using_declaration: "using" name ';'
#line 277 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NUsingDeclaration* > () = new NUsingDeclaration(yystack_[1].value.as < amanda::core::String > ()); }
#line 1081 "compiler/Parser.cpp"
    break;

  case 12: // function_declaration: type "identifier" '(' argument_list ')' '{' statement_sequence '}'
#line 281 "specs/grammar.y"
                                                                       { yylhs.value.as < amanda::compiler::ast::NFunctionDeclaration* > () = new NFunctionDeclaration(yystack_[6].value.as < amanda::core::String > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()); }
#line 1087 "compiler/Parser.cpp"
    break;

  case 13: // statement: simple_statement ';'
#line 286 "specs/grammar.y"
      { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[1].value.as < amanda::compiler::ast::NStatement* > (); }
#line 1093 "compiler/Parser.cpp"
    break;

  case 14: // statement: compound_statement
#line 287 "specs/grammar.y"
      { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NStatement* > (); }
#line 1099 "compiler/Parser.cpp"
    break;

  case 15: // simple_statement: return_statement
#line 291 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NReturnStatement* > (); }
#line 1105 "compiler/Parser.cpp"
    break;

  case 16: // simple_statement: expression_statement
#line 292 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NExpressionStatement* > (); }
#line 1111 "compiler/Parser.cpp"
    break;

  case 17: // compound_statement: if_statement
#line 296 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NConditionalStatement* > (); }
#line 1117 "compiler/Parser.cpp"
    break;

  case 18: // compound_statement: while_statement
#line 297 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NWhileStatement* > (); }
#line 1123 "compiler/Parser.cpp"
    break;

  case 19: // expression_statement: function_call
#line 303 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[0].value.as < amanda::compiler::ast::NFunctionCall* > ()); }
#line 1129 "compiler/Parser.cpp"
    break;

  case 20: // return_statement: "return" expression
#line 308 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NReturnStatement* > () = new NReturnStatement(); }
#line 1135 "compiler/Parser.cpp"
    break;

  case 21: // return_statement: "return"
#line 309 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NReturnStatement* > () = new NReturnStatement(); }
#line 1141 "compiler/Parser.cpp"
    break;

  case 22: // if_statement: "if" '(' expression ')' '{' statement_sequence '}'
#line 315 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                        }
#line 1149 "compiler/Parser.cpp"
    break;

  case 23: // if_statement: "if" '(' expression ')' '{' statement_sequence '}' "else" '{' statement_sequence '}'
#line 320 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[8].value.as < amanda::compiler::ast::NExpression* > (), yystack_[5].value.as < amanda::compiler::ast::NBlock* > ()); yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addElseClause(yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()); 
                                                        }
#line 1157 "compiler/Parser.cpp"
    break;

  case 24: // while_statement: "while" '(' expression ')' '{' statement_sequence '}'
#line 327 "specs/grammar.y"
                                                {
                                                    yylhs.value.as < amanda::compiler::ast::NWhileStatement* > () = new NWhileStatement(yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                }
#line 1165 "compiler/Parser.cpp"
    break;

  case 25: // expression: id
#line 334 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NIdentifier* > (); }
#line 1171 "compiler/Parser.cpp"
    break;

  case 26: // expression: numeric_literal
#line 335 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NExpression* > (); }
#line 1177 "compiler/Parser.cpp"
    break;

  case 27: // expression: function_call
#line 336 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NFunctionCall* > (); }
#line 1183 "compiler/Parser.cpp"
    break;

  case 28: // expression: binary_operator
#line 337 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NBinaryOperator* > (); }
#line 1189 "compiler/Parser.cpp"
    break;

  case 29: // expression: '(' expression ')'
#line 338 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[1].value.as < amanda::compiler::ast::NExpression* > (); }
#line 1195 "compiler/Parser.cpp"
    break;

  case 30: // function_call: name '(' expression_list ')'
#line 342 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NFunctionCall* > () = new NFunctionCall(yystack_[3].value.as < amanda::core::String > ()); yylhs.value.as < amanda::compiler::ast::NFunctionCall* > ()->addPassedArguments(*yystack_[1].value.as < amanda::compiler::ast::ExpressionList* > ()); delete yystack_[1].value.as < amanda::compiler::ast::ExpressionList* > (); }
#line 1201 "compiler/Parser.cpp"
    break;

  case 31: // id: name
#line 347 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NIdentifier* > () = new NIdentifier(yystack_[0].value.as < amanda::core::String > ()); }
#line 1207 "compiler/Parser.cpp"
    break;

  case 32: // numeric_literal: "integer literal"
#line 352 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = new NInteger(yystack_[0].value.as < amanda::core::String > ()); }
#line 1213 "compiler/Parser.cpp"
    break;

  case 33: // expression_list: %empty
#line 357 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = new ExpressionList();                    }
#line 1219 "compiler/Parser.cpp"
    break;

  case 34: // expression_list: expression
#line 358 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = new ExpressionList(); yylhs.value.as < amanda::compiler::ast::ExpressionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1225 "compiler/Parser.cpp"
    break;

  case 35: // expression_list: expression_list ',' expression
#line 359 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = yystack_[2].value.as < amanda::compiler::ast::ExpressionList* > (); yylhs.value.as < amanda::compiler::ast::ExpressionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NExpression* > ());                   }
#line 1231 "compiler/Parser.cpp"
    break;

  case 36: // statement_sequence: %empty
#line 364 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = new NBlock(); }
#line 1237 "compiler/Parser.cpp"
    break;

  case 37: // statement_sequence: statement
#line 365 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = new NBlock(); yylhs.value.as < amanda::compiler::ast::NBlock* > ()->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1243 "compiler/Parser.cpp"
    break;

  case 38: // statement_sequence: statement_sequence statement
#line 366 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = yystack_[1].value.as < amanda::compiler::ast::NBlock* > (); yylhs.value.as < amanda::compiler::ast::NBlock* > ()->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1249 "compiler/Parser.cpp"
    break;

  case 52: // name: simple_name
#line 394 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1255 "compiler/Parser.cpp"
    break;

  case 53: // name: qualified_name
#line 395 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1261 "compiler/Parser.cpp"
    break;

  case 54: // simple_name: "identifier"
#line 399 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1267 "compiler/Parser.cpp"
    break;

  case 55: // qualified_name: "identifier" "'::'" "identifier"
#line 403 "specs/grammar.y"
                                            { yylhs.value.as < amanda::core::String > ().append(yystack_[2].value.as < amanda::core::String > ()).append("::").append(yystack_[0].value.as < amanda::core::String > ()); }
#line 1273 "compiler/Parser.cpp"
    break;

  case 56: // qualified_name: qualified_name "'::'" "identifier"
#line 404 "specs/grammar.y"
                                            { yylhs.value.as < amanda::core::String > () = yystack_[2].value.as < amanda::core::String > (); yylhs.value.as < amanda::core::String > ().append("::").append(yystack_[0].value.as < amanda::core::String > ()); }
#line 1279 "compiler/Parser.cpp"
    break;

  case 60: // binary_operator: expression '<' expression
#line 416 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Lesser, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1285 "compiler/Parser.cpp"
    break;

  case 61: // binary_operator: expression '>' expression
#line 417 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Greater, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1291 "compiler/Parser.cpp"
    break;


#line 1295 "compiler/Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  DefaultParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  DefaultParser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "integer literal",
  "identifier", "and", "as", "break", "case", "class", "delete", "do",
  "else", "for", "if", "is", "interface", "namespace", "new", "not", "or",
  "private", "protected", "public", "return", "switch", "using", "while",
  "bool", "byte", "short", "int", "long", "ushort", "uint", "ulong",
  "string", "char", "void", "float", "double", "'::'", "'<='", "'>='",
  "'=='", "'!='", "'++'", "'--'", "'!'", "'#'", "'$'", "'%'", "'&'", "'('",
  "')'", "'*'", "'+'", "','", "'-'", "'.'", "'/'", "':'", "';'", "'<'",
  "'='", "'>'", "'?'", "'['", "']'", "'^'", "'{'", "'|'", "'}'", "'~'",
  "$accept", "compilation_unit", "declarations", "declaration",
  "namespace_declaration", "using_declaration", "function_declaration",
  "statement", "simple_statement", "compound_statement",
  "expression_statement", "return_statement", "if_statement",
  "while_statement", "expression", "function_call", "id",
  "numeric_literal", "expression_list", "statement_sequence", "type",
  "simple_type", "reference_type", "name", "simple_name", "qualified_name",
  "argument_list", "binary_operator", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // DefaultParser::context.
  DefaultParser::context::context (const DefaultParser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  DefaultParser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }


  bool
  DefaultParser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  DefaultParser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
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

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (!yy_lac_established_)
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
    return true;
  }

  // Discard any previous initial lookahead context.
  void
  DefaultParser::yy_lac_discard_ (const char* evt)
  {
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
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << evt << '\n';
        yy_lac_established_ = false;
      }
  }

  int
  DefaultParser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  DefaultParser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char DefaultParser::yypact_ninf_ = -76;

  const signed char DefaultParser::yytable_ninf_ = -1;

  const signed char
  DefaultParser::yypact_[] =
  {
      99,   -31,    10,    16,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,    24,    99,   -76,   -76,   -76,   -76,     0,
     -76,   -76,   -76,   -76,    11,    55,   -30,    35,    43,   -76,
     -76,    48,    -6,   100,   -76,    99,    99,   -76,   113,   -76,
     -76,    -1,    99,     1,    31,   -76,   -76,    40,   113,    18,
       3,    54,     5,    58,   -76,    50,   -76,   -76,   -76,   -76,
     -76,   -76,     9,    60,   -76,     5,   -76,     5,   -10,   -76,
     -76,   -76,    60,   -76,     5,   -76,   -76,   -76,     5,   -48,
      19,     5,     5,    33,   -10,    32,    51,   -76,   -10,   -10,
      56,   -76,     5,    18,    18,   -10,    30,    37,   106,   -76,
      62,    18,    42,   -76
  };

  const signed char
  DefaultParser::yydefact_[] =
  {
       3,    54,     0,     0,    43,    44,    45,    46,    47,    51,
      42,    48,    49,     0,     2,     4,     6,     7,     8,     0,
      39,    40,    50,    52,    53,     0,    54,     0,     0,     1,
       5,     0,     0,     0,    55,     3,     3,    11,    57,    41,
      56,     0,    10,     0,     0,     9,    58,     0,     0,    36,
       0,     0,    21,     0,    37,     0,    14,    16,    15,    17,
      18,    19,     0,     0,    59,     0,    32,     0,    20,    27,
      25,    26,    31,    28,     0,    13,    12,    38,    33,     0,
       0,     0,     0,     0,    34,     0,     0,    29,    60,    61,
       0,    30,     0,    36,    36,    35,     0,     0,    22,    24,
       0,    36,     0,    23
  };

  const signed char
  DefaultParser::yypgoto_[] =
  {
     -76,   -76,    39,     7,   -76,   -76,   -76,   -19,   -76,   -76,
     -76,   -76,   -76,   -76,    81,    41,   -76,   -76,   -76,   -75,
     -36,   -76,   -76,    -2,   -76,   -76,   -76,   -76
  };

  const signed char
  DefaultParser::yydefgoto_[] =
  {
       0,    13,    14,    15,    16,    17,    18,    54,    55,    56,
      57,    58,    59,    60,    68,    61,    70,    71,    85,    62,
      19,    20,    21,    22,    23,    24,    44,    73
  };

  const signed char
  DefaultParser::yytable_[] =
  {
      27,    28,    43,     1,    31,    46,    86,    64,    66,     1,
      25,    25,    50,     1,    26,    81,     2,    82,    96,    97,
       1,    30,     1,    51,    29,     3,   102,     4,     5,     6,
       7,     8,    51,    52,     1,     9,    53,    10,    11,    12,
      35,     1,    52,    77,    51,    53,     1,    63,    30,    30,
      72,    51,    33,    81,    52,    82,    51,    53,    67,    34,
      63,    52,    39,    72,    53,    72,    52,    32,    32,    53,
      32,    45,    72,    87,    41,    42,    72,    77,    77,    72,
      72,    76,    81,    77,    82,    47,    91,    90,    48,    92,
      72,    63,    63,    69,    63,    63,    81,    36,    82,    63,
      63,    38,    98,     1,    40,    37,    69,    65,    69,    99,
      49,    74,    75,    78,   103,    69,     2,     1,   100,    69,
       0,    93,    69,    69,     0,     3,    94,     4,     5,     6,
       7,     8,   101,    69,     0,     9,     0,    10,    11,    12,
       0,     4,     5,     6,     7,     8,    79,     0,    80,     9,
       0,    10,    11,    12,     0,    83,     0,     0,     0,    84,
       0,     0,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95
  };

  const signed char
  DefaultParser::yycheck_[] =
  {
       2,     3,    38,     4,     4,     4,    54,     4,     3,     4,
      41,    41,    48,     4,     4,    63,    17,    65,    93,    94,
       4,    14,     4,    14,     0,    26,   101,    28,    29,    30,
      31,    32,    14,    24,     4,    36,    27,    38,    39,    40,
      70,     4,    24,    62,    14,    27,     4,    49,    41,    42,
      52,    14,    41,    63,    24,    65,    14,    27,    53,     4,
      62,    24,    68,    65,    27,    67,    24,    67,    67,    27,
      67,    72,    74,    54,    35,    36,    78,    96,    97,    81,
      82,    72,    63,   102,    65,    54,    54,    54,    57,    57,
      92,    93,    94,    52,    96,    97,    63,    62,    65,   101,
     102,    53,    72,     4,     4,    62,    65,    53,    67,    72,
      70,    53,    62,    53,    72,    74,    17,     4,    12,    78,
      -1,    70,    81,    82,    -1,    26,    70,    28,    29,    30,
      31,    32,    70,    92,    -1,    36,    -1,    38,    39,    40,
      -1,    28,    29,    30,    31,    32,    65,    -1,    67,    36,
      -1,    38,    39,    40,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92
  };

  const signed char
  DefaultParser::yystos_[] =
  {
       0,     4,    17,    26,    28,    29,    30,    31,    32,    36,
      38,    39,    40,    75,    76,    77,    78,    79,    80,    94,
      95,    96,    97,    98,    99,    41,     4,    97,    97,     0,
      77,     4,    67,    41,     4,    70,    62,    62,    53,    68,
       4,    76,    76,    94,   100,    72,     4,    54,    57,    70,
      94,    14,    24,    27,    81,    82,    83,    84,    85,    86,
      87,    89,    93,    97,     4,    53,     3,    53,    88,    89,
      90,    91,    97,   101,    53,    62,    72,    81,    53,    88,
      88,    63,    65,    88,    88,    92,    54,    54,    88,    88,
      54,    54,    57,    70,    70,    88,    93,    93,    72,    72,
      12,    70,    93,    72
  };

  const signed char
  DefaultParser::yyr1_[] =
  {
       0,    74,    75,    76,    76,    76,    77,    77,    77,    78,
      78,    79,    80,    81,    81,    82,    82,    83,    83,    84,
      85,    85,    86,    86,    87,    88,    88,    88,    88,    88,
      89,    90,    91,    92,    92,    92,    93,    93,    93,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    98,    99,    99,   100,   100,   100,
     101,   101
  };

  const signed char
  DefaultParser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     1,     1,     1,     5,
       4,     3,     8,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     7,    11,     7,     1,     1,     1,     1,     3,
       4,     1,     1,     0,     1,     3,     0,     1,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     0,     2,     4,
       3,     3
  };




#if YYDEBUG
  const short
  DefaultParser::yyrline_[] =
  {
       0,   234,   234,   250,   251,   252,   256,   257,   258,   262,
     263,   277,   281,   286,   287,   291,   292,   296,   297,   303,
     308,   309,   314,   319,   326,   334,   335,   336,   337,   338,
     342,   347,   352,   357,   358,   359,   364,   365,   366,   371,
     372,   373,   377,   378,   379,   380,   381,   382,   383,   384,
     388,   389,   394,   395,   399,   403,   404,   409,   410,   411,
     416,   417
  };

  void
  DefaultParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  DefaultParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 53 "specs/grammar.y"
} } // amanda::compiler
#line 1944 "compiler/Parser.cpp"

#line 420 "specs/grammar.y"

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
