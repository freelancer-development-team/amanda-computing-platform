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
#line 268 "specs/grammar.y"
                    {
                        NCompilationUnit* unit = new NCompilationUnit(lexer.filename.c_str());
                        assert(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > () != NULL && "Null pointer exception.");

                        unit->addDeclarations(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > ());

                        // Set the parse tree to the compiler.
                        compiler.setAbstractSyntaxTree(unit);

                        // Assign the semmantic value to the accept rule
                        yylhs.value.as < amanda::compiler::ast::NCompilationUnit* > () = unit;
                    }
#line 1285 "compiler/Parser.cpp"
    break;

  case 3: // declarations: %empty
#line 284 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = new NDeclarationBlock(); }
#line 1291 "compiler/Parser.cpp"
    break;

  case 4: // declarations: declaration
#line 285 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = new NDeclarationBlock(); yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > ()->addDeclaration(yystack_[0].value.as < amanda::compiler::ast::NDeclaration* > ()); }
#line 1297 "compiler/Parser.cpp"
    break;

  case 5: // declarations: declarations declaration
#line 286 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > () = yystack_[1].value.as < amanda::compiler::ast::NDeclarationBlock* > (); yylhs.value.as < amanda::compiler::ast::NDeclarationBlock* > ()->addDeclaration(yystack_[0].value.as < amanda::compiler::ast::NDeclaration* > ()); }
#line 1303 "compiler/Parser.cpp"
    break;

  case 6: // declaration: namespace_declaration
#line 292 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NNamespaceDeclaration* > (); }
#line 1309 "compiler/Parser.cpp"
    break;

  case 7: // declaration: using_declaration
#line 293 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NUsingDeclaration* > (); }
#line 1315 "compiler/Parser.cpp"
    break;

  case 8: // declaration: class_declaration
#line 294 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NClassDeclaration* > (); }
#line 1321 "compiler/Parser.cpp"
    break;

  case 9: // declaration: function_declaration
#line 295 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NDeclaration* > () = yystack_[0].value.as < amanda::compiler::ast::NFunctionDeclaration* > (); }
#line 1327 "compiler/Parser.cpp"
    break;

  case 10: // namespace_declaration: "namespace" "identifier" '{' declarations '}'
#line 299 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > () = new NNamespaceDeclaration(yystack_[3].value.as < amanda::core::String > ()); yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > ()->addDeclarations(yystack_[1].value.as < amanda::compiler::ast::NDeclarationBlock* > ()); }
#line 1333 "compiler/Parser.cpp"
    break;

  case 11: // namespace_declaration: "namespace" name ';' declarations
#line 300 "specs/grammar.y"
                                                {
                                                    // This is gonna be the last generated namespace when
                                                    // we call the function
                                                    NNamespaceDeclaration* last = NULL;
                                                    NNamespaceDeclaration* parent = buildNamespacesByQualifiedName(yystack_[2].value.as < amanda::core::String > (), last);

                                                    assert(last != NULL && "Null pointer exception");
                                                    assert(parent != NULL && "Null pointer exception");

                                                    yylhs.value.as < amanda::compiler::ast::NNamespaceDeclaration* > () = parent; last->addDeclarations(yystack_[0].value.as < amanda::compiler::ast::NDeclarationBlock* > ());
                                                }
#line 1349 "compiler/Parser.cpp"
    break;

  case 12: // using_declaration: "using" name ';'
#line 314 "specs/grammar.y"
                            { yylhs.value.as < amanda::compiler::ast::NUsingDeclaration* > () = new NUsingDeclaration(yystack_[1].value.as < amanda::core::String > ()); }
#line 1355 "compiler/Parser.cpp"
    break;

  case 13: // function_declaration: type "identifier" '(' argument_list ')' '{' statement_sequence '}'
#line 318 "specs/grammar.y"
                                                                       { yylhs.value.as < amanda::compiler::ast::NFunctionDeclaration* > () = new NFunctionDeclaration(yystack_[6].value.as < amanda::core::String > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()); }
#line 1361 "compiler/Parser.cpp"
    break;

  case 14: // class_declaration: access_modifier "class" "identifier" '{' class_scope '}'
#line 326 "specs/grammar.y"
        {
            yylhs.value.as < amanda::compiler::ast::NClassDeclaration* > () = new NClassDeclaration(yystack_[3].value.as < amanda::core::String > ());
            yylhs.value.as < amanda::compiler::ast::NClassDeclaration* > ()->addClassSections(*yystack_[1].value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ());

            // Set class properties
            yylhs.value.as < amanda::compiler::ast::NClassDeclaration* > ()->setAccessModifier(yystack_[5].value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > ());

            // Clean-up
            delete yystack_[1].value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ();
        }
#line 1376 "compiler/Parser.cpp"
    break;

  case 15: // class_scope: class_section
#line 339 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > () = new NClassDeclaration::ClassSectionList(); yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ()->reserve(3); yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NClassDeclaration::ClassBodySection* > ()); }
#line 1382 "compiler/Parser.cpp"
    break;

  case 16: // class_scope: class_scope class_section
#line 340 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > () = yystack_[1].value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (); yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NClassDeclaration::ClassBodySection* > ()); }
#line 1388 "compiler/Parser.cpp"
    break;

  case 17: // class_section: access_modifier ':' class_statement_sequence
#line 345 "specs/grammar.y"
                                                {
                                                    yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassBodySection* > () = new NClassDeclaration::ClassBodySection(yystack_[2].value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > ());
                                                    yylhs.value.as < amanda::compiler::ast::NClassDeclaration::ClassBodySection* > ()->setStatements(*yystack_[0].value.as < amanda::compiler::ast::StatementList* > ());

                                                    // Clean-up the mess
                                                    delete yystack_[0].value.as < amanda::compiler::ast::StatementList* > ();
                                                }
#line 1400 "compiler/Parser.cpp"
    break;

  case 18: // class_statement_sequence: %empty
#line 355 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::StatementList* > () = new StatementList(); }
#line 1406 "compiler/Parser.cpp"
    break;

  case 19: // class_statement_sequence: class_statement
#line 356 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::StatementList* > () = new StatementList(); yylhs.value.as < amanda::compiler::ast::StatementList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1412 "compiler/Parser.cpp"
    break;

  case 20: // class_statement_sequence: class_statement_sequence class_statement
#line 357 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::StatementList* > () = yystack_[1].value.as < amanda::compiler::ast::StatementList* > (); yylhs.value.as < amanda::compiler::ast::StatementList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1418 "compiler/Parser.cpp"
    break;

  case 21: // class_statement: field_declaration ';'
#line 361 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[1].value.as < amanda::compiler::ast::NClassFieldDeclaration* > (); }
#line 1424 "compiler/Parser.cpp"
    break;

  case 22: // field_declaration: type id
#line 365 "specs/grammar.y"
                        { yylhs.value.as < amanda::compiler::ast::NClassFieldDeclaration* > () = new NClassFieldDeclaration(yystack_[1].value.as < amanda::core::String > (), yystack_[0].value.as < amanda::compiler::ast::NIdentifier* > ()); }
#line 1430 "compiler/Parser.cpp"
    break;

  case 23: // statement: simple_statement ';'
#line 370 "specs/grammar.y"
      { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[1].value.as < amanda::compiler::ast::NStatement* > (); }
#line 1436 "compiler/Parser.cpp"
    break;

  case 24: // statement: compound_statement
#line 371 "specs/grammar.y"
      { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NStatement* > (); }
#line 1442 "compiler/Parser.cpp"
    break;

  case 25: // simple_statement: return_statement
#line 375 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NReturnStatement* > (); }
#line 1448 "compiler/Parser.cpp"
    break;

  case 26: // simple_statement: expression_statement
#line 376 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NExpressionStatement* > (); }
#line 1454 "compiler/Parser.cpp"
    break;

  case 27: // compound_statement: if_statement
#line 380 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NConditionalStatement* > (); }
#line 1460 "compiler/Parser.cpp"
    break;

  case 28: // compound_statement: for_statement
#line 381 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NForLoopStatement* > (); }
#line 1466 "compiler/Parser.cpp"
    break;

  case 29: // compound_statement: while_statement
#line 382 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NStatement* > () = yystack_[0].value.as < amanda::compiler::ast::NWhileStatement* > (); }
#line 1472 "compiler/Parser.cpp"
    break;

  case 30: // expression_statement: function_call
#line 388 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[0].value.as < amanda::compiler::ast::NFunctionCall* > ()); }
#line 1478 "compiler/Parser.cpp"
    break;

  case 31: // expression_statement: variable_declaration
#line 389 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[0].value.as < amanda::compiler::ast::NVariableDeclaration* > ()); }
#line 1484 "compiler/Parser.cpp"
    break;

  case 32: // expression_statement: assignment_expression
#line 390 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NExpressionStatement* > () = new NExpressionStatement(yystack_[0].value.as < amanda::compiler::ast::NAssignmentExpression* > ()); }
#line 1490 "compiler/Parser.cpp"
    break;

  case 33: // return_statement: "return" expression
#line 395 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NReturnStatement* > () = new NReturnStatement(); }
#line 1496 "compiler/Parser.cpp"
    break;

  case 34: // return_statement: "return"
#line 396 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NReturnStatement* > () = new NReturnStatement(); }
#line 1502 "compiler/Parser.cpp"
    break;

  case 35: // if_statement: "if" '(' expression ')' '{' statement_sequence '}'
#line 402 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                        }
#line 1510 "compiler/Parser.cpp"
    break;

  case 36: // if_statement: "if" '(' expression ')' '{' statement_sequence '}' "else" '{' statement_sequence '}'
#line 407 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[8].value.as < amanda::compiler::ast::NExpression* > (), yystack_[5].value.as < amanda::compiler::ast::NBlock* > ()); yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addElseClause(yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()); 
                                                        }
#line 1518 "compiler/Parser.cpp"
    break;

  case 37: // if_statement: "if" '(' expression ')' '{' statement_sequence '}' multiple_else_if_clauses
#line 411 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[5].value.as < amanda::compiler::ast::NExpression* > (), yystack_[2].value.as < amanda::compiler::ast::NBlock* > ());
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addMultipleElseIfClauses(yystack_[0].value.as < amanda::compiler::ast::ConditionalStatementList > ());
                                                        }
#line 1527 "compiler/Parser.cpp"
    break;

  case 38: // if_statement: "if" '(' expression ')' '{' statement_sequence '}' multiple_else_if_clauses "else" '{' statement_sequence '}'
#line 416 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[9].value.as < amanda::compiler::ast::NExpression* > (), yystack_[6].value.as < amanda::compiler::ast::NBlock* > ());
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addMultipleElseIfClauses(yystack_[4].value.as < amanda::compiler::ast::ConditionalStatementList > ());
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > ()->addElseClause(yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                        }
#line 1537 "compiler/Parser.cpp"
    break;

  case 39: // if_statement: "if" '(' expression ')' statement
#line 422 "specs/grammar.y"
                                                        {
                                                            // Add a statement sequence
                                                            NBlock* block = new NBlock();
                                                            block->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ());

                                                            // Create the conditional statement
                                                            yylhs.value.as < amanda::compiler::ast::NConditionalStatement* > () = new NConditionalStatement(yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), block);
                                                        }
#line 1550 "compiler/Parser.cpp"
    break;

  case 40: // multiple_else_if_clauses: "else" "if" '(' expression ')' '{' statement_sequence '}'
#line 434 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::ConditionalStatementList > ().push_back(new NConditionalStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()));
                                                        }
#line 1558 "compiler/Parser.cpp"
    break;

  case 41: // multiple_else_if_clauses: multiple_else_if_clauses "else" "if" '(' expression ')' '{' statement_sequence '}'
#line 438 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::ConditionalStatementList > () = yystack_[8].value.as < amanda::compiler::ast::ConditionalStatementList > ();
                                                            yylhs.value.as < amanda::compiler::ast::ConditionalStatementList > ().push_back(new NConditionalStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ()));
                                                        }
#line 1567 "compiler/Parser.cpp"
    break;

  case 42: // for_statement: "for" '(' optional_expression ';' expression ';' optional_expression ')' '{' statement_sequence '}'
#line 446 "specs/grammar.y"
                                                        {
                                                            yylhs.value.as < amanda::compiler::ast::NForLoopStatement* > () = new NForLoopStatement(yystack_[8].value.as < amanda::compiler::ast::NExpression* > (), yystack_[6].value.as < amanda::compiler::ast::NExpression* > (), yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                        }
#line 1575 "compiler/Parser.cpp"
    break;

  case 43: // while_statement: "while" '(' expression ')' '{' statement_sequence '}'
#line 453 "specs/grammar.y"
                                                {
                                                    yylhs.value.as < amanda::compiler::ast::NWhileStatement* > () = new NWhileStatement(yystack_[4].value.as < amanda::compiler::ast::NExpression* > (), yystack_[1].value.as < amanda::compiler::ast::NBlock* > ());
                                                }
#line 1583 "compiler/Parser.cpp"
    break;

  case 44: // while_statement: "while" '(' expression ')' statement
#line 457 "specs/grammar.y"
                                                {
                                                    // Add a new scope to the while loop
                                                    NBlock* body = new NBlock();
                                                    body->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ());

                                                    yylhs.value.as < amanda::compiler::ast::NWhileStatement* > () = new NWhileStatement(yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), body);
                                                }
#line 1595 "compiler/Parser.cpp"
    break;

  case 45: // optional_expression: expression
#line 468 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NExpression* > (); }
#line 1601 "compiler/Parser.cpp"
    break;

  case 46: // optional_expression: %empty
#line 469 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = NULL; }
#line 1607 "compiler/Parser.cpp"
    break;

  case 47: // expression: id
#line 473 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NIdentifier* > (); }
#line 1613 "compiler/Parser.cpp"
    break;

  case 48: // expression: boolean_literal
#line 474 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NBoolean* > (); }
#line 1619 "compiler/Parser.cpp"
    break;

  case 49: // expression: numeric_literal
#line 475 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NExpression* > (); }
#line 1625 "compiler/Parser.cpp"
    break;

  case 50: // expression: variable_declaration
#line 476 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NVariableDeclaration* > (); }
#line 1631 "compiler/Parser.cpp"
    break;

  case 51: // expression: function_call
#line 477 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NFunctionCall* > (); }
#line 1637 "compiler/Parser.cpp"
    break;

  case 52: // expression: binary_operator
#line 478 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NBinaryOperator* > (); }
#line 1643 "compiler/Parser.cpp"
    break;

  case 53: // expression: assignment_expression
#line 479 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[0].value.as < amanda::compiler::ast::NAssignmentExpression* > (); }
#line 1649 "compiler/Parser.cpp"
    break;

  case 54: // expression: '(' expression ')'
#line 480 "specs/grammar.y"
                                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = yystack_[1].value.as < amanda::compiler::ast::NExpression* > (); }
#line 1655 "compiler/Parser.cpp"
    break;

  case 55: // function_call: name '(' expression_list ')'
#line 484 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NFunctionCall* > () = new NFunctionCall(yystack_[3].value.as < amanda::core::String > ()); yylhs.value.as < amanda::compiler::ast::NFunctionCall* > ()->addPassedArguments(*yystack_[1].value.as < amanda::compiler::ast::ExpressionList* > ()); delete yystack_[1].value.as < amanda::compiler::ast::ExpressionList* > (); }
#line 1661 "compiler/Parser.cpp"
    break;

  case 56: // variable_declaration: type id
#line 488 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NVariableDeclaration* > () = new NVariableDeclaration(yystack_[1].value.as < amanda::core::String > (), yystack_[0].value.as < amanda::compiler::ast::NIdentifier* > ()); }
#line 1667 "compiler/Parser.cpp"
    break;

  case 57: // variable_declaration: variable_declaration '=' expression
#line 489 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NVariableDeclaration* > () = yystack_[2].value.as < amanda::compiler::ast::NVariableDeclaration* > (); yylhs.value.as < amanda::compiler::ast::NVariableDeclaration* > ()->setAssignmentExpression(yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1673 "compiler/Parser.cpp"
    break;

  case 58: // assignment_expression: id '=' expression
#line 493 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NAssignmentExpression* > () = new NAssignmentExpression(yystack_[2].value.as < amanda::compiler::ast::NIdentifier* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1679 "compiler/Parser.cpp"
    break;

  case 59: // id: name
#line 498 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NIdentifier* > () = new NIdentifier(yystack_[0].value.as < amanda::core::String > ()); }
#line 1685 "compiler/Parser.cpp"
    break;

  case 60: // numeric_literal: "integer literal"
#line 503 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NExpression* > () = new NInteger(yystack_[0].value.as < amanda::core::String > ()); }
#line 1691 "compiler/Parser.cpp"
    break;

  case 61: // boolean_literal: "boolean literal"
#line 508 "specs/grammar.y"
                                { yylhs.value.as < amanda::compiler::ast::NBoolean* > () = new NBoolean(yystack_[0].value.as < bool > ()); }
#line 1697 "compiler/Parser.cpp"
    break;

  case 62: // expression_list: %empty
#line 513 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = new ExpressionList();                    }
#line 1703 "compiler/Parser.cpp"
    break;

  case 63: // expression_list: expression
#line 514 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = new ExpressionList(); yylhs.value.as < amanda::compiler::ast::ExpressionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1709 "compiler/Parser.cpp"
    break;

  case 64: // expression_list: expression_list ',' expression
#line 515 "specs/grammar.y"
                                        { yylhs.value.as < amanda::compiler::ast::ExpressionList* > () = yystack_[2].value.as < amanda::compiler::ast::ExpressionList* > (); yylhs.value.as < amanda::compiler::ast::ExpressionList* > ()->push_back(yystack_[0].value.as < amanda::compiler::ast::NExpression* > ());                   }
#line 1715 "compiler/Parser.cpp"
    break;

  case 65: // statement_sequence: %empty
#line 520 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = new NBlock(); }
#line 1721 "compiler/Parser.cpp"
    break;

  case 66: // statement_sequence: statement
#line 521 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = new NBlock(); yylhs.value.as < amanda::compiler::ast::NBlock* > ()->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1727 "compiler/Parser.cpp"
    break;

  case 67: // statement_sequence: statement_sequence statement
#line 522 "specs/grammar.y"
                                    { yylhs.value.as < amanda::compiler::ast::NBlock* > () = yystack_[1].value.as < amanda::compiler::ast::NBlock* > (); yylhs.value.as < amanda::compiler::ast::NBlock* > ()->addStatement(yystack_[0].value.as < amanda::compiler::ast::NStatement* > ()); }
#line 1733 "compiler/Parser.cpp"
    break;

  case 68: // type: simple_type
#line 527 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1739 "compiler/Parser.cpp"
    break;

  case 69: // type: reference_type
#line 528 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1745 "compiler/Parser.cpp"
    break;

  case 70: // type: type '[' ']'
#line 529 "specs/grammar.y"
                    { yylhs.value.as < amanda::core::String > () = "default-types::array@<"; yylhs.value.as < amanda::core::String > ().append(yystack_[2].value.as < amanda::core::String > ()).append(">"); }
#line 1751 "compiler/Parser.cpp"
    break;

  case 71: // simple_type: "void"
#line 533 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::void"; }
#line 1757 "compiler/Parser.cpp"
    break;

  case 72: // simple_type: "bool"
#line 534 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::bool"; }
#line 1763 "compiler/Parser.cpp"
    break;

  case 73: // simple_type: "byte"
#line 535 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::byte"; }
#line 1769 "compiler/Parser.cpp"
    break;

  case 74: // simple_type: "short"
#line 536 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::short"; }
#line 1775 "compiler/Parser.cpp"
    break;

  case 75: // simple_type: "int"
#line 537 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::int"; }
#line 1781 "compiler/Parser.cpp"
    break;

  case 76: // simple_type: "long"
#line 538 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::long"; }
#line 1787 "compiler/Parser.cpp"
    break;

  case 77: // simple_type: "float"
#line 539 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::float"; }
#line 1793 "compiler/Parser.cpp"
    break;

  case 78: // simple_type: "double"
#line 540 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::double"; }
#line 1799 "compiler/Parser.cpp"
    break;

  case 79: // reference_type: name
#line 544 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1805 "compiler/Parser.cpp"
    break;

  case 80: // reference_type: "string"
#line 545 "specs/grammar.y"
                { yylhs.value.as < amanda::core::String > () = "default-types::string"; }
#line 1811 "compiler/Parser.cpp"
    break;

  case 81: // name: simple_name
#line 550 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1817 "compiler/Parser.cpp"
    break;

  case 82: // name: qualified_name
#line 551 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1823 "compiler/Parser.cpp"
    break;

  case 83: // simple_name: "identifier"
#line 555 "specs/grammar.y"
      { yylhs.value.as < amanda::core::String > () = yystack_[0].value.as < amanda::core::String > (); }
#line 1829 "compiler/Parser.cpp"
    break;

  case 84: // qualified_name: "identifier" "'::'" "identifier"
#line 559 "specs/grammar.y"
                                            { yylhs.value.as < amanda::core::String > ().append(yystack_[2].value.as < amanda::core::String > ()).append("::").append(yystack_[0].value.as < amanda::core::String > ()); }
#line 1835 "compiler/Parser.cpp"
    break;

  case 85: // qualified_name: qualified_name "'::'" "identifier"
#line 560 "specs/grammar.y"
                                            { yylhs.value.as < amanda::core::String > () = yystack_[2].value.as < amanda::core::String > (); yylhs.value.as < amanda::core::String > ().append("::").append(yystack_[0].value.as < amanda::core::String > ()); }
#line 1841 "compiler/Parser.cpp"
    break;

  case 86: // access_modifier: "private"
#line 565 "specs/grammar.y"
                    { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > () = NClassDeclaration::createAccessModifierFromString("private"); }
#line 1847 "compiler/Parser.cpp"
    break;

  case 87: // access_modifier: "protected"
#line 566 "specs/grammar.y"
                    { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > () = NClassDeclaration::createAccessModifierFromString("protected"); }
#line 1853 "compiler/Parser.cpp"
    break;

  case 88: // access_modifier: "public"
#line 567 "specs/grammar.y"
                    { yylhs.value.as < amanda::compiler::ast::NClassDeclaration::AccessModifier > () = NClassDeclaration::createAccessModifierFromString("public"); }
#line 1859 "compiler/Parser.cpp"
    break;

  case 92: // binary_operator: expression '<' expression
#line 579 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Lesser, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1865 "compiler/Parser.cpp"
    break;

  case 93: // binary_operator: expression "'<='" expression
#line 580 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_LesserEquals, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1871 "compiler/Parser.cpp"
    break;

  case 94: // binary_operator: expression '>' expression
#line 581 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Greater, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1877 "compiler/Parser.cpp"
    break;

  case 95: // binary_operator: expression "'>='" expression
#line 582 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_GreaterEquals, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1883 "compiler/Parser.cpp"
    break;

  case 96: // binary_operator: expression "'=='" expression
#line 583 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Equals, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1889 "compiler/Parser.cpp"
    break;

  case 97: // binary_operator: expression "'!='" expression
#line 584 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_NotEquals, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1895 "compiler/Parser.cpp"
    break;

  case 98: // binary_operator: expression '+' expression
#line 585 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Sum, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1901 "compiler/Parser.cpp"
    break;

  case 99: // binary_operator: expression '-' expression
#line 586 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Sub, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1907 "compiler/Parser.cpp"
    break;

  case 100: // binary_operator: expression '/' expression
#line 587 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Div, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1913 "compiler/Parser.cpp"
    break;

  case 101: // binary_operator: expression '*' expression
#line 588 "specs/grammar.y"
                                            { yylhs.value.as < amanda::compiler::ast::NBinaryOperator* > () = new NBinaryOperator(BO_Mult, yystack_[2].value.as < amanda::compiler::ast::NExpression* > (), yystack_[0].value.as < amanda::compiler::ast::NExpression* > ()); }
#line 1919 "compiler/Parser.cpp"
    break;


#line 1923 "compiler/Parser.cpp"

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
  "optional_expression", "expression", "function_call",
  "variable_declaration", "assignment_expression", "id", "numeric_literal",
  "boolean_literal", "expression_list", "statement_sequence", "type",
  "simple_type", "reference_type", "name", "simple_name", "qualified_name",
  "access_modifier", "argument_list", "binary_operator", YY_NULLPTR
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

  const signed char DefaultParser::yytable_ninf_ = -80;

  const short
  DefaultParser::yypact_[] =
  {
     595,   -42,    22,   -61,   -61,   -61,    33,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,    42,   595,   -61,   -61,
     -61,   -61,   -61,    -4,   -61,   -61,   -61,   -61,     9,    36,
      58,   -32,    -9,    -1,   -61,   -61,    12,    10,    65,    74,
     -61,   595,   595,   -61,   269,   -61,   -61,     7,   256,   595,
       1,   -23,    25,   -61,   -61,    11,   269,     8,   -61,    23,
     616,     5,   -61,   -61,   269,    26,    37,   560,    38,   -61,
      24,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    28,   -61,
      34,   302,     6,     2,   -61,   269,   -61,    35,     6,   560,
     560,   -61,   -61,   560,   723,   -61,    28,   -61,    34,   -61,
     -61,   -61,   560,   -61,   560,   560,   -61,   -61,   -61,   -61,
     560,   -61,   -61,   -61,    40,   723,   615,   639,   560,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   663,   723,
     723,   723,   -17,   560,   514,   -61,   -44,   -44,   -44,   -44,
     -61,   -40,   -40,   -61,   -44,   -44,   536,   -61,   560,   669,
     616,   -61,   616,   -61,   723,   560,   324,   355,    45,    90,
     -61,    41,    -8,    94,   616,    53,   616,     0,   377,   560,
     408,    55,   616,   -61,   693,   -61,   560,   430,    43,   717,
     -61,   616,    47,   461,   616,   -61,   483,   -61
  };

  const signed char
  DefaultParser::yydefact_[] =
  {
       3,    83,     0,    86,    87,    88,     0,    72,    73,    74,
      75,    76,    80,    71,    77,    78,     0,     2,     4,     6,
       7,     9,     8,     0,    68,    69,    79,    81,    82,     0,
       0,    83,     0,     0,     1,     5,     0,     0,     0,     0,
      84,     3,     3,    12,    89,    70,    85,     0,     0,    11,
       0,     0,     0,    10,    90,     0,     0,     0,    15,     0,
      65,     0,    14,    16,    18,     0,     0,    34,     0,    66,
       0,    24,    26,    25,    27,    28,    29,    30,    31,    32,
       0,     0,     0,    59,    91,    17,    19,     0,     0,    46,
       0,    61,    60,     0,    33,    51,    50,    53,    47,    49,
      48,    52,     0,    23,     0,     0,    13,    67,    56,    59,
      62,    20,    21,    22,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    63,     0,     0,     0,    54,    93,    95,    96,    97,
     101,    98,    99,   100,    92,    94,     0,    55,     0,     0,
      65,    39,    65,    44,    64,    46,     0,     0,     0,    35,
      43,     0,     0,    37,    65,     0,    65,     0,     0,     0,
       0,     0,    65,    42,     0,    36,     0,     0,     0,     0,
      38,    65,     0,     0,    65,    40,     0,    41
  };

  const short
  DefaultParser::yypgoto_[] =
  {
     -61,   -61,   -16,   -13,   -61,   -61,   -61,   -61,   -61,    61,
     -61,    30,   -61,    51,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -33,   145,   -21,    18,    59,   -60,   -61,   -61,
     -61,   424,    13,   -61,   -61,     3,   -61,   -61,   -28,   -61,
     -61
  };

  const unsigned char
  DefaultParser::yydefgoto_[] =
  {
       0,    16,    17,    18,    19,    20,    21,    22,    57,    58,
      85,    86,    87,    69,    70,    71,    72,    73,    74,   163,
      75,    76,   114,   115,    95,    96,    97,    98,    99,   100,
     132,    81,    82,    24,    25,    83,    27,    28,    29,    51,
     101
  };

  const short
  DefaultParser::yytable_[] =
  {
      80,    36,    30,    26,    35,    32,    54,   -79,   165,    33,
      84,     1,    30,    23,   122,   123,   171,   124,   122,   125,
      26,    80,   108,   125,    59,    48,    49,    31,   113,    59,
      23,     3,     4,     5,    55,    35,    35,    56,     1,    77,
     147,    41,    34,   148,    26,    26,    39,    26,     3,     4,
       5,    26,    26,    38,    23,    23,    42,    50,   110,    26,
      77,    23,    23,    40,    43,   166,    37,    26,    44,    61,
      46,    37,   -79,   172,    80,    37,    37,    88,    78,    47,
      52,    45,    89,    62,    60,   109,    80,    64,    26,   103,
      80,   109,    80,    90,   102,   104,    80,    80,    88,    78,
     112,   105,   161,   162,    80,   133,    80,   167,    80,   169,
      80,   176,    80,    77,   164,   111,   181,    80,    63,    79,
     184,    80,   158,    80,    80,    77,    80,     0,     0,    77,
       0,    77,   107,     0,     0,    77,    77,     0,     0,     0,
      79,     0,     0,    77,     0,    77,     0,    77,     0,    77,
       0,    77,    78,     0,     0,     0,    77,     0,     0,     0,
      77,     0,    77,    77,    78,    77,     0,     0,    78,     0,
      78,     0,     0,     0,    78,    78,     0,     0,     0,     0,
       0,     0,    78,     0,    78,   151,    78,     0,    78,     0,
      78,     0,     0,    79,     0,    78,     0,   153,     0,    78,
       0,    78,    78,     0,    78,    79,     0,   107,   107,    79,
       0,    79,    94,     0,     0,    79,    79,     0,     0,   107,
       0,   107,     0,    79,     0,    79,     0,    79,   107,    79,
       0,    79,     0,     0,   107,   116,    79,   107,   117,     0,
      79,     0,    79,    79,     0,    79,     0,   128,     0,   129,
     130,     0,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     1,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     1,     2,     0,     0,   149,     3,
       4,     5,     0,     0,     0,     6,     0,     7,     8,     9,
      10,    11,     0,   154,     0,    12,     0,    13,    14,    15,
       7,     8,     9,    10,    11,     0,     0,     1,    12,     0,
      13,    14,    15,     0,   174,     0,     0,    65,    66,     0,
       0,   179,     0,     0,     0,     0,     0,     0,    67,     1,
       0,    53,    68,     7,     8,     9,    10,    11,     0,    65,
      66,    12,     0,    13,    14,    15,     0,     0,     0,     0,
      67,     0,     0,     0,    68,     7,     8,     9,    10,    11,
       1,     0,     0,    12,     0,    13,    14,    15,     0,     0,
      65,    66,     0,     0,     0,     0,     0,   106,     0,     0,
       0,    67,     1,     0,     0,    68,     7,     8,     9,    10,
      11,     0,    65,    66,    12,     0,    13,    14,    15,   159,
       0,     0,     0,    67,     0,     0,     0,    68,     7,     8,
       9,    10,    11,     1,     0,     0,    12,     0,    13,    14,
      15,     0,     0,    65,    66,     0,     0,     0,     0,     0,
     160,     0,     0,     0,    67,     1,     0,     0,    68,     7,
       8,     9,    10,    11,     0,    65,    66,    12,     0,    13,
      14,    15,   173,     0,     0,     0,    67,     0,     0,     0,
      68,     7,     8,     9,    10,    11,     1,     0,     0,    12,
       0,    13,    14,    15,     0,     0,    65,    66,     0,     0,
       0,     0,     0,   175,     0,     0,     0,    67,     1,     0,
       0,    68,     7,     8,     9,    10,    11,     0,    65,    66,
      12,     0,    13,    14,    15,   180,     0,     0,     0,    67,
       0,     0,     0,    68,     7,     8,     9,    10,    11,     1,
       0,     0,    12,     0,    13,    14,    15,     0,     0,    65,
      66,     0,     0,     0,     0,     0,   185,     0,     0,     0,
      67,     1,     0,     0,    68,     7,     8,     9,    10,    11,
       0,    65,    66,    12,     0,    13,    14,    15,   187,     0,
       0,     0,    67,    91,    92,     1,    68,     7,     8,     9,
      10,    11,     0,     0,   156,    12,   157,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,   150,   168,     0,
     170,     7,     8,     9,    10,    11,   177,     0,     0,    12,
       1,    13,    14,    15,     0,   183,     0,     0,   186,   152,
       0,     0,     0,     0,     2,     0,    93,     0,     3,     4,
       5,     1,     0,     0,     6,     0,     7,     8,     9,    10,
      11,    65,    66,     0,    12,     0,    13,    14,    15,     0,
       0,     0,    67,     0,     0,     0,    68,     7,     8,     9,
      10,    11,     0,     0,     0,    12,     0,    13,    14,    15,
     118,   119,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   122,   123,     0,   124,     0,   125,     0,
       0,   126,     0,   127,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   122,   123,     0,
     124,     0,   125,     0,     0,   126,     0,   127,   118,   119,
     120,   121,     0,     0,   118,   119,   120,   121,     0,     0,
     146,   122,   123,     0,   124,     0,   125,   122,   123,   126,
     124,   127,   125,     0,   155,   126,     0,   127,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
     178,   122,   123,     0,   124,     0,   125,     0,     0,   126,
       0,   127,   118,   119,   120,   121,     0,     0,   118,   119,
     120,   121,     0,     0,   182,   122,   123,     0,   124,     0,
     125,   122,   123,   126,   124,   127,   125,     0,     0,   126,
       0,   127
  };

  const short
  DefaultParser::yycheck_[] =
  {
      60,     5,    44,     0,    17,     2,     5,     5,    16,     6,
       5,     5,    44,     0,    58,    59,    16,    61,    58,    63,
      17,    81,    82,    63,    52,    41,    42,     5,    88,    57,
      17,    23,    24,    25,    57,    48,    49,    60,     5,    60,
      57,    73,     0,    60,    41,    42,    10,    44,    23,    24,
      25,    48,    49,    44,    41,    42,    65,    44,    56,    56,
      81,    48,    49,     5,    65,    73,    70,    64,    56,    56,
       5,    70,    70,    73,   134,    70,    70,    64,    60,     5,
      73,    71,    56,    75,    73,    82,   146,    64,    85,    65,
     150,    88,   152,    56,    56,    67,   156,   157,    85,    81,
      65,    67,    57,    13,   164,    65,   166,    13,   168,    56,
     170,    56,   172,   134,    73,    85,    73,   177,    57,    60,
      73,   181,   155,   183,   184,   146,   186,    -1,    -1,   150,
      -1,   152,    81,    -1,    -1,   156,   157,    -1,    -1,    -1,
      81,    -1,    -1,   164,    -1,   166,    -1,   168,    -1,   170,
      -1,   172,   134,    -1,    -1,    -1,   177,    -1,    -1,    -1,
     181,    -1,   183,   184,   146,   186,    -1,    -1,   150,    -1,
     152,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,
      -1,    -1,   164,    -1,   166,   134,   168,    -1,   170,    -1,
     172,    -1,    -1,   134,    -1,   177,    -1,   146,    -1,   181,
      -1,   183,   184,    -1,   186,   146,    -1,   156,   157,   150,
      -1,   152,    67,    -1,    -1,   156,   157,    -1,    -1,   168,
      -1,   170,    -1,   164,    -1,   166,    -1,   168,   177,   170,
      -1,   172,    -1,    -1,   183,    90,   177,   186,    93,    -1,
     181,    -1,   183,   184,    -1,   186,    -1,   102,    -1,   104,
     105,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,     5,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,     5,    19,    -1,    -1,   133,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    -1,   148,    -1,    39,    -1,    41,    42,    43,
      31,    32,    33,    34,    35,    -1,    -1,     5,    39,    -1,
      41,    42,    43,    -1,   169,    -1,    -1,    15,    16,    -1,
      -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    26,     5,
      -1,    75,    30,    31,    32,    33,    34,    35,    -1,    15,
      16,    39,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
       5,    -1,    -1,    39,    -1,    41,    42,    43,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    26,     5,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,    15,    16,    39,    -1,    41,    42,    43,    75,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,     5,    -1,    -1,    39,    -1,    41,    42,
      43,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    26,     5,    -1,    -1,    30,    31,
      32,    33,    34,    35,    -1,    15,    16,    39,    -1,    41,
      42,    43,    75,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,     5,    -1,    -1,    39,
      -1,    41,    42,    43,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    26,     5,    -1,
      -1,    30,    31,    32,    33,    34,    35,    -1,    15,    16,
      39,    -1,    41,    42,    43,    75,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,     5,
      -1,    -1,    39,    -1,    41,    42,    43,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      26,     5,    -1,    -1,    30,    31,    32,    33,    34,    35,
      -1,    15,    16,    39,    -1,    41,    42,    43,    75,    -1,
      -1,    -1,    26,     3,     4,     5,    30,    31,    32,    33,
      34,    35,    -1,    -1,   150,    39,   152,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,   164,    -1,
     166,    31,    32,    33,    34,    35,   172,    -1,    -1,    39,
       5,    41,    42,    43,    -1,   181,    -1,    -1,   184,    73,
      -1,    -1,    -1,    -1,    19,    -1,    56,    -1,    23,    24,
      25,     5,    -1,    -1,    29,    -1,    31,    32,    33,    34,
      35,    15,    16,    -1,    39,    -1,    41,    42,    43,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    -1,    41,    42,    43,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    -1,    61,    -1,    63,    -1,
      -1,    66,    -1,    68,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,
      61,    -1,    63,    -1,    -1,    66,    -1,    68,    45,    46,
      47,    48,    -1,    -1,    45,    46,    47,    48,    -1,    -1,
      57,    58,    59,    -1,    61,    -1,    63,    58,    59,    66,
      61,    68,    63,    -1,    65,    66,    -1,    68,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    61,    -1,    63,    -1,    -1,    66,
      -1,    68,    45,    46,    47,    48,    -1,    -1,    45,    46,
      47,    48,    -1,    -1,    57,    58,    59,    -1,    61,    -1,
      63,    58,    59,    66,    61,    68,    63,    -1,    -1,    66,
      -1,    68
  };

  const signed char
  DefaultParser::yystos_[] =
  {
       0,     5,    19,    23,    24,    25,    29,    31,    32,    33,
      34,    35,    39,    41,    42,    43,    78,    79,    80,    81,
      82,    83,    84,   109,   110,   111,   112,   113,   114,   115,
      44,     5,   112,   112,     0,    80,     5,    70,    44,    10,
       5,    73,    65,    65,    56,    71,     5,     5,    79,    79,
     109,   116,    73,    75,     5,    57,    60,    85,    86,   115,
      73,   109,    75,    86,    64,    15,    16,    26,    30,    90,
      91,    92,    93,    94,    95,    97,    98,   101,   102,   103,
     104,   108,   109,   112,     5,    87,    88,    89,   109,    56,
      56,     3,     4,    56,   100,   101,   102,   103,   104,   105,
     106,   117,    56,    65,    67,    67,    75,    90,   104,   112,
      56,    88,    65,   104,    99,   100,   100,   100,    45,    46,
      47,    48,    58,    59,    61,    63,    66,    68,   100,   100,
     100,   100,   107,    65,    57,    57,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,    57,    57,    60,   100,
      73,    90,    73,    90,   100,    65,   108,   108,    99,    75,
      75,    57,    13,    96,    73,    16,    73,    13,   108,    56,
     108,    16,    73,    75,   100,    75,    56,   108,    57,   100,
      75,    73,    57,   108,    73,    75,   108,    75
  };

  const signed char
  DefaultParser::yyr1_[] =
  {
       0,    77,    78,    79,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    83,    84,    85,    85,    86,    87,    87,
      87,    88,    89,    90,    90,    91,    91,    92,    92,    92,
      93,    93,    93,    94,    94,    95,    95,    95,    95,    95,
      96,    96,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   102,   102,   103,   104,
     105,   106,   107,   107,   107,   108,   108,   108,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   111,
     111,   112,   112,   113,   114,   114,   115,   115,   115,   116,
     116,   116,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117
  };

  const signed char
  DefaultParser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       5,     4,     3,     8,     6,     1,     2,     3,     0,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     7,    11,     8,    12,     5,
       8,     9,    11,     7,     5,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     2,     3,     3,     1,
       1,     1,     0,     1,     3,     0,     1,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     0,
       2,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3
  };




#if YYDEBUG
  const short
  DefaultParser::yyrline_[] =
  {
       0,   268,   268,   284,   285,   286,   292,   293,   294,   295,
     299,   300,   314,   318,   322,   339,   340,   344,   355,   356,
     357,   361,   365,   370,   371,   375,   376,   380,   381,   382,
     388,   389,   390,   395,   396,   401,   406,   410,   415,   421,
     433,   437,   445,   452,   456,   468,   469,   473,   474,   475,
     476,   477,   478,   479,   480,   484,   488,   489,   493,   498,
     503,   508,   513,   514,   515,   520,   521,   522,   527,   528,
     529,   533,   534,   535,   536,   537,   538,   539,   540,   544,
     545,   550,   551,   555,   559,   560,   565,   566,   567,   572,
     573,   574,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588
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
#line 2741 "compiler/Parser.cpp"

#line 591 "specs/grammar.y"

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
