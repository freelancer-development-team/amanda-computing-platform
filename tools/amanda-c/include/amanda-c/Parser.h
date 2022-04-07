// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file include/amanda-c/Parser.h
 ** Define the amanda::compiler::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_INCLUDE_AMANDA_C_PARSER_H_INCLUDED
# define YY_YY_INCLUDE_AMANDA_C_PARSER_H_INCLUDED
// "%code requires" blocks.
#line 79 "specs/grammar.y"


    #include <amanda-vm/TypeSystem.h>
    #include <amanda-c/ast-package.h>

    // C++ API
    #include <vector>

    namespace amanda {
        namespace compiler
        {
            class Scanner;
            class CompilationContext;

            namespace ast
            {

            // Typedefs
            typedef std::vector<amanda::compiler::ast::NConditionalStatement*> ConditionalStatementList;

            }
        }
    }

#line 74 "include/amanda-c/Parser.h"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include <amanda-c/ParserLocations.h>


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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 53 "specs/grammar.y"
namespace amanda { namespace compiler {
#line 204 "include/amanda-c/Parser.h"




  /// A Bison parser.
  class DefaultParser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // multiple_else_if_clauses
      char dummy1[sizeof (amanda::compiler::ast::ConditionalStatementList)];

      // expression_list
      char dummy2[sizeof (amanda::compiler::ast::ExpressionList*)];

      // assignment_expression
      char dummy3[sizeof (amanda::compiler::ast::NAssignmentExpression*)];

      // binary_operator
      char dummy4[sizeof (amanda::compiler::ast::NBinaryOperator*)];

      // statement_sequence
      char dummy5[sizeof (amanda::compiler::ast::NBlock*)];

      // boolean_literal
      char dummy6[sizeof (amanda::compiler::ast::NBoolean*)];

      // class_declaration
      char dummy7[sizeof (amanda::compiler::ast::NClassDeclaration*)];

      // access_modifier
      char dummy8[sizeof (amanda::compiler::ast::NClassDeclaration::AccessModifier)];

      // class_section
      char dummy9[sizeof (amanda::compiler::ast::NClassDeclaration::ClassBodySection*)];

      // class_scope
      char dummy10[sizeof (amanda::compiler::ast::NClassDeclaration::ClassSectionList*)];

      // field_declaration
      char dummy11[sizeof (amanda::compiler::ast::NClassFieldDeclaration*)];

      // compilation_unit
      char dummy12[sizeof (amanda::compiler::ast::NCompilationUnit*)];

      // if_statement
      char dummy13[sizeof (amanda::compiler::ast::NConditionalStatement*)];

      // declaration
      char dummy14[sizeof (amanda::compiler::ast::NDeclaration*)];

      // declarations
      char dummy15[sizeof (amanda::compiler::ast::NDeclarationBlock*)];

      // optional_expression
      // expression
      // numeric_literal
      char dummy16[sizeof (amanda::compiler::ast::NExpression*)];

      // expression_statement
      char dummy17[sizeof (amanda::compiler::ast::NExpressionStatement*)];

      // for_statement
      char dummy18[sizeof (amanda::compiler::ast::NForLoopStatement*)];

      // function_call
      char dummy19[sizeof (amanda::compiler::ast::NFunctionCall*)];

      // function_declaration
      char dummy20[sizeof (amanda::compiler::ast::NFunctionDeclaration*)];

      // id
      char dummy21[sizeof (amanda::compiler::ast::NIdentifier*)];

      // namespace_declaration
      char dummy22[sizeof (amanda::compiler::ast::NNamespaceDeclaration*)];

      // return_statement
      char dummy23[sizeof (amanda::compiler::ast::NReturnStatement*)];

      // class_statement
      // statement
      // simple_statement
      // compound_statement
      char dummy24[sizeof (amanda::compiler::ast::NStatement*)];

      // using_declaration
      char dummy25[sizeof (amanda::compiler::ast::NUsingDeclaration*)];

      // variable_declaration
      char dummy26[sizeof (amanda::compiler::ast::NVariableDeclaration*)];

      // while_statement
      char dummy27[sizeof (amanda::compiler::ast::NWhileStatement*)];

      // class_statement_sequence
      char dummy28[sizeof (amanda::compiler::ast::StatementList*)];

      // "integer literal"
      // "identifier"
      // type
      // simple_type
      // reference_type
      // name
      // simple_name
      // qualified_name
      char dummy29[sizeof (amanda::core::String)];

      // "boolean literal"
      char dummy30[sizeof (bool)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOKEN_YYEMPTY = -2,
    TOKEN_EOF = 0,                 // "end of file"
    TOKEN_YYerror = 256,           // error
    TOKEN_YYUNDEF = 257,           // "invalid token"
    TOKEN_BOOLEAN = 258,           // "boolean literal"
    TOKEN_INTEGER = 259,           // "integer literal"
    TOKEN_IDENTIFIER = 260,        // "identifier"
    TOKEN_AND = 261,               // "and"
    TOKEN_AS = 262,                // "as"
    TOKEN_BREAK = 263,             // "break"
    TOKEN_CASE = 264,              // "case"
    TOKEN_CLASS = 265,             // "class"
    TOKEN_DELETE = 266,            // "delete"
    TOKEN_DO = 267,                // "do"
    TOKEN_ELSE = 268,              // "else"
    TOKEN_EXCEPT = 269,            // "except"
    TOKEN_FOR = 270,               // "for"
    TOKEN_IF = 271,                // "if"
    TOKEN_IS = 272,                // "is"
    TOKEN_INTERFACE = 273,         // "interface"
    TOKEN_NAMESPACE = 274,         // "namespace"
    TOKEN_NEW = 275,               // "new"
    TOKEN_NOT = 276,               // "not"
    TOKEN_OR = 277,                // "or"
    TOKEN_PRIVATE = 278,           // "private"
    TOKEN_PROTECTED = 279,         // "protected"
    TOKEN_PUBLIC = 280,            // "public"
    TOKEN_RETURN = 281,            // "return"
    TOKEN_SWITCH = 282,            // "switch"
    TOKEN_TRY = 283,               // "try"
    TOKEN_USING = 284,             // "using"
    TOKEN_WHILE = 285,             // "while"
    TOKEN_BOOL = 286,              // "bool"
    TOKEN_BYTE = 287,              // "byte"
    TOKEN_SHORT = 288,             // "short"
    TOKEN_INT = 289,               // "int"
    TOKEN_LONG = 290,              // "long"
    TOKEN_USHORT = 291,            // "ushort"
    TOKEN_UINT = 292,              // "uint"
    TOKEN_ULONG = 293,             // "ulong"
    TOKEN_STRING = 294,            // "string"
    TOKEN_CHAR = 295,              // "char"
    TOKEN_VOID = 296,              // "void"
    TOKEN_FLOAT = 297,             // "float"
    TOKEN_DOUBLE = 298,            // "double"
    TOKEN_SCOPE_OP = 299,          // "'::'"
    TOKEN_LE = 300,                // "'<='"
    TOKEN_GE = 301,                // "'>='"
    TOKEN_EQ = 302,                // "'=='"
    TOKEN_NE = 303,                // "'!='"
    TOKEN_PLUSPLUS = 304,          // "'++'"
    TOKEN_MINUSMINUS = 305         // "'--'"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 77, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_BOOLEAN = 3,                           // "boolean literal"
        S_INTEGER = 4,                           // "integer literal"
        S_IDENTIFIER = 5,                        // "identifier"
        S_AND = 6,                               // "and"
        S_AS = 7,                                // "as"
        S_BREAK = 8,                             // "break"
        S_CASE = 9,                              // "case"
        S_CLASS = 10,                            // "class"
        S_DELETE = 11,                           // "delete"
        S_DO = 12,                               // "do"
        S_ELSE = 13,                             // "else"
        S_EXCEPT = 14,                           // "except"
        S_FOR = 15,                              // "for"
        S_IF = 16,                               // "if"
        S_IS = 17,                               // "is"
        S_INTERFACE = 18,                        // "interface"
        S_NAMESPACE = 19,                        // "namespace"
        S_NEW = 20,                              // "new"
        S_NOT = 21,                              // "not"
        S_OR = 22,                               // "or"
        S_PRIVATE = 23,                          // "private"
        S_PROTECTED = 24,                        // "protected"
        S_PUBLIC = 25,                           // "public"
        S_RETURN = 26,                           // "return"
        S_SWITCH = 27,                           // "switch"
        S_TRY = 28,                              // "try"
        S_USING = 29,                            // "using"
        S_WHILE = 30,                            // "while"
        S_BOOL = 31,                             // "bool"
        S_BYTE = 32,                             // "byte"
        S_SHORT = 33,                            // "short"
        S_INT = 34,                              // "int"
        S_LONG = 35,                             // "long"
        S_USHORT = 36,                           // "ushort"
        S_UINT = 37,                             // "uint"
        S_ULONG = 38,                            // "ulong"
        S_STRING = 39,                           // "string"
        S_CHAR = 40,                             // "char"
        S_VOID = 41,                             // "void"
        S_FLOAT = 42,                            // "float"
        S_DOUBLE = 43,                           // "double"
        S_SCOPE_OP = 44,                         // "'::'"
        S_LE = 45,                               // "'<='"
        S_GE = 46,                               // "'>='"
        S_EQ = 47,                               // "'=='"
        S_NE = 48,                               // "'!='"
        S_PLUSPLUS = 49,                         // "'++'"
        S_MINUSMINUS = 50,                       // "'--'"
        S_51_ = 51,                              // '!'
        S_52_ = 52,                              // '#'
        S_53_ = 53,                              // '$'
        S_54_ = 54,                              // '%'
        S_55_ = 55,                              // '&'
        S_56_ = 56,                              // '('
        S_57_ = 57,                              // ')'
        S_58_ = 58,                              // '*'
        S_59_ = 59,                              // '+'
        S_60_ = 60,                              // ','
        S_61_ = 61,                              // '-'
        S_62_ = 62,                              // '.'
        S_63_ = 63,                              // '/'
        S_64_ = 64,                              // ':'
        S_65_ = 65,                              // ';'
        S_66_ = 66,                              // '<'
        S_67_ = 67,                              // '='
        S_68_ = 68,                              // '>'
        S_69_ = 69,                              // '?'
        S_70_ = 70,                              // '['
        S_71_ = 71,                              // ']'
        S_72_ = 72,                              // '^'
        S_73_ = 73,                              // '{'
        S_74_ = 74,                              // '|'
        S_75_ = 75,                              // '}'
        S_76_ = 76,                              // '~'
        S_YYACCEPT = 77,                         // $accept
        S_compilation_unit = 78,                 // compilation_unit
        S_declarations = 79,                     // declarations
        S_declaration = 80,                      // declaration
        S_namespace_declaration = 81,            // namespace_declaration
        S_using_declaration = 82,                // using_declaration
        S_function_declaration = 83,             // function_declaration
        S_class_declaration = 84,                // class_declaration
        S_class_scope = 85,                      // class_scope
        S_class_section = 86,                    // class_section
        S_class_statement_sequence = 87,         // class_statement_sequence
        S_class_statement = 88,                  // class_statement
        S_field_declaration = 89,                // field_declaration
        S_statement = 90,                        // statement
        S_simple_statement = 91,                 // simple_statement
        S_compound_statement = 92,               // compound_statement
        S_expression_statement = 93,             // expression_statement
        S_return_statement = 94,                 // return_statement
        S_if_statement = 95,                     // if_statement
        S_multiple_else_if_clauses = 96,         // multiple_else_if_clauses
        S_for_statement = 97,                    // for_statement
        S_while_statement = 98,                  // while_statement
        S_optional_expression = 99,              // optional_expression
        S_expression = 100,                      // expression
        S_function_call = 101,                   // function_call
        S_variable_declaration = 102,            // variable_declaration
        S_assignment_expression = 103,           // assignment_expression
        S_id = 104,                              // id
        S_numeric_literal = 105,                 // numeric_literal
        S_boolean_literal = 106,                 // boolean_literal
        S_expression_list = 107,                 // expression_list
        S_statement_sequence = 108,              // statement_sequence
        S_type = 109,                            // type
        S_simple_type = 110,                     // simple_type
        S_reference_type = 111,                  // reference_type
        S_name = 112,                            // name
        S_simple_name = 113,                     // simple_name
        S_qualified_name = 114,                  // qualified_name
        S_access_modifier = 115,                 // access_modifier
        S_argument_list = 116,                   // argument_list
        S_binary_operator = 117                  // binary_operator
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        value.move< amanda::compiler::ast::ConditionalStatementList > (std::move (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< amanda::compiler::ast::ExpressionList* > (std::move (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< amanda::compiler::ast::NAssignmentExpression* > (std::move (that.value));
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.move< amanda::compiler::ast::NBinaryOperator* > (std::move (that.value));
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.move< amanda::compiler::ast::NBlock* > (std::move (that.value));
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        value.move< amanda::compiler::ast::NBoolean* > (std::move (that.value));
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        value.move< amanda::compiler::ast::NClassDeclaration* > (std::move (that.value));
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        value.move< amanda::compiler::ast::NClassDeclaration::AccessModifier > (std::move (that.value));
        break;

      case symbol_kind::S_class_section: // class_section
        value.move< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > (std::move (that.value));
        break;

      case symbol_kind::S_class_scope: // class_scope
        value.move< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (std::move (that.value));
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        value.move< amanda::compiler::ast::NClassFieldDeclaration* > (std::move (that.value));
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.move< amanda::compiler::ast::NCompilationUnit* > (std::move (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< amanda::compiler::ast::NConditionalStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< amanda::compiler::ast::NDeclaration* > (std::move (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< amanda::compiler::ast::NDeclarationBlock* > (std::move (that.value));
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.move< amanda::compiler::ast::NExpression* > (std::move (that.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.move< amanda::compiler::ast::NExpressionStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_for_statement: // for_statement
        value.move< amanda::compiler::ast::NForLoopStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< amanda::compiler::ast::NFunctionCall* > (std::move (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.move< amanda::compiler::ast::NFunctionDeclaration* > (std::move (that.value));
        break;

      case symbol_kind::S_id: // id
        value.move< amanda::compiler::ast::NIdentifier* > (std::move (that.value));
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        value.move< amanda::compiler::ast::NNamespaceDeclaration* > (std::move (that.value));
        break;

      case symbol_kind::S_return_statement: // return_statement
        value.move< amanda::compiler::ast::NReturnStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< amanda::compiler::ast::NStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.move< amanda::compiler::ast::NUsingDeclaration* > (std::move (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< amanda::compiler::ast::NVariableDeclaration* > (std::move (that.value));
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.move< amanda::compiler::ast::NWhileStatement* > (std::move (that.value));
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        value.move< amanda::compiler::ast::StatementList* > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< amanda::core::String > (std::move (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        value.move< bool > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::ConditionalStatementList&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::ConditionalStatementList& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::ExpressionList*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::ExpressionList*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NAssignmentExpression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NAssignmentExpression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NBinaryOperator*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NBinaryOperator*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NBlock*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NBlock*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NBoolean*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NBoolean*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NClassDeclaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NClassDeclaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NClassDeclaration::AccessModifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NClassDeclaration::AccessModifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NClassDeclaration::ClassBodySection*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NClassDeclaration::ClassBodySection*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NClassDeclaration::ClassSectionList*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NClassDeclaration::ClassSectionList*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NClassFieldDeclaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NClassFieldDeclaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NCompilationUnit*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NCompilationUnit*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NConditionalStatement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NConditionalStatement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NDeclaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NDeclaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NDeclarationBlock*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NDeclarationBlock*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NExpression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NExpression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NExpressionStatement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NExpressionStatement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NForLoopStatement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NForLoopStatement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NFunctionCall*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NFunctionCall*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NFunctionDeclaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NFunctionDeclaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NIdentifier*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NIdentifier*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NNamespaceDeclaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NNamespaceDeclaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NReturnStatement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NReturnStatement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NStatement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NStatement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NUsingDeclaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NUsingDeclaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NVariableDeclaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NVariableDeclaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::NWhileStatement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::NWhileStatement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::compiler::ast::StatementList*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::compiler::ast::StatementList*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, amanda::core::String&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const amanda::core::String& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        value.template destroy< amanda::compiler::ast::ConditionalStatementList > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.template destroy< amanda::compiler::ast::ExpressionList* > ();
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.template destroy< amanda::compiler::ast::NAssignmentExpression* > ();
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.template destroy< amanda::compiler::ast::NBinaryOperator* > ();
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.template destroy< amanda::compiler::ast::NBlock* > ();
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        value.template destroy< amanda::compiler::ast::NBoolean* > ();
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        value.template destroy< amanda::compiler::ast::NClassDeclaration* > ();
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        value.template destroy< amanda::compiler::ast::NClassDeclaration::AccessModifier > ();
        break;

      case symbol_kind::S_class_section: // class_section
        value.template destroy< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > ();
        break;

      case symbol_kind::S_class_scope: // class_scope
        value.template destroy< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > ();
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        value.template destroy< amanda::compiler::ast::NClassFieldDeclaration* > ();
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.template destroy< amanda::compiler::ast::NCompilationUnit* > ();
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.template destroy< amanda::compiler::ast::NConditionalStatement* > ();
        break;

      case symbol_kind::S_declaration: // declaration
        value.template destroy< amanda::compiler::ast::NDeclaration* > ();
        break;

      case symbol_kind::S_declarations: // declarations
        value.template destroy< amanda::compiler::ast::NDeclarationBlock* > ();
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.template destroy< amanda::compiler::ast::NExpression* > ();
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.template destroy< amanda::compiler::ast::NExpressionStatement* > ();
        break;

      case symbol_kind::S_for_statement: // for_statement
        value.template destroy< amanda::compiler::ast::NForLoopStatement* > ();
        break;

      case symbol_kind::S_function_call: // function_call
        value.template destroy< amanda::compiler::ast::NFunctionCall* > ();
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.template destroy< amanda::compiler::ast::NFunctionDeclaration* > ();
        break;

      case symbol_kind::S_id: // id
        value.template destroy< amanda::compiler::ast::NIdentifier* > ();
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        value.template destroy< amanda::compiler::ast::NNamespaceDeclaration* > ();
        break;

      case symbol_kind::S_return_statement: // return_statement
        value.template destroy< amanda::compiler::ast::NReturnStatement* > ();
        break;

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.template destroy< amanda::compiler::ast::NStatement* > ();
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.template destroy< amanda::compiler::ast::NUsingDeclaration* > ();
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.template destroy< amanda::compiler::ast::NVariableDeclaration* > ();
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.template destroy< amanda::compiler::ast::NWhileStatement* > ();
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        value.template destroy< amanda::compiler::ast::StatementList* > ();
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.template destroy< amanda::core::String > ();
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        value.template destroy< bool > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return DefaultParser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, amanda::core::String v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const amanda::core::String& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    DefaultParser (amanda::compiler::CompilationContext& compiler_yyarg, amanda::compiler::Scanner& lexer_yyarg);
    virtual ~DefaultParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    DefaultParser (const DefaultParser&) = delete;
    /// Non copyable.
    DefaultParser& operator= (const DefaultParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOF (location_type l)
      {
        return symbol_type (token::TOKEN_EOF, std::move (l));
      }
#else
      static
      symbol_type
      make_EOF (const location_type& l)
      {
        return symbol_type (token::TOKEN_EOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOKEN_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOKEN_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOKEN_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (bool v, location_type l)
      {
        return symbol_type (token::TOKEN_BOOLEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const bool& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BOOLEAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (amanda::core::String v, location_type l)
      {
        return symbol_type (token::TOKEN_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const amanda::core::String& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (amanda::core::String v, location_type l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const amanda::core::String& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::TOKEN_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::TOKEN_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AS (location_type l)
      {
        return symbol_type (token::TOKEN_AS, std::move (l));
      }
#else
      static
      symbol_type
      make_AS (const location_type& l)
      {
        return symbol_type (token::TOKEN_AS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::TOKEN_BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::TOKEN_BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (location_type l)
      {
        return symbol_type (token::TOKEN_CASE, std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const location_type& l)
      {
        return symbol_type (token::TOKEN_CASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (location_type l)
      {
        return symbol_type (token::TOKEN_CLASS, std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const location_type& l)
      {
        return symbol_type (token::TOKEN_CLASS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELETE (location_type l)
      {
        return symbol_type (token::TOKEN_DELETE, std::move (l));
      }
#else
      static
      symbol_type
      make_DELETE (const location_type& l)
      {
        return symbol_type (token::TOKEN_DELETE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (location_type l)
      {
        return symbol_type (token::TOKEN_DO, std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const location_type& l)
      {
        return symbol_type (token::TOKEN_DO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::TOKEN_ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::TOKEN_ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCEPT (location_type l)
      {
        return symbol_type (token::TOKEN_EXCEPT, std::move (l));
      }
#else
      static
      symbol_type
      make_EXCEPT (const location_type& l)
      {
        return symbol_type (token::TOKEN_EXCEPT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::TOKEN_FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::TOKEN_FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::TOKEN_IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::TOKEN_IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IS (location_type l)
      {
        return symbol_type (token::TOKEN_IS, std::move (l));
      }
#else
      static
      symbol_type
      make_IS (const location_type& l)
      {
        return symbol_type (token::TOKEN_IS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERFACE (location_type l)
      {
        return symbol_type (token::TOKEN_INTERFACE, std::move (l));
      }
#else
      static
      symbol_type
      make_INTERFACE (const location_type& l)
      {
        return symbol_type (token::TOKEN_INTERFACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAMESPACE (location_type l)
      {
        return symbol_type (token::TOKEN_NAMESPACE, std::move (l));
      }
#else
      static
      symbol_type
      make_NAMESPACE (const location_type& l)
      {
        return symbol_type (token::TOKEN_NAMESPACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (location_type l)
      {
        return symbol_type (token::TOKEN_NEW, std::move (l));
      }
#else
      static
      symbol_type
      make_NEW (const location_type& l)
      {
        return symbol_type (token::TOKEN_NEW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::TOKEN_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::TOKEN_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::TOKEN_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::TOKEN_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRIVATE (location_type l)
      {
        return symbol_type (token::TOKEN_PRIVATE, std::move (l));
      }
#else
      static
      symbol_type
      make_PRIVATE (const location_type& l)
      {
        return symbol_type (token::TOKEN_PRIVATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROTECTED (location_type l)
      {
        return symbol_type (token::TOKEN_PROTECTED, std::move (l));
      }
#else
      static
      symbol_type
      make_PROTECTED (const location_type& l)
      {
        return symbol_type (token::TOKEN_PROTECTED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC (location_type l)
      {
        return symbol_type (token::TOKEN_PUBLIC, std::move (l));
      }
#else
      static
      symbol_type
      make_PUBLIC (const location_type& l)
      {
        return symbol_type (token::TOKEN_PUBLIC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::TOKEN_RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::TOKEN_RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (location_type l)
      {
        return symbol_type (token::TOKEN_SWITCH, std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const location_type& l)
      {
        return symbol_type (token::TOKEN_SWITCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRY (location_type l)
      {
        return symbol_type (token::TOKEN_TRY, std::move (l));
      }
#else
      static
      symbol_type
      make_TRY (const location_type& l)
      {
        return symbol_type (token::TOKEN_TRY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USING (location_type l)
      {
        return symbol_type (token::TOKEN_USING, std::move (l));
      }
#else
      static
      symbol_type
      make_USING (const location_type& l)
      {
        return symbol_type (token::TOKEN_USING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::TOKEN_WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::TOKEN_WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (location_type l)
      {
        return symbol_type (token::TOKEN_BOOL, std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const location_type& l)
      {
        return symbol_type (token::TOKEN_BOOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BYTE (location_type l)
      {
        return symbol_type (token::TOKEN_BYTE, std::move (l));
      }
#else
      static
      symbol_type
      make_BYTE (const location_type& l)
      {
        return symbol_type (token::TOKEN_BYTE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHORT (location_type l)
      {
        return symbol_type (token::TOKEN_SHORT, std::move (l));
      }
#else
      static
      symbol_type
      make_SHORT (const location_type& l)
      {
        return symbol_type (token::TOKEN_SHORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (location_type l)
      {
        return symbol_type (token::TOKEN_INT, std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const location_type& l)
      {
        return symbol_type (token::TOKEN_INT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG (location_type l)
      {
        return symbol_type (token::TOKEN_LONG, std::move (l));
      }
#else
      static
      symbol_type
      make_LONG (const location_type& l)
      {
        return symbol_type (token::TOKEN_LONG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USHORT (location_type l)
      {
        return symbol_type (token::TOKEN_USHORT, std::move (l));
      }
#else
      static
      symbol_type
      make_USHORT (const location_type& l)
      {
        return symbol_type (token::TOKEN_USHORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT (location_type l)
      {
        return symbol_type (token::TOKEN_UINT, std::move (l));
      }
#else
      static
      symbol_type
      make_UINT (const location_type& l)
      {
        return symbol_type (token::TOKEN_UINT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ULONG (location_type l)
      {
        return symbol_type (token::TOKEN_ULONG, std::move (l));
      }
#else
      static
      symbol_type
      make_ULONG (const location_type& l)
      {
        return symbol_type (token::TOKEN_ULONG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (location_type l)
      {
        return symbol_type (token::TOKEN_STRING, std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const location_type& l)
      {
        return symbol_type (token::TOKEN_STRING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (location_type l)
      {
        return symbol_type (token::TOKEN_CHAR, std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const location_type& l)
      {
        return symbol_type (token::TOKEN_CHAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (location_type l)
      {
        return symbol_type (token::TOKEN_VOID, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (location_type l)
      {
        return symbol_type (token::TOKEN_FLOAT, std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const location_type& l)
      {
        return symbol_type (token::TOKEN_FLOAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE (location_type l)
      {
        return symbol_type (token::TOKEN_DOUBLE, std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE (const location_type& l)
      {
        return symbol_type (token::TOKEN_DOUBLE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SCOPE_OP (location_type l)
      {
        return symbol_type (token::TOKEN_SCOPE_OP, std::move (l));
      }
#else
      static
      symbol_type
      make_SCOPE_OP (const location_type& l)
      {
        return symbol_type (token::TOKEN_SCOPE_OP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::TOKEN_LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::TOKEN_LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::TOKEN_GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::TOKEN_GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::TOKEN_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::TOKEN_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (location_type l)
      {
        return symbol_type (token::TOKEN_NE, std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const location_type& l)
      {
        return symbol_type (token::TOKEN_NE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUSPLUS (location_type l)
      {
        return symbol_type (token::TOKEN_PLUSPLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUSPLUS (const location_type& l)
      {
        return symbol_type (token::TOKEN_PLUSPLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUSMINUS (location_type l)
      {
        return symbol_type (token::TOKEN_MINUSMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUSMINUS (const location_type& l)
      {
        return symbol_type (token::TOKEN_MINUSMINUS, l);
      }
#endif


    class context
    {
    public:
      context (const DefaultParser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const DefaultParser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    DefaultParser (const DefaultParser&);
    /// Non copyable.
    DefaultParser& operator= (const DefaultParser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 791,     ///< Last index in yytable_.
      yynnts_ = 41,  ///< Number of nonterminal symbols.
      yyfinal_ = 34 ///< Termination state number.
    };


    // User arguments.
    amanda::compiler::CompilationContext& compiler;
    amanda::compiler::Scanner& lexer;

  };

  inline
  DefaultParser::symbol_kind_type
  DefaultParser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,    53,    54,    55,     2,
      56,    57,    58,    59,    60,    61,    62,    63,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    65,
      66,    67,    68,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    74,    75,    76,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
    };
    // Last valid token kind.
    const int code_max = 305;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  DefaultParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        value.copy< amanda::compiler::ast::ConditionalStatementList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< amanda::compiler::ast::ExpressionList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.copy< amanda::compiler::ast::NAssignmentExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.copy< amanda::compiler::ast::NBinaryOperator* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.copy< amanda::compiler::ast::NBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        value.copy< amanda::compiler::ast::NBoolean* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        value.copy< amanda::compiler::ast::NClassDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        value.copy< amanda::compiler::ast::NClassDeclaration::AccessModifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_section: // class_section
        value.copy< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_scope: // class_scope
        value.copy< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        value.copy< amanda::compiler::ast::NClassFieldDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.copy< amanda::compiler::ast::NCompilationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.copy< amanda::compiler::ast::NConditionalStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< amanda::compiler::ast::NDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.copy< amanda::compiler::ast::NDeclarationBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.copy< amanda::compiler::ast::NExpression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.copy< amanda::compiler::ast::NExpressionStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_statement: // for_statement
        value.copy< amanda::compiler::ast::NForLoopStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.copy< amanda::compiler::ast::NFunctionCall* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.copy< amanda::compiler::ast::NFunctionDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.copy< amanda::compiler::ast::NIdentifier* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        value.copy< amanda::compiler::ast::NNamespaceDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_return_statement: // return_statement
        value.copy< amanda::compiler::ast::NReturnStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.copy< amanda::compiler::ast::NStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.copy< amanda::compiler::ast::NUsingDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.copy< amanda::compiler::ast::NVariableDeclaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.copy< amanda::compiler::ast::NWhileStatement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        value.copy< amanda::compiler::ast::StatementList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.copy< amanda::core::String > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        value.copy< bool > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  DefaultParser::symbol_kind_type
  DefaultParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  DefaultParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  DefaultParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_multiple_else_if_clauses: // multiple_else_if_clauses
        value.move< amanda::compiler::ast::ConditionalStatementList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< amanda::compiler::ast::ExpressionList* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< amanda::compiler::ast::NAssignmentExpression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_binary_operator: // binary_operator
        value.move< amanda::compiler::ast::NBinaryOperator* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_sequence: // statement_sequence
        value.move< amanda::compiler::ast::NBlock* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_boolean_literal: // boolean_literal
        value.move< amanda::compiler::ast::NBoolean* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_class_declaration: // class_declaration
        value.move< amanda::compiler::ast::NClassDeclaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_access_modifier: // access_modifier
        value.move< amanda::compiler::ast::NClassDeclaration::AccessModifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_class_section: // class_section
        value.move< amanda::compiler::ast::NClassDeclaration::ClassBodySection* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_class_scope: // class_scope
        value.move< amanda::compiler::ast::NClassDeclaration::ClassSectionList* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_field_declaration: // field_declaration
        value.move< amanda::compiler::ast::NClassFieldDeclaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_compilation_unit: // compilation_unit
        value.move< amanda::compiler::ast::NCompilationUnit* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< amanda::compiler::ast::NConditionalStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< amanda::compiler::ast::NDeclaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< amanda::compiler::ast::NDeclarationBlock* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_optional_expression: // optional_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numeric_literal: // numeric_literal
        value.move< amanda::compiler::ast::NExpression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
        value.move< amanda::compiler::ast::NExpressionStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_for_statement: // for_statement
        value.move< amanda::compiler::ast::NForLoopStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< amanda::compiler::ast::NFunctionCall* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function_declaration: // function_declaration
        value.move< amanda::compiler::ast::NFunctionDeclaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_id: // id
        value.move< amanda::compiler::ast::NIdentifier* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_namespace_declaration: // namespace_declaration
        value.move< amanda::compiler::ast::NNamespaceDeclaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_return_statement: // return_statement
        value.move< amanda::compiler::ast::NReturnStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_class_statement: // class_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_compound_statement: // compound_statement
        value.move< amanda::compiler::ast::NStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_using_declaration: // using_declaration
        value.move< amanda::compiler::ast::NUsingDeclaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< amanda::compiler::ast::NVariableDeclaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_while_statement: // while_statement
        value.move< amanda::compiler::ast::NWhileStatement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_class_statement_sequence: // class_statement_sequence
        value.move< amanda::compiler::ast::StatementList* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // "integer literal"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_type: // type
      case symbol_kind::S_simple_type: // simple_type
      case symbol_kind::S_reference_type: // reference_type
      case symbol_kind::S_name: // name
      case symbol_kind::S_simple_name: // simple_name
      case symbol_kind::S_qualified_name: // qualified_name
        value.move< amanda::core::String > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean literal"
        value.move< bool > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  DefaultParser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  DefaultParser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  DefaultParser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  DefaultParser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  DefaultParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  DefaultParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  DefaultParser::symbol_kind_type
  DefaultParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  DefaultParser::symbol_kind_type
  DefaultParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 53 "specs/grammar.y"
} } // amanda::compiler
#line 3190 "include/amanda-c/Parser.h"




#endif // !YY_YY_INCLUDE_AMANDA_C_PARSER_H_INCLUDED
