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
#line 105 "specs/grammar.y"


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


#line 115 "compiler/Parser.cpp"


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
#line 208 "compiler/Parser.cpp"

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
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::ConditionalStatementList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::ExpressionList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NAssignmentExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NBinaryOperator* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NBoolean* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NClassDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NClassDeclaration::AccessModifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_section: // class_section
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_scope: // class_scope
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NClassFieldDeclaration* > (YY_MOVE (that.value));
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

      case symbol_kind::S_do_while_statement: // do_while_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NDoWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NExpressionStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_statement: // for_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NForLoopStatement* > (YY_MOVE (that.value));
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

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NUnaryOperator* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NUsingDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NVariableDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::NWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        value.YY_MOVE_OR_COPY< amanda::compiler::ast::StatementList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.YY_MOVE_OR_COPY< amanda::core::String > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
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
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        value.move< amanda::compiler::ast::ConditionalStatementList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< amanda::compiler::ast::ExpressionList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< amanda::compiler::ast::NAssignmentExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.move< amanda::compiler::ast::NBinaryOperator* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.move< amanda::compiler::ast::NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        value.move< amanda::compiler::ast::NBoolean* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        value.move< amanda::compiler::ast::NClassDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        value.move< amanda::compiler::ast::NClassDeclaration::AccessModifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_section: // class_section
        value.move< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_scope: // class_scope
        value.move< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        value.move< amanda::compiler::ast::NClassFieldDeclaration* > (YY_MOVE (that.value));
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

      case symbol_kind::S_do_while_statement: // do_while_statement
        value.move< amanda::compiler::ast::NDoWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.move< amanda::compiler::ast::NExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.move< amanda::compiler::ast::NExpressionStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_statement: // for_statement
        value.move< amanda::compiler::ast::NForLoopStatement* > (YY_MOVE (that.value));
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

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< amanda::compiler::ast::NStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.move< amanda::compiler::ast::NUnaryOperator* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.move< amanda::compiler::ast::NUsingDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< amanda::compiler::ast::NVariableDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.move< amanda::compiler::ast::NWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        value.move< amanda::compiler::ast::StatementList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< amanda::core::String > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        value.move< bool > (YY_MOVE (that.value));
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
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        value.copy< amanda::compiler::ast::ConditionalStatementList > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< amanda::compiler::ast::ExpressionList* > (that.value);
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.copy< amanda::compiler::ast::NAssignmentExpression* > (that.value);
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.copy< amanda::compiler::ast::NBinaryOperator* > (that.value);
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.copy< amanda::compiler::ast::NBlock* > (that.value);
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        value.copy< amanda::compiler::ast::NBoolean* > (that.value);
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        value.copy< amanda::compiler::ast::NClassDeclaration* > (that.value);
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        value.copy< amanda::compiler::ast::NClassDeclaration::AccessModifier > (that.value);
        break;

      case symbol_kind::S_class_section: // class_section
        value.copy< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > (that.value);
        break;

      case symbol_kind::S_class_scope: // class_scope
        value.copy< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (that.value);
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        value.copy< amanda::compiler::ast::NClassFieldDeclaration* > (that.value);
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

      case symbol_kind::S_do_while_statement: // do_while_statement
        value.copy< amanda::compiler::ast::NDoWhileStatement* > (that.value);
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.copy< amanda::compiler::ast::NExpression* > (that.value);
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.copy< amanda::compiler::ast::NExpressionStatement* > (that.value);
        break;

      case symbol_kind::S_for_statement: // for_statement
        value.copy< amanda::compiler::ast::NForLoopStatement* > (that.value);
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

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.copy< amanda::compiler::ast::NStatement* > (that.value);
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< amanda::compiler::ast::NUnaryOperator* > (that.value);
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.copy< amanda::compiler::ast::NUsingDeclaration* > (that.value);
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.copy< amanda::compiler::ast::NVariableDeclaration* > (that.value);
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.copy< amanda::compiler::ast::NWhileStatement* > (that.value);
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        value.copy< amanda::compiler::ast::StatementList* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.copy< amanda::core::String > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        value.copy< bool > (that.value);
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
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        value.move< amanda::compiler::ast::ConditionalStatementList > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< amanda::compiler::ast::ExpressionList* > (that.value);
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< amanda::compiler::ast::NAssignmentExpression* > (that.value);
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.move< amanda::compiler::ast::NBinaryOperator* > (that.value);
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.move< amanda::compiler::ast::NBlock* > (that.value);
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        value.move< amanda::compiler::ast::NBoolean* > (that.value);
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        value.move< amanda::compiler::ast::NClassDeclaration* > (that.value);
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        value.move< amanda::compiler::ast::NClassDeclaration::AccessModifier > (that.value);
        break;

      case symbol_kind::S_class_section: // class_section
        value.move< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > (that.value);
        break;

      case symbol_kind::S_class_scope: // class_scope
        value.move< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (that.value);
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        value.move< amanda::compiler::ast::NClassFieldDeclaration* > (that.value);
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

      case symbol_kind::S_do_while_statement: // do_while_statement
        value.move< amanda::compiler::ast::NDoWhileStatement* > (that.value);
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.move< amanda::compiler::ast::NExpression* > (that.value);
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.move< amanda::compiler::ast::NExpressionStatement* > (that.value);
        break;

      case symbol_kind::S_for_statement: // for_statement
        value.move< amanda::compiler::ast::NForLoopStatement* > (that.value);
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

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< amanda::compiler::ast::NStatement* > (that.value);
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.move< amanda::compiler::ast::NUnaryOperator* > (that.value);
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.move< amanda::compiler::ast::NUsingDeclaration* > (that.value);
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< amanda::compiler::ast::NVariableDeclaration* > (that.value);
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.move< amanda::compiler::ast::NWhileStatement* > (that.value);
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        value.move< amanda::compiler::ast::StatementList* > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< amanda::core::String > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        value.move< bool > (that.value);
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
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        yylhs.value.emplace< amanda::compiler::ast::ConditionalStatementList > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
        yylhs.value.emplace< amanda::compiler::ast::ExpressionList* > ();
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        yylhs.value.emplace< amanda::compiler::ast::NAssignmentExpression* > ();
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        yylhs.value.emplace< amanda::compiler::ast::NBinaryOperator* > ();
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        yylhs.value.emplace< amanda::compiler::ast::NBlock* > ();
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        yylhs.value.emplace< amanda::compiler::ast::NBoolean* > ();
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        yylhs.value.emplace< amanda::compiler::ast::NClassDeclaration* > ();
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        yylhs.value.emplace< amanda::compiler::ast::NClassDeclaration::AccessModifier > ();
        break;

      case symbol_kind::S_class_section: // class_section
        yylhs.value.emplace< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > ();
        break;

      case symbol_kind::S_class_scope: // class_scope
        yylhs.value.emplace< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ();
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        yylhs.value.emplace< amanda::compiler::ast::NClassFieldDeclaration* > ();
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

      case symbol_kind::S_do_while_statement: // do_while_statement
        yylhs.value.emplace< amanda::compiler::ast::NDoWhileStatement* > ();
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        yylhs.value.emplace< amanda::compiler::ast::NExpression* > ();
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        yylhs.value.emplace< amanda::compiler::ast::NExpressionStatement* > ();
        break;

      case symbol_kind::S_for_statement: // for_statement
        yylhs.value.emplace< amanda::compiler::ast::NForLoopStatement* > ();
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

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        yylhs.value.emplace< amanda::compiler::ast::NStatement* > ();
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        yylhs.value.emplace< amanda::compiler::ast::NUnaryOperator* > ();
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        yylhs.value.emplace< amanda::compiler::ast::NUsingDeclaration* > ();
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        yylhs.value.emplace< amanda::compiler::ast::NVariableDeclaration* > ();
        break;

      case symbol_kind::S_while_statement: // while_statement
        yylhs.value.emplace< amanda::compiler::ast::NWhileStatement* > ();
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        yylhs.value.emplace< amanda::compiler::ast::StatementList* > ();
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        yylhs.value.emplace< amanda::core::String > ();
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        yylhs.value.emplace< bool > ();
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
#line 270 "specs/grammar.y"
                    {
                        NCompilationUnit* unit = new NCompilationUnit(lexer.filename.c_str());
                        assert(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > () != NULL && "Null pointer exception.");

                        unit->addDeclarations(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > ());

                        // Set the parse tree to the compiler.
                        compiler.setAbstractSyntaxTree(unit);

                        // Assign the semmantic value to the accept rule
                        yylhs.value.as < amanda::compiler::ast::NCompilationUnit* > () = unit;
                    }
#line 1325 "compiler/Parser.cpp"
    break;

  case 3: // declarations: %empty
#line 286 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = new NDeclarationBlock(); }
#line 1331 "compiler/Parser.cpp"
    break;

  case 4: // declarations: declaration
#line 287 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = new NDeclarationBlock(); yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > ()->addDeclaration(yystack_[0].value.as < amanda::compiler::ast::NDeclaration* > ()); }
#line 1337 "compiler/Parser.cpp"
    break;

  case 5: // declarations: declarations declaration
#line 288 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = yystack_[1].value.as < amanda::compiler::ast::NDeclarationBlock* > (); yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > ()->addDeclaration(yystack_[0].value.as < amanda::compiler::ast::NDeclaration* > ()); }
#line 1343 "compiler/Parser.cpp"
    break;

  case 6: // declaration: namespace_declaration
#line 294 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NNamespaceDeclaration* > (); }
#line 1349 "compiler/Parser.cpp"
    break;

  case 7: // declaration: using_declaration
#line 295 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NUsingDeclaration* > (); }
#line 1355 "compiler/Parser.cpp"
    break;

  case 8: // declaration: class_declaration
#line 296 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NClassDeclaration* > (); }
#line 1361 "compiler/Parser.cpp"
    break;

  case 9: // declaration: function_declaration
#line 297 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NFunctionDeclaration* > (); }
#line 1367 "compiler/Parser.cpp"
    break;

  case 10: // namespace_declaration: "namespace" "identifier" '{' declarations '}'
#line 301 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > () = new NNamespaceDeclaration(yystack_[3].value.as < amanda::core::String > ()); yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > ()->addDeclarations(yystack_[1].value.as < amanda::compiler::ast::NDeclarationBlock* > ()); }
#line 1373 "compiler/Parser.cpp"
    break;

  case 11: // namespace_declaration: "namespace" name ';' declarations
#line 302 "specs/grammar.y"
                                                {
                                                    // This is gonna be the last generated namespace when
                                                    // we call the function
                                                    NNamespaceDeclaration* last = NULL;
                                                    NNamespaceDeclaration* parent = buildNamespacesByQualifiedName(yystack_[2].value.as < amanda::core::String > (), last);

                                                    assert(last != NULL && "Null pointer exception");
                                                    assert(parent != NULL && "Null pointer exception");

                                                    yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > () = parent; last->addDeclarations(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > ());
                                                }
#line 1389 "compiler/Parser.cpp"
    break;

  case 12: // using_declaration: "using" name ';'
#line 316 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NUsingDeclaration* > () = new NUsingDeclaration(yystack_[1].value.as < amanda::core::String > ()); }
#line 1395 "compiler/Parser.cpp"
    break;

  case 13: // function_declaration: type "identifier" '(' argument_list ')' '{' statement_sequence '}'
#line 320 "specs/grammar.y"
                                                                       { yylhs.value.as < amanda::compiler::ast::NFunctionDeclaration* > () = new NFunctionDeclaration(yystack_[6].value.as < amanda::core::String > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()); }
#line 1401 "compiler/Parser.cpp"
    break;

  case 14: // class_declaration: access_modifier "class" "identifier" '{' class_scope '}'
#line 328 "specs/grammar.y"
        {
            yylhs.value.as < amanda::compiler::ast::NClassDeclaration* > () = new NClassDeclaration(yystack_[3].value.as < amanda::core::String > ());
            yylhs.value.as < amanda::compiler::ast::NClassDeclaration* > ()->addClassSections(*yystack_[1].value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ());

            // Set class properties
            yylhs.value.as < amanda::compiler::ast::NClassDeclaration* > ()->setAccessModifier(yystack_[5].value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > ());

            // Clean-up
            delete yystack_[1].value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ();
        }
#line 1416 "compiler/Parser.cpp"
    break;

  case 15: // class_scope: class_section
#line 341 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > () = new NClassDeclaration::ClassSectionList(); yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ()->reserve(3); yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NClassDeclaration::ClassBodySection* > ()); }
#line 1422 "compiler/Parser.cpp"
    break;

  case 16: // class_scope: class_scope class_section
#line 342 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > () = yystack_[1].value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (); yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NClassDeclaration::ClassBodySection* > ()); }
#line 1428 "compiler/Parser.cpp"
    break;

  case 17: // class_section: access_modifier ':' class_statement_sequence
#line 347 "specs/grammar.y"
                                                {
                                                    yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassBodySection* > () = new NClassDeclaration::ClassBodySection(yystack_[2].value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > ());
                                                    yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassBodySection* > ()->setStatements(*yystack_[0].value.as < amanda::compiler::ast::StatementList* > ());

                                                    // Clean-up the mess
                                                    delete yystack_[0].value.as < amanda::compiler::ast::StatementList* > ();
                                                }
#line 1440 "compiler/Parser.cpp"
    break;

  case 18: // class_statement_sequence: %empty
#line 357 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::StatementList* > () = new StatementList(); }
#line 1446 "compiler/Parser.cpp"
    break;

  case 19: // class_statement_sequence: class_statement
#line 358 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::StatementList* > () = new StatementList(); yylhs.value.as < amanda::compiler::ast::StatementList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1452 "compiler/Parser.cpp"
    break;

  case 20: // class_statement_sequence: class_statement_sequence class_statement
#line 359 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::StatementList* > () = yystack_[1].value.as < amanda::compiler::ast::StatementList* > (); yylhs.value.as < amanda::compiler::ast::StatementList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1458 "compiler/Parser.cpp"
    break;

  case 21: // class_statement: field_declaration ';'
#line 363 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[1].value.as < amanda::compiler::ast::NClassFieldDeclaration* > (); }
#line 1464 "compiler/Parser.cpp"
    break;

  case 22: // field_declaration: type id
#line 367 "specs/grammar.y"
                        { yylhs.value.as < amanda::compiler::ast::NClassFieldDeclaration* > () = new NClassFieldDeclaration(yystack_[1].value.as < amanda::core::String > (), yystack_[0].value.as < amanda::compiler::ast::NIdentifier* > ()); }
#line 1470 "compiler/Parser.cpp"
    break;

  case 23: // statement: simple_statement
#line 372 "specs/grammar.y"
      { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NStatement* > (); }
#line 1476 "compiler/Parser.cpp"
    break;

  case 24: // statement: compound_statement
#line 373 "specs/grammar.y"
      { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NStatement* > (); }
#line 1482 "compiler/Parser.cpp"
    break;

  case 25: // simple_statement: return_statement
#line 377 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NReturnStatement* > (); }
#line 1488 "compiler/Parser.cpp"
    break;

  case 26: // simple_statement: expression_statement
#line 378 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NExpressionStatement* > (); }
#line 1494 "compiler/Parser.cpp"
    break;

  case 27: // compound_statement: if_statement
#line 382 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NConditionalStatement* > (); }
#line 1500 "compiler/Parser.cpp"
    break;

  case 28: // compound_statement: for_statement
#line 383 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NForLoopStatement* > (); }
#line 1506 "compiler/Parser.cpp"
    break;

  case 29: // compound_statement: while_statement
#line 384 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NWhileStatement* > (); }
#line 1512 "compiler/Parser.cpp"
    break;

  case 30: // compound_statement: do_while_statement
#line 385 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NDoWhileStatement* > (); }
#line 1518 "compiler/Parser.cpp"
    break;

  case 31: // expression_statement: function_call ';'
#line 391 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[1].value.as < amanda::compiler::ast::NFunctionCall* > ()); }
#line 1524 "compiler/Parser.cpp"
    break;

  case 32: // expression_statement: variable_declaration ';'
#line 392 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[1].value.as < amanda::compiler::ast::NVariableDeclaration* > ()); }
#line 1530 "compiler/Parser.cpp"
    break;

  case 33: // expression_statement: assignment_expression ';'
#line 393 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[1].value.as < amanda::compiler::ast::NAssignmentExpression* > ()); }
#line 1536 "compiler/Parser.cpp"
    break;

  case 34: // expression_statement: unary_operator ';'
#line 394 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[1].value.as < amanda::compiler::ast::NUnaryOperator* > ()); }
#line 1542 "compiler/Parser.cpp"
    break;

  case 35: // return_statement: "return" expression ';'
#line 399 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NReturnStatement* > () = new NReturnStatement(); }
#line 1548 "compiler/Parser.cpp"
    break;

  case 36: // return_statement: "return" ';'
#line 400 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NReturnStatement* > () = new NReturnStatement(); }
#line 1554 "compiler/Parser.cpp"
    break;

  case 37: // if_statement: "if" '(' expression ')' '{' statement_sequence '}'
#line 406 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                        }
#line 1562 "compiler/Parser.cpp"
    break;

  case 38: // if_statement: "if" '(' expression ')' '{' statement_sequence '}' "else" '{' statement_sequence '}'
#line 411 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[8].value.as < amanda::compiler::ast::NExpression* > (), yystack_[5].value.as < amanda::compiler::ast::NBlock* > ()); yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addElseClause(yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()); 
                                                        }
#line 1570 "compiler/Parser.cpp"
    break;

  case 39: // if_statement: "if" '(' expression ')' '{' statement_sequence '}' multiple_else_if_clauses
#line 415 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[5].value.as < amanda::compiler::ast::NExpression* > (), yystack_[2].value.as < amanda::compiler::ast::NBlock* > ());
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addMultipleElseIfClauses(yystack_[0].value.as < amanda::compiler::ast::ConditionalStatementList > ());
                                                        }
#line 1579 "compiler/Parser.cpp"
    break;

  case 40: // if_statement: "if" '(' expression ')' '{' statement_sequence '}' multiple_else_if_clauses "else" '{' statement_sequence '}'
#line 420 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[9].value.as < amanda::compiler::ast::NExpression* > (), yystack_[6].value.as < amanda::compiler::ast::NBlock* > ());
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addMultipleElseIfClauses(yystack_[4].value.as < amanda::compiler::ast::ConditionalStatementList > ());
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addElseClause(yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                        }
#line 1589 "compiler/Parser.cpp"
    break;

  case 41: // if_statement: "if" '(' expression ')' statement
#line 426 "specs/grammar.y"
                                                        {
                                                            // Add a statement sequence
                                                            NBlock* block = new NBlock();
                                                            block->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ());

                                                            // Create the conditional statement
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), block);
                                                        }
#line 1602 "compiler/Parser.cpp"
    break;

  case 42: // multiple_else_if_clauses: "else" "if" '(' expression ')' '{' statement_sequence '}'
#line 438 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::ConditionalStatementList > ().push_back(new NConditionalStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()));
                                                        }
#line 1610 "compiler/Parser.cpp"
    break;

  case 43: // multiple_else_if_clauses: multiple_else_if_clauses "else" "if" '(' expression ')' '{' statement_sequence '}'
#line 442 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::ConditionalStatementList > () = yystack_[8].value.as < amanda::compiler::ast::ConditionalStatementList > ();
                                                            yylhs.value.as < amanda::compiler::ast::ConditionalStatementList > ().push_back(new NConditionalStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()));
                                                        }
#line 1619 "compiler/Parser.cpp"
    break;

  case 44: // for_statement: "for" '(' optional_expression ';' expression ';' optional_expression ')' '{' statement_sequence '}'
#line 450 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NForLoopStatement* > () = new NForLoopStatement(yystack_[8].value.as < amanda::compiler::ast::NExpression* > (), yystack_[6].value.as < amanda::compiler::ast::NExpression* > (), yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                        }
#line 1627 "compiler/Parser.cpp"
    break;

  case 45: // while_statement: "while" '(' expression ')' '{' statement_sequence '}'
#line 457 "specs/grammar.y"
                                                {
                                                    yylhs.value.as < amanda::compiler::ast::NWhileStatement* > () = new NWhileStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                }
#line 1635 "compiler/Parser.cpp"
    break;

  case 46: // while_statement: "while" '(' expression ')' statement
#line 461 "specs/grammar.y"
                                                {
                                                    // Add a new scope to the while loop
                                                    NBlock* body = new NBlock();
                                                    body->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ());

                                                    yylhs.value.as < amanda::compiler::ast::NWhileStatement* > () = new NWhileStatement(yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), body);
                                                }
#line 1647 "compiler/Parser.cpp"
    break;

  case 47: // do_while_statement: "do" '{' statement_sequence '}' "while" '(' expression ')' ';'
#line 472 "specs/grammar.y"
                                                {
                                                    yylhs.value.as < amanda::compiler::ast::NDoWhileStatement* > () = new NDoWhileStatement(yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[6].value.as < amanda::compiler::ast::NBlock* > ());
                                                }
#line 1655 "compiler/Parser.cpp"
    break;

  case 48: // optional_expression: expression
#line 479 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NExpression* > (); }
#line 1661 "compiler/Parser.cpp"
    break;

  case 49: // optional_expression: %empty
#line 480 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = NULL; }
#line 1667 "compiler/Parser.cpp"
    break;

  case 50: // expression: id
#line 484 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NIdentifier* > (); }
#line 1673 "compiler/Parser.cpp"
    break;

  case 51: // expression: boolean_literal
#line 485 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NBoolean* > (); }
#line 1679 "compiler/Parser.cpp"
    break;

  case 52: // expression: numeric_literal
#line 486 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NExpression* > (); }
#line 1685 "compiler/Parser.cpp"
    break;

  case 53: // expression: variable_declaration
#line 487 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NVariableDeclaration* > (); }
#line 1691 "compiler/Parser.cpp"
    break;

  case 54: // expression: function_call
#line 488 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NFunctionCall* > (); }
#line 1697 "compiler/Parser.cpp"
    break;

  case 55: // expression: binary_operator
#line 489 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NBinaryOperator* > (); }
#line 1703 "compiler/Parser.cpp"
    break;

  case 56: // expression: assignment_expression
#line 490 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NAssignmentExpression* > (); }
#line 1709 "compiler/Parser.cpp"
    break;

  case 57: // expression: unary_operator
#line 491 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NUnaryOperator* > (); }
#line 1715 "compiler/Parser.cpp"
    break;

  case 58: // expression: '(' expression ')'
#line 492 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[1].value.as < amanda::compiler::ast::NExpression* > (); }
#line 1721 "compiler/Parser.cpp"
    break;

  case 59: // function_call: name '(' expression_list ')'
#line 496 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NFunctionCall* > () = new NFunctionCall(yystack_[3].value.as < amanda::core::String > ()); yylhs.value.as < amanda::compiler::ast::NFunctionCall* > ()->addPassedArguments(*yystack_[1].value.as < amanda::compiler::ast::ExpressionList* > ()); delete yystack_[1].value.as < amanda::compiler::ast::ExpressionList* > (); }
#line 1727 "compiler/Parser.cpp"
    break;

  case 60: // variable_declaration: type id
#line 500 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NVariableDeclaration* > () = new NVariableDeclaration(yystack_[1].value.as < amanda::core::String > (), yystack_[0].value.as < amanda::compiler::ast::NIdentifier* > ()); }
#line 1733 "compiler/Parser.cpp"
    break;

  case 61: // variable_declaration: variable_declaration '=' expression
#line 501 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NVariableDeclaration* > () = yystack_[2].value.as < amanda::compiler::ast::NVariableDeclaration* > (); yylhs.value.as < amanda::compiler::ast::NVariableDeclaration* > ()->setAssignmentExpression(yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1739 "compiler/Parser.cpp"
    break;

  case 62: // assignment_expression: id '=' expression
#line 505 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NAssignmentExpression* > () = new NAssignmentExpression(yystack_[2].value.as < amanda::compiler::ast::NIdentifier* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1745 "compiler/Parser.cpp"
    break;

  case 63: // id: name
#line 510 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NIdentifier* > () = new NIdentifier(yystack_[0].value.as < amanda::core::String > ()); }
#line 1751 "compiler/Parser.cpp"
    break;

  case 64: // numeric_literal: "integer literal"
#line 515 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = new NInteger(yystack_[0].value.as < amanda::core::String > ()); }
#line 1757 "compiler/Parser.cpp"
    break;

  case 65: // boolean_literal: "boolean literal"
#line 520 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NBoolean* > () = new NBoolean(yystack_[0].value.as < bool > ()); }
#line 1763 "compiler/Parser.cpp"
    break;

  case 66: // expression_list: %empty
#line 525 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = new ExpressionList();                    }
#line 1769 "compiler/Parser.cpp"
    break;

  case 67: // expression_list: expression
#line 526 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = new ExpressionList(); yylhs.value.as < amanda::compiler::ast::ExpressionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1775 "compiler/Parser.cpp"
    break;

  case 68: // expression_list: expression_list ',' expression
#line 527 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = yystack_[2].value.as < amanda::compiler::ast::ExpressionList* > (); yylhs.value.as < amanda::compiler::ast::ExpressionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NExpression* > ());                   }
#line 1781 "compiler/Parser.cpp"
    break;

  case 69: // statement_sequence: %empty
#line 532 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = new NBlock(); }
#line 1787 "compiler/Parser.cpp"
    break;

  case 70: // statement_sequence: statement
#line 533 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = new NBlock(); yylhs.value.as < amanda::compiler::ast::NBlock* > ()->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1793 "compiler/Parser.cpp"
    break;

  case 71: // statement_sequence: statement_sequence statement
#line 534 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = yystack_[1].value.as < amanda::compiler::ast::NBlock* > (); yylhs.value.as < amanda::compiler::ast::NBlock* > ()->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1799 "compiler/Parser.cpp"
    break;

  case 72: // type: simple_type
#line 539 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1805 "compiler/Parser.cpp"
    break;

  case 73: // type: reference_type
#line 540 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1811 "compiler/Parser.cpp"
    break;

  case 74: // type: type '[' ']'
#line 541 "specs/grammar.y"
                    { yylhs.value.as < amanda::core::String > () = "Array@<"; yylhs.value.as < amanda::core::String > ().append(yystack_[2].value.as < amanda::core::String > ()).append(">"); }
#line 1817 "compiler/Parser.cpp"
    break;

  case 75: // simple_type: "void"
#line 545 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::void"; }
#line 1823 "compiler/Parser.cpp"
    break;

  case 76: // simple_type: "bool"
#line 546 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::bool"; }
#line 1829 "compiler/Parser.cpp"
    break;

  case 77: // simple_type: "byte"
#line 547 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::byte"; }
#line 1835 "compiler/Parser.cpp"
    break;

  case 78: // simple_type: "short"
#line 548 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::short"; }
#line 1841 "compiler/Parser.cpp"
    break;

  case 79: // simple_type: "int"
#line 549 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::int"; }
#line 1847 "compiler/Parser.cpp"
    break;

  case 80: // simple_type: "long"
#line 550 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::long"; }
#line 1853 "compiler/Parser.cpp"
    break;

  case 81: // simple_type: "float"
#line 551 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::float"; }
#line 1859 "compiler/Parser.cpp"
    break;

  case 82: // simple_type: "double"
#line 552 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::double"; }
#line 1865 "compiler/Parser.cpp"
    break;

  case 83: // reference_type: name
#line 556 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1871 "compiler/Parser.cpp"
    break;

  case 84: // reference_type: "string"
#line 557 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::string"; }
#line 1877 "compiler/Parser.cpp"
    break;

  case 85: // name: simple_name
#line 562 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1883 "compiler/Parser.cpp"
    break;

  case 86: // name: qualified_name
#line 563 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1889 "compiler/Parser.cpp"
    break;

  case 87: // simple_name: "identifier"
#line 567 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1895 "compiler/Parser.cpp"
    break;

  case 88: // qualified_name: "identifier" "'::'" "identifier"
#line 571 "specs/grammar.y"
                                            { yylhs.value.as < amanda::core::String > ().append(yystack_[2].value.as < amanda::core::String > ()).append("::").append(yystack_[0].value.as < amanda::core::String > ()); }
#line 1901 "compiler/Parser.cpp"
    break;

  case 89: // qualified_name: qualified_name "'::'" "identifier"
#line 572 "specs/grammar.y"
                                            { yylhs.value.as < amanda::core::String > () = yystack_[2].value.as < amanda::core::String > (); yylhs.value.as < amanda::core::String > ().append("::").append(yystack_[0].value.as < amanda::core::String > ()); }
#line 1907 "compiler/Parser.cpp"
    break;

  case 90: // access_modifier: "private"
#line 577 "specs/grammar.y"
                    { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > () = NClassDeclaration::createAccessModifierFromString("private"); }
#line 1913 "compiler/Parser.cpp"
    break;

  case 91: // access_modifier: "protected"
#line 578 "specs/grammar.y"
                    { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > () = NClassDeclaration::createAccessModifierFromString("protected"); }
#line 1919 "compiler/Parser.cpp"
    break;

  case 92: // access_modifier: "public"
#line 579 "specs/grammar.y"
                    { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > () = NClassDeclaration::createAccessModifierFromString("public"); }
#line 1925 "compiler/Parser.cpp"
    break;

  case 96: // binary_operator: expression '<' expression
#line 591 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Lesser, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1931 "compiler/Parser.cpp"
    break;

  case 97: // binary_operator: expression "'<='" expression
#line 592 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_LesserEquals, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1937 "compiler/Parser.cpp"
    break;

  case 98: // binary_operator: expression '>' expression
#line 593 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Greater, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1943 "compiler/Parser.cpp"
    break;

  case 99: // binary_operator: expression "'>='" expression
#line 594 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_GreaterEquals, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1949 "compiler/Parser.cpp"
    break;

  case 100: // binary_operator: expression "'=='" expression
#line 595 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Equals, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1955 "compiler/Parser.cpp"
    break;

  case 101: // binary_operator: expression "'!='" expression
#line 596 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_NotEquals, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1961 "compiler/Parser.cpp"
    break;

  case 102: // binary_operator: expression '+' expression
#line 597 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Sum, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1967 "compiler/Parser.cpp"
    break;

  case 103: // binary_operator: expression '-' expression
#line 598 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Sub, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1973 "compiler/Parser.cpp"
    break;

  case 104: // binary_operator: expression '/' expression
#line 599 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Div, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1979 "compiler/Parser.cpp"
    break;

  case 105: // binary_operator: expression '*' expression
#line 600 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Mult, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1985 "compiler/Parser.cpp"
    break;

  case 106: // binary_operator: expression '%' expression
#line 601 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Mod, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1991 "compiler/Parser.cpp"
    break;

  case 107: // binary_operator: expression "and" expression
#line 602 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_LogicAnd, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1997 "compiler/Parser.cpp"
    break;

  case 108: // binary_operator: expression "or" expression
#line 603 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_LogicOr, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 2003 "compiler/Parser.cpp"
    break;

  case 109: // unary_operator: "'++'" expression
#line 607 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NUnaryOperator* > () = new NUnaryOperator(UO_Preincrement, yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 2009 "compiler/Parser.cpp"
    break;

  case 110: // unary_operator: "'--'" expression
#line 608 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NUnaryOperator* > () = new NUnaryOperator(UO_Predecrement, yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 2015 "compiler/Parser.cpp"
    break;

  case 111: // unary_operator: expression "'++'"
#line 609 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NUnaryOperator* > () = new NUnaryOperator(UO_Postincrement, yystack_[1].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 2021 "compiler/Parser.cpp"
    break;

  case 112: // unary_operator: expression "'--'"
#line 610 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NUnaryOperator* > () = new NUnaryOperator(UO_Postdecrement, yystack_[1].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 2027 "compiler/Parser.cpp"
    break;


#line 2031 "compiler/Parser.cpp"

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
    "end of file", "error", "invalid token", "boolean literal",
  "integer literal", "identifier", "and", "as", "break", "case", "class",
  "delete", "do", "else", "except", "for", "if", "is", "interface",
  "namespace", "new", "not", "or", "private", "protected", "public",
  "return", "switch", "try", "using", "while", "bool", "byte", "short",
  "int", "long", "ushort", "uint", "ulong", "string", "char", "void",
  "float", "double", "'::'", "'<='", "'>='", "'=='", "'!='", "'++'",
  "'--'", "'!'", "'#'", "'$'", "'%'", "'&'", "'('", "')'", "'*'", "'+'",
  "','", "'-'", "'.'", "'/'", "':'", "';'", "'<'", "'='", "'>'", "'?'",
  "'['", "']'", "'^'", "'{'", "'|'", "'}'", "'~'", "$accept",
  "compilation_unit", "declarations", "declaration",
  "namespace_declaration", "using_declaration", "function_declaration",
  "class_declaration", "class_scope", "class_section",
  "class_statement_sequence", "class_statement", "field_declaration",
  "statement", "simple_statement", "compound_statement",
  "expression_statement", "return_statement", "if_statement",
  "multiple_else_if_clauses", "for_statement", "while_statement",
  "do_while_statement", "optional_expression", "expression",
  "function_call", "variable_declaration", "assignment_expression", "id",
  "numeric_literal", "boolean_literal", "expression_list",
  "statement_sequence", "type", "simple_type", "reference_type", "name",
  "simple_name", "qualified_name", "access_modifier", "argument_list",
  "binary_operator", "unary_operator", YY_NULLPTR
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


  const signed char DefaultParser::yypact_ninf_ = -87;

  const signed char DefaultParser::yytable_ninf_ = -84;

  const short
  DefaultParser::yypact_[] =
  {
    1234,   -37,     8,   -87,   -87,   -87,    21,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,    39,  1234,   -87,   -87,
     -87,   -87,   -87,     0,   -87,   -87,   -87,   -87,   -24,    43,
      44,   -43,   -10,    22,   -87,   -87,    36,     7,    62,    88,
     -87,  1234,  1234,   -87,  1247,   -87,   -87,    24,   271,  1234,
       4,   -35,    66,   -87,   -87,    25,  1247,    13,   -87,    31,
    1179,     5,   -87,   -87,  1247,   -87,   -87,    27,    40,    47,
     864,    49,  1199,  1199,  1199,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,  1113,    42,   -25,    48,    51,   -87,
     -87,   351,     6,    -2,   -87,    54,   -87,  1247,   -87,    55,
       6,  1179,  1199,  1199,   -87,   878,   -87,    57,   -87,   -87,
    1199,  1113,  1113,   909,  1199,  1199,  1199,  1199,  1199,  1199,
     -87,   -87,  1199,  1199,  1199,  1199,  1199,  1199,  1199,   -87,
     -87,  1199,   -87,  1199,   -87,   -87,   -87,   -87,  1199,   -87,
     -87,   -87,   -87,   399,    60,  1113,   939,   -87,   968,   -87,
    1113,  1113,    23,    23,    23,    23,  1113,    11,   142,   142,
      11,    23,    23,  1113,  1113,  1113,   -33,    76,  1199,   783,
     831,   -87,  1199,    52,   997,  1179,   -87,  1179,   -87,  1113,
    1199,  1199,   447,   495,  1026,    59,   101,   -87,    61,    56,
      -4,   114,   -87,  1179,    72,  1179,    12,   543,  1199,   591,
      78,  1179,   -87,  1055,   -87,  1199,   639,    67,  1084,   -87,
    1179,    74,   687,  1179,   -87,   735,   -87
  };

  const signed char
  DefaultParser::yydefact_[] =
  {
       3,    87,     0,    90,    91,    92,     0,    76,    77,    78,
      79,    80,    84,    75,    81,    82,     0,     2,     4,     6,
       7,     9,     8,     0,    72,    73,    83,    85,    86,     0,
       0,    87,     0,     0,     1,     5,     0,     0,     0,     0,
      88,     3,     3,    12,    93,    74,    89,     0,     0,    11,
       0,     0,     0,    10,    94,     0,     0,     0,    15,     0,
      69,     0,    14,    16,    18,    65,    64,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    23,    24,    26,    25,
      27,    28,    29,    30,     0,    54,    53,    56,    50,    52,
      51,     0,     0,    63,    55,    57,    95,    17,    19,     0,
       0,    69,    49,     0,    36,     0,    54,    53,    56,    57,
       0,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,   112,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,    33,     0,    13,    71,    60,    63,    66,    34,
      20,    21,    22,     0,     0,    48,     0,    35,     0,    58,
     107,   108,    97,    99,   100,   101,   106,   105,   102,   103,
     104,    96,    98,    61,    62,    67,     0,     0,     0,     0,
       0,    59,     0,     0,     0,    69,    41,    69,    46,    68,
       0,    49,     0,     0,     0,     0,    37,    45,     0,     0,
       0,    39,    47,    69,     0,    69,     0,     0,     0,     0,
       0,    69,    44,     0,    38,     0,     0,     0,     0,    40,
      69,     0,     0,    69,    42,     0,    43
  };

  const short
  DefaultParser::yypgoto_[] =
  {
     -87,   -87,    -7,    -1,   -87,   -87,   -87,   -87,   -87,    92,
     -87,    64,   -87,   146,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -36,   155,   -60,   -39,    20,   -86,   -87,
     -87,   -87,   149,    15,   -87,   -87,     2,   -87,   -87,   -34,
     -87,   -87,    41
  };

  const unsigned char
  DefaultParser::yydefgoto_[] =
  {
       0,    16,    17,    18,    19,    20,    21,    22,    57,    58,
      97,    98,    99,    75,    76,    77,    78,    79,    80,   191,
      81,    82,    83,   144,    84,   106,   107,   108,    88,    89,
      90,   166,    91,    92,    24,    25,    93,    27,    28,    29,
      51,    94,   109
  };

  const short
  DefaultParser::yytable_[] =
  {
      85,    30,    26,   -83,    32,    36,   136,    30,    33,    54,
      96,     1,   194,    31,   142,    23,    35,   114,    59,    26,
      38,    86,    55,    59,   171,    56,     1,   172,   200,   114,
      41,    85,    23,   115,    48,    49,     3,     4,     5,    34,
     130,    85,   131,    26,    26,   115,    26,    35,    35,    40,
      26,    26,    86,    39,   138,    42,    23,    23,    26,    50,
     120,   121,    86,    23,    23,   122,    26,    46,   -83,   195,
      37,    61,   120,   121,    37,    37,    37,   122,    45,   100,
      87,   123,   124,    85,   125,   201,   126,    43,    62,     3,
       4,     5,    44,    47,   137,    64,   102,    52,    60,    26,
     101,    95,   137,   103,    86,   110,   173,   129,   180,    85,
      85,    87,   100,   132,   190,    85,   189,    85,   133,   139,
     141,    87,    85,    85,   131,   168,   192,   196,   198,   193,
      86,    86,    95,    85,   205,    85,    86,    85,    86,    85,
     210,    85,    95,    86,    86,   185,    85,   213,   114,    63,
      85,     0,    85,    85,    86,    85,    86,     0,    86,     0,
      86,   140,    86,    87,   115,     0,     0,    86,     0,     0,
       0,    86,     0,    86,    86,     0,    86,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,    87,
      87,   120,   121,     0,     0,    87,   122,    87,     0,     0,
     123,     0,    87,    87,     0,   126,     0,     0,     0,     0,
      95,    95,     0,    87,     0,    87,    95,    87,    95,    87,
       0,    87,     0,    95,    95,   105,    87,   111,   112,   113,
      87,     0,    87,    87,    95,    87,    95,   135,    95,     0,
      95,     0,    95,     0,     0,     0,     0,    95,     0,     0,
     143,    95,     0,    95,    95,     0,    95,   145,   146,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,   150,
     151,   152,   153,   154,   155,     0,     1,   156,   157,   158,
     159,   160,   161,   162,     0,     0,   163,     0,   164,   135,
       2,     0,     0,   165,     3,     4,     5,     0,     0,     0,
       6,     0,     7,     8,     9,    10,    11,     0,     0,     0,
      12,     0,    13,    14,    15,   176,   178,     0,     0,     0,
       0,     0,     0,   174,   182,     0,   183,   179,   135,   135,
       0,     0,     0,     0,     0,   184,   145,     0,     0,     0,
       0,     0,   197,   135,   199,   135,    53,     0,     0,     0,
     206,     0,   135,   203,    65,    66,     1,     0,   135,   212,
     208,   135,   215,    67,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,    71,     7,     8,     9,    10,    11,     0,     0,     0,
      12,     0,    13,    14,    15,     0,     0,     0,     0,     0,
      72,    73,    65,    66,     1,     0,     0,    74,     0,     0,
       0,    67,     0,     0,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,   134,     0,     0,    71,
       7,     8,     9,    10,    11,     0,     0,     0,    12,     0,
      13,    14,    15,     0,     0,     0,     0,     0,    72,    73,
      65,    66,     1,     0,     0,    74,     0,     0,     0,    67,
       0,     0,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,   167,     0,     0,    71,     7,     8,
       9,    10,    11,     0,     0,     0,    12,     0,    13,    14,
      15,     0,     0,     0,     0,     0,    72,    73,    65,    66,
       1,     0,     0,    74,     0,     0,     0,    67,     0,     0,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,   186,     0,     0,    71,     7,     8,     9,    10,
      11,     0,     0,     0,    12,     0,    13,    14,    15,     0,
       0,     0,     0,     0,    72,    73,    65,    66,     1,     0,
       0,    74,     0,     0,     0,    67,     0,     0,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     187,     0,     0,    71,     7,     8,     9,    10,    11,     0,
       0,     0,    12,     0,    13,    14,    15,     0,     0,     0,
       0,     0,    72,    73,    65,    66,     1,     0,     0,    74,
       0,     0,     0,    67,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,   202,     0,
       0,    71,     7,     8,     9,    10,    11,     0,     0,     0,
      12,     0,    13,    14,    15,     0,     0,     0,     0,     0,
      72,    73,    65,    66,     1,     0,     0,    74,     0,     0,
       0,    67,     0,     0,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,   204,     0,     0,    71,
       7,     8,     9,    10,    11,     0,     0,     0,    12,     0,
      13,    14,    15,     0,     0,     0,     0,     0,    72,    73,
      65,    66,     1,     0,     0,    74,     0,     0,     0,    67,
       0,     0,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,   209,     0,     0,    71,     7,     8,
       9,    10,    11,     0,     0,     0,    12,     0,    13,    14,
      15,     0,     0,     0,     0,     0,    72,    73,    65,    66,
       1,     0,     0,    74,     0,     0,     0,    67,     0,     0,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,   214,     0,     0,    71,     7,     8,     9,    10,
      11,     0,     0,     0,    12,     0,    13,    14,    15,     0,
       0,     0,     0,     0,    72,    73,    65,    66,     1,     0,
       0,    74,     0,     0,     0,    67,     0,     0,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     216,     0,     0,    71,     7,     8,     9,    10,    11,     0,
       0,     0,    12,     0,    13,    14,    15,     0,     0,     0,
       0,     0,    72,    73,    65,    66,     1,     0,     0,    74,
       0,     0,     0,    67,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,   175,    70,     0,     0,
       0,    71,     7,     8,     9,    10,    11,    65,    66,     1,
      12,     0,    13,    14,    15,     0,     0,     0,     0,     0,
      72,    73,     0,     0,   114,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     9,    10,    11,
     115,     0,     0,    12,   177,    13,    14,    15,     0,     0,
       0,     0,     0,    72,    73,   114,     0,     0,     0,     0,
      74,     0,     0,   116,   117,   118,   119,   120,   121,   104,
       0,   115,   122,     0,     0,     0,   123,   124,     0,   125,
       0,   126,     0,   147,   127,   114,   128,     0,     0,     0,
       0,     0,     0,     0,   116,   117,   118,   119,   120,   121,
       0,   115,     0,   122,     0,     0,   149,   123,   124,     0,
     125,     0,   126,     0,   114,   127,     0,   128,     0,     0,
       0,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     115,     0,     0,   122,     0,     0,   169,   123,   124,     0,
     125,     0,   126,   114,     0,   127,     0,   128,     0,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   115,
       0,     0,   122,     0,     0,   170,   123,   124,     0,   125,
       0,   126,   114,     0,   127,     0,   128,     0,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   115,     0,
       0,   122,     0,     0,     0,   123,   124,     0,   125,     0,
     126,   114,   181,   127,     0,   128,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   115,     0,     0,
     122,     0,     0,   188,   123,   124,     0,   125,     0,   126,
     114,     0,   127,     0,   128,     0,     0,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   115,     0,     0,   122,
       0,     0,   207,   123,   124,     0,   125,     0,   126,   114,
       0,   127,     0,   128,     0,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   115,     0,     0,   122,     0,
       0,   211,   123,   124,     0,   125,     0,   126,     0,     0,
     127,     0,   128,     0,     0,     0,     0,     0,   116,   117,
     118,   119,   120,   121,     0,     0,     0,   122,     0,     0,
       0,   123,   124,     0,   125,     0,   126,     0,     0,   127,
       0,   128,    65,    66,     1,     0,     0,     0,     0,     0,
       0,    67,     0,     0,    68,    69,     0,     0,     0,     0,
       0,     0,    65,    66,     1,    70,     0,     0,     0,    71,
       7,     8,     9,    10,    11,     0,     0,     0,    12,     0,
      13,    14,    15,     0,     0,     0,     0,     0,    72,    73,
       7,     8,     9,    10,    11,    74,     0,     0,    12,     1,
      13,    14,    15,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     1,     2,     0,    74,     0,     3,     4,     5,
       0,     0,     0,     6,     0,     7,     8,     9,    10,    11,
       0,     0,     0,    12,     0,    13,    14,    15,     7,     8,
       9,    10,    11,     0,     0,     0,    12,     0,    13,    14,
      15
  };

  const short
  DefaultParser::yycheck_[] =
  {
      60,    44,     0,     5,     2,     5,    92,    44,     6,     5,
       5,     5,    16,     5,   100,     0,    17,     6,    52,    17,
      44,    60,    57,    57,    57,    60,     5,    60,    16,     6,
      73,    91,    17,    22,    41,    42,    23,    24,    25,     0,
      65,   101,    67,    41,    42,    22,    44,    48,    49,     5,
      48,    49,    91,    10,    56,    65,    41,    42,    56,    44,
      49,    50,   101,    48,    49,    54,    64,     5,    70,    73,
      70,    56,    49,    50,    70,    70,    70,    54,    71,    64,
      60,    58,    59,   143,    61,    73,    63,    65,    75,    23,
      24,    25,    56,     5,    92,    64,    56,    73,    73,    97,
      73,    60,   100,    56,   143,    56,    30,    65,    56,   169,
     170,    91,    97,    65,    13,   175,    57,   177,    67,    65,
      65,   101,   182,   183,    67,    65,    65,    13,    56,    73,
     169,   170,    91,   193,    56,   195,   175,   197,   177,   199,
      73,   201,   101,   182,   183,   181,   206,    73,     6,    57,
     210,    -1,   212,   213,   193,   215,   195,    -1,   197,    -1,
     199,    97,   201,   143,    22,    -1,    -1,   206,    -1,    -1,
      -1,   210,    -1,   212,   213,    -1,   215,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   169,
     170,    49,    50,    -1,    -1,   175,    54,   177,    -1,    -1,
      58,    -1,   182,   183,    -1,    63,    -1,    -1,    -1,    -1,
     169,   170,    -1,   193,    -1,   195,   175,   197,   177,   199,
      -1,   201,    -1,   182,   183,    70,   206,    72,    73,    74,
     210,    -1,   212,   213,   193,   215,   195,    91,   197,    -1,
     199,    -1,   201,    -1,    -1,    -1,    -1,   206,    -1,    -1,
     101,   210,    -1,   212,   213,    -1,   215,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,   114,
     115,   116,   117,   118,   119,    -1,     5,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,   131,    -1,   133,   143,
      19,    -1,    -1,   138,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    41,    42,    43,   169,   170,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   175,    -1,   177,   172,   182,   183,
      -1,    -1,    -1,    -1,    -1,   180,   181,    -1,    -1,    -1,
      -1,    -1,   193,   197,   195,   199,    75,    -1,    -1,    -1,
     201,    -1,   206,   198,     3,     4,     5,    -1,   212,   210,
     205,   215,   213,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,     3,     4,     5,    -1,    -1,    56,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    75,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
       3,     4,     5,    -1,    -1,    56,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    75,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,     3,     4,
       5,    -1,    -1,    56,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    75,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,     3,     4,     5,    -1,
      -1,    56,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      75,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,     3,     4,     5,    -1,    -1,    56,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    75,    -1,
      -1,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,     3,     4,     5,    -1,    -1,    56,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    75,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
       3,     4,     5,    -1,    -1,    56,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    75,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,     3,     4,
       5,    -1,    -1,    56,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    75,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,     3,     4,     5,    -1,
      -1,    56,    -1,    -1,    -1,    12,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      75,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,     3,     4,     5,    -1,    -1,    56,
      -1,    -1,    -1,    12,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,     3,     4,     5,
      39,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    -1,    -1,     6,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      22,    -1,    -1,    39,    73,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    49,    50,     6,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    45,    46,    47,    48,    49,    50,    65,
      -1,    22,    54,    -1,    -1,    -1,    58,    59,    -1,    61,
      -1,    63,    -1,    65,    66,     6,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      -1,    22,    -1,    54,    -1,    -1,    57,    58,    59,    -1,
      61,    -1,    63,    -1,     6,    66,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      22,    -1,    -1,    54,    -1,    -1,    57,    58,    59,    -1,
      61,    -1,    63,     6,    -1,    66,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    22,
      -1,    -1,    54,    -1,    -1,    57,    58,    59,    -1,    61,
      -1,    63,     6,    -1,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    22,    -1,
      -1,    54,    -1,    -1,    -1,    58,    59,    -1,    61,    -1,
      63,     6,    65,    66,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    22,    -1,    -1,
      54,    -1,    -1,    57,    58,    59,    -1,    61,    -1,    63,
       6,    -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    22,    -1,    -1,    54,
      -1,    -1,    57,    58,    59,    -1,    61,    -1,    63,     6,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    22,    -1,    -1,    54,    -1,
      -1,    57,    58,    59,    -1,    61,    -1,    63,    -1,    -1,
      66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    58,    59,    -1,    61,    -1,    63,    -1,    -1,    66,
      -1,    68,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
      31,    32,    33,    34,    35,    56,    -1,    -1,    39,     5,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
      -1,    -1,     5,    19,    -1,    56,    -1,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    -1,    41,    42,    43,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    41,    42,
      43
  };

  const signed char
  DefaultParser::yystos_[] =
  {
       0,     5,    19,    23,    24,    25,    29,    31,    32,    33,
      34,    35,    39,    41,    42,    43,    78,    79,    80,    81,
      82,    83,    84,   110,   111,   112,   113,   114,   115,   116,
      44,     5,   113,   113,     0,    80,     5,    70,    44,    10,
       5,    73,    65,    65,    56,    71,     5,     5,    79,    79,
     110,   117,    73,    75,     5,    57,    60,    85,    86,   116,
      73,   110,    75,    86,    64,     3,     4,    12,    15,    16,
      26,    30,    49,    50,    56,    90,    91,    92,    93,    94,
      95,    97,    98,    99,   101,   102,   103,   104,   105,   106,
     107,   109,   110,   113,   118,   119,     5,    87,    88,    89,
     110,    73,    56,    56,    65,   101,   102,   103,   104,   119,
      56,   101,   101,   101,     6,    22,    45,    46,    47,    48,
      49,    50,    54,    58,    59,    61,    63,    66,    68,    65,
      65,    67,    65,    67,    75,    90,   105,   113,    56,    65,
      88,    65,   105,   109,   100,   101,   101,    65,   101,    57,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   108,    75,    65,    57,
      57,    57,    60,    30,   101,    73,    90,    73,    90,   101,
      56,    65,   109,   109,   101,   100,    75,    75,    57,    57,
      13,    96,    65,    73,    16,    73,    13,   109,    56,   109,
      16,    73,    75,   101,    75,    56,   109,    57,   101,    75,
      73,    57,   109,    73,    75,   109,    75
  };

  const signed char
  DefaultParser::yyr1_[] =
  {
       0,    77,    78,    79,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    83,    84,    85,    85,    86,    87,    87,
      87,    88,    89,    90,    90,    91,    91,    92,    92,    92,
      92,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    96,    96,    97,    98,    98,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     103,   103,   104,   105,   106,   107,   108,   108,   108,   109,
     109,   109,   110,   110,   110,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   114,   115,   115,
     116,   116,   116,   117,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119
  };

  const signed char
  DefaultParser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       5,     4,     3,     8,     6,     1,     2,     3,     0,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     3,     2,     7,    11,     8,
      12,     5,     8,     9,    11,     7,     5,     9,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       2,     3,     3,     1,     1,     1,     0,     1,     3,     0,
       1,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     0,     2,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2
  };




#if YYDEBUG
  const short
  DefaultParser::yyrline_[] =
  {
       0,   270,   270,   286,   287,   288,   294,   295,   296,   297,
     301,   302,   316,   320,   324,   341,   342,   346,   357,   358,
     359,   363,   367,   372,   373,   377,   378,   382,   383,   384,
     385,   391,   392,   393,   394,   399,   400,   405,   410,   414,
     419,   425,   437,   441,   449,   456,   460,   471,   479,   480,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   496,
     500,   501,   505,   510,   515,   520,   525,   526,   527,   532,
     533,   534,   539,   540,   541,   545,   546,   547,   548,   549,
     550,   551,   552,   556,   557,   562,   563,   567,   571,   572,
     577,   578,   579,   584,   585,   586,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   607,
     608,   609,   610
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
#line 2962 "compiler/Parser.cpp"

#line 613 "specs/grammar.y"

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
