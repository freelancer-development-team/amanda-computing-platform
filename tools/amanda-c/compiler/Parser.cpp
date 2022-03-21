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
      case symbol_kind::S_statement_sequence: // statement_sequence
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NCompilationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NDeclarationBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_statement_sequence: // statement_sequence
        value.move< amanda::compiler::ast::NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.move< amanda::compiler::ast::NCompilationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< amanda::compiler::ast::NDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< amanda::compiler::ast::NDeclarationBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_statement_sequence: // statement_sequence
        value.copy< amanda::compiler::ast::NBlock* > (that.value);
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.copy< amanda::compiler::ast::NCompilationUnit* > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< amanda::compiler::ast::NDeclaration* > (that.value);
        break;

      case symbol_kind::S_declarations: // declarations
        value.copy< amanda::compiler::ast::NDeclarationBlock* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_statement_sequence: // statement_sequence
        value.move< amanda::compiler::ast::NBlock* > (that.value);
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.move< amanda::compiler::ast::NCompilationUnit* > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< amanda::compiler::ast::NDeclaration* > (that.value);
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< amanda::compiler::ast::NDeclarationBlock* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_statement_sequence: // statement_sequence
        yylhs.value.emplace< amanda::compiler::ast::NBlock* > ();
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        yylhs.value.emplace< amanda::compiler::ast::NCompilationUnit* > ();
        break;

      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< amanda::compiler::ast::NDeclaration* > ();
        break;

      case symbol_kind::S_declarations: // declarations
        yylhs.value.emplace< amanda::compiler::ast::NDeclarationBlock* > ();
        break;

      case symbol_kind::S_expression: // expression
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
#line 228 "specs/grammar.y"
                    {
                        NCompilationUnit* unit = new NCompilationUnit(lexer.filename.c_str());
                        assert(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > () != NULL && "Null pointer exception.");

                        unit->addDeclarations(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > ());

                        // Set the parse tree to the compiler.
                        compiler.setAbstractSyntaxTree(unit);

                        // Assign the semmantic value to the accept rule
                        yylhs.value.as < amanda::compiler::ast::NCompilationUnit* > () = unit;
                    }
#line 932 "compiler/Parser.cpp"
    break;

  case 3: // declarations: %empty
#line 244 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = new NDeclarationBlock(); }
#line 938 "compiler/Parser.cpp"
    break;

  case 4: // declarations: declaration
#line 245 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = new NDeclarationBlock(); yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > ()->addDeclaration(yystack_[0].value.as < amanda::compiler::ast::NDeclaration* > ()); }
#line 944 "compiler/Parser.cpp"
    break;

  case 5: // declarations: declarations declaration
#line 246 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = yystack_[1].value.as < amanda::compiler::ast::NDeclarationBlock* > (); yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > ()->addDeclaration(yystack_[0].value.as < amanda::compiler::ast::NDeclaration* > ()); }
#line 950 "compiler/Parser.cpp"
    break;

  case 6: // declaration: namespace_declaration
#line 250 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NNamespaceDeclaration* > (); }
#line 956 "compiler/Parser.cpp"
    break;

  case 7: // declaration: using_declaration
#line 251 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NUsingDeclaration* > (); }
#line 962 "compiler/Parser.cpp"
    break;

  case 8: // declaration: function_declaration
#line 252 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NFunctionDeclaration* > (); }
#line 968 "compiler/Parser.cpp"
    break;

  case 9: // namespace_declaration: "namespace" "identifier" '{' declarations '}'
#line 256 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > () = new NNamespaceDeclaration(yystack_[3].value.as < amanda::core::String > ()); yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > ()->addDeclarations(yystack_[1].value.as < amanda::compiler::ast::NDeclarationBlock* > ()); }
#line 974 "compiler/Parser.cpp"
    break;

  case 10: // namespace_declaration: "namespace" name ';' declarations
#line 257 "specs/grammar.y"
                                                {
                                                    // This is gonna be the last generated namespace when
                                                    // we call the function
                                                    NNamespaceDeclaration* last = NULL;
                                                    NNamespaceDeclaration* parent = buildNamespacesByQualifiedName(yystack_[2].value.as < amanda::core::String > (), last);

                                                    assert(last != NULL && "Null pointer exception");
                                                    assert(parent != NULL && "Null pointer exception");

                                                    yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > () = parent; last->addDeclarations(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > ());
                                                }
#line 990 "compiler/Parser.cpp"
    break;

  case 11: // using_declaration: "using" name ';'
#line 271 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NUsingDeclaration* > () = new NUsingDeclaration(yystack_[1].value.as < amanda::core::String > ()); }
#line 996 "compiler/Parser.cpp"
    break;

  case 12: // function_declaration: type "identifier" '(' argument_list ')' '{' statement_sequence '}'
#line 275 "specs/grammar.y"
                                                                       { yylhs.value.as < amanda::compiler::ast::NFunctionDeclaration* > () = new NFunctionDeclaration(yystack_[6].value.as < amanda::core::String > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()); }
#line 1002 "compiler/Parser.cpp"
    break;

  case 13: // statement: simple_statement ';'
#line 280 "specs/grammar.y"
      { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[1].value.as < amanda::compiler::ast::NStatement* > (); }
#line 1008 "compiler/Parser.cpp"
    break;

  case 14: // statement: compound_statement
#line 281 "specs/grammar.y"
      { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NStatement* > (); }
#line 1014 "compiler/Parser.cpp"
    break;

  case 15: // simple_statement: return_statement
#line 285 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NReturnStatement* > (); }
#line 1020 "compiler/Parser.cpp"
    break;

  case 16: // simple_statement: expression_statement
#line 286 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NExpressionStatement* > (); }
#line 1026 "compiler/Parser.cpp"
    break;

  case 17: // compound_statement: while_statement
#line 290 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NWhileStatement* > (); }
#line 1032 "compiler/Parser.cpp"
    break;

  case 18: // expression_statement: function_call
#line 296 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[0].value.as < amanda::compiler::ast::NFunctionCall* > ()); }
#line 1038 "compiler/Parser.cpp"
    break;

  case 19: // return_statement: "return" expression
#line 301 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NReturnStatement* > () = new NReturnStatement(); }
#line 1044 "compiler/Parser.cpp"
    break;

  case 20: // return_statement: "return"
#line 302 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NReturnStatement* > () = new NReturnStatement(); }
#line 1050 "compiler/Parser.cpp"
    break;

  case 21: // while_statement: "while" '(' ')' '{' statement_sequence '}'
#line 307 "specs/grammar.y"
                                                {
                                                    yylhs.value.as < amanda::compiler::ast::NWhileStatement* > () = new NWhileStatement(yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()); 
                                                }
#line 1058 "compiler/Parser.cpp"
    break;

  case 22: // expression: function_call
#line 314 "specs/grammar.y"
                        { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NFunctionCall* > (); }
#line 1064 "compiler/Parser.cpp"
    break;

  case 23: // function_call: name '(' expression_list ')'
#line 318 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NFunctionCall* > () = new NFunctionCall(yystack_[3].value.as < amanda::core::String > ()); }
#line 1070 "compiler/Parser.cpp"
    break;

  case 27: // statement_sequence: %empty
#line 331 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = new NBlock(); }
#line 1076 "compiler/Parser.cpp"
    break;

  case 28: // statement_sequence: statement
#line 332 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = new NBlock(); yylhs.value.as < amanda::compiler::ast::NBlock* > ()->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1082 "compiler/Parser.cpp"
    break;

  case 29: // statement_sequence: statement_sequence statement
#line 333 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = yystack_[1].value.as < amanda::compiler::ast::NBlock* > (); yylhs.value.as < amanda::compiler::ast::NBlock* > ()->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1088 "compiler/Parser.cpp"
    break;

  case 43: // name: simple_name
#line 361 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1094 "compiler/Parser.cpp"
    break;

  case 44: // name: qualified_name
#line 362 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1100 "compiler/Parser.cpp"
    break;

  case 45: // simple_name: "identifier"
#line 366 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1106 "compiler/Parser.cpp"
    break;

  case 46: // qualified_name: "identifier" "'::'" "identifier"
#line 370 "specs/grammar.y"
                                            { yylhs.value.as < amanda::core::String > ().append(yystack_[2].value.as < amanda::core::String > ()).append("::").append(yystack_[0].value.as < amanda::core::String > ()); }
#line 1112 "compiler/Parser.cpp"
    break;

  case 47: // qualified_name: qualified_name "'::'" "identifier"
#line 371 "specs/grammar.y"
                                            { yylhs.value.as < amanda::core::String > () = yystack_[2].value.as < amanda::core::String > (); yylhs.value.as < amanda::core::String > ().append("::").append(yystack_[0].value.as < amanda::core::String > ()); }
#line 1118 "compiler/Parser.cpp"
    break;


#line 1122 "compiler/Parser.cpp"

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
  "expression_statement", "return_statement", "while_statement",
  "expression", "function_call", "expression_list", "statement_sequence",
  "type", "simple_type", "reference_type", "name", "simple_name",
  "qualified_name", "argument_list", YY_NULLPTR
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


  const signed char DefaultParser::yypact_ninf_ = -61;

  const signed char DefaultParser::yytable_ninf_ = -1;

  const signed char
  DefaultParser::yypact_[] =
  {
      66,   -31,    16,    18,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,    33,    66,   -61,   -61,   -61,   -61,    -1,
     -61,   -61,   -61,   -61,    -6,    39,   -28,   -14,   -12,   -61,
     -61,     7,    -4,    61,   -61,    66,    66,   -61,    23,   -61,
     -61,     0,    66,     1,   -46,   -61,   -61,     8,    23,    52,
       2,    18,    24,   -61,    22,   -61,   -61,   -61,   -61,   -61,
      10,    27,   -61,   -61,   -61,    31,   -61,   -61,   -61,    18,
      20,   -61,   -38,    52,   -61,    18,    17,   -61,   -61
  };

  const signed char
  DefaultParser::yydefact_[] =
  {
       3,    45,     0,     0,    34,    35,    36,    37,    38,    42,
      33,    39,    40,     0,     2,     4,     6,     7,     8,     0,
      30,    31,    41,    43,    44,     0,    45,     0,     0,     1,
       5,     0,     0,     0,    46,     3,     3,    11,    48,    32,
      47,     0,    10,     0,     0,     9,    49,     0,     0,    27,
       0,    20,     0,    28,     0,    14,    16,    15,    17,    18,
       0,     0,    50,    19,    22,     0,    13,    12,    29,    24,
       0,    25,     0,    27,    23,     0,     0,    26,    21
  };

  const signed char
  DefaultParser::yypgoto_[] =
  {
     -61,   -61,   -11,     4,   -61,   -61,   -61,   -53,   -61,   -61,
     -61,   -61,   -61,   -60,     6,   -61,    13,   -36,   -61,   -61,
      -2,   -61,   -61,   -61
  };

  const signed char
  DefaultParser::yydefgoto_[] =
  {
       0,    13,    14,    15,    16,    17,    18,    53,    54,    55,
      56,    57,    58,    63,    59,    72,    60,    19,    20,    21,
      22,    23,    24,    44
  };

  const signed char
  DefaultParser::yytable_[] =
  {
      27,    28,    43,    31,     1,    46,    62,    68,    47,    71,
      25,    48,    50,    25,     1,    77,    74,     2,    30,    75,
      26,     1,     1,    68,    41,    42,     3,     1,     4,     5,
       6,     7,     8,    29,    51,    33,     9,    52,    10,    11,
      12,    51,    35,    34,    52,    30,    30,    61,    36,    61,
      37,     4,     5,     6,     7,     8,     1,    64,    61,     9,
      38,    10,    11,    12,    39,    40,    32,    61,    32,    32,
       1,    61,    45,    61,    61,    64,    51,    65,    49,    52,
      69,    64,    67,     2,    66,    70,    76,     0,     0,    78,
      73,     0,     3,     0,     4,     5,     6,     7,     8,     0,
       0,     0,     9,     0,    10,    11,    12
  };

  const signed char
  DefaultParser::yycheck_[] =
  {
       2,     3,    38,     4,     4,     4,     4,    60,    54,    69,
      41,    57,    48,    41,     4,    75,    54,    17,    14,    57,
       4,     4,     4,    76,    35,    36,    26,     4,    28,    29,
      30,    31,    32,     0,    24,    41,    36,    27,    38,    39,
      40,    24,    70,     4,    27,    41,    42,    49,    62,    51,
      62,    28,    29,    30,    31,    32,     4,    51,    60,    36,
      53,    38,    39,    40,    68,     4,    67,    69,    67,    67,
       4,    73,    72,    75,    76,    69,    24,    53,    70,    27,
      53,    75,    72,    17,    62,    54,    73,    -1,    -1,    72,
      70,    -1,    26,    -1,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,    -1,    38,    39,    40
  };

  const signed char
  DefaultParser::yystos_[] =
  {
       0,     4,    17,    26,    28,    29,    30,    31,    32,    36,
      38,    39,    40,    75,    76,    77,    78,    79,    80,    91,
      92,    93,    94,    95,    96,    41,     4,    94,    94,     0,
      77,     4,    67,    41,     4,    70,    62,    62,    53,    68,
       4,    76,    76,    91,    97,    72,     4,    54,    57,    70,
      91,    24,    27,    81,    82,    83,    84,    85,    86,    88,
      90,    94,     4,    87,    88,    53,    62,    72,    81,    53,
      54,    87,    89,    70,    54,    57,    90,    87,    72
  };

  const signed char
  DefaultParser::yyr1_[] =
  {
       0,    74,    75,    76,    76,    76,    77,    77,    77,    78,
      78,    79,    80,    81,    81,    82,    82,    83,    84,    85,
      85,    86,    87,    88,    89,    89,    89,    90,    90,    90,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    94,    94,    95,    96,    96,    97,    97,
      97
  };

  const signed char
  DefaultParser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     1,     1,     1,     5,
       4,     3,     8,     2,     1,     1,     1,     1,     1,     2,
       1,     6,     1,     4,     0,     1,     3,     0,     1,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     0,     2,
       4
  };




#if YYDEBUG
  const short
  DefaultParser::yyrline_[] =
  {
       0,   228,   228,   244,   245,   246,   250,   251,   252,   256,
     257,   271,   275,   280,   281,   285,   286,   290,   296,   301,
     302,   307,   314,   318,   324,   325,   326,   331,   332,   333,
     338,   339,   340,   344,   345,   346,   347,   348,   349,   350,
     351,   355,   356,   361,   362,   366,   370,   371,   376,   377,
     378
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
#line 1744 "compiler/Parser.cpp"

#line 381 "specs/grammar.y"


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
