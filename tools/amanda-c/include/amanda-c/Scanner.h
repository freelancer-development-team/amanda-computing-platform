// include/amanda-c/Scanner.h generated by reflex 3.2.1 from specs/scanner.l

#ifndef REFLEX_INCLUDE_AMANDA_C_SCANNER_H
#define REFLEX_INCLUDE_AMANDA_C_SCANNER_H
#define IN_HEADER 1
#define REFLEX_VERSION "3.2.1"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#undef REFLEX_OPTION_YYLTYPE
#undef REFLEX_OPTION_YYSTYPE
#undef REFLEX_OPTION_batch
#undef REFLEX_OPTION_bison_cc
#undef REFLEX_OPTION_bison_cc_namespace
#undef REFLEX_OPTION_bison_cc_parser
#undef REFLEX_OPTION_bison_complete
#undef REFLEX_OPTION_bison_locations
#undef REFLEX_OPTION_fast
#undef REFLEX_OPTION_freespace
#undef REFLEX_OPTION_header_file
#undef REFLEX_OPTION_lex
#undef REFLEX_OPTION_lexer
#undef REFLEX_OPTION_namespace
#undef REFLEX_OPTION_outfile
#undef REFLEX_OPTION_token_eof
#undef REFLEX_OPTION_token_type

#define REFLEX_OPTION_YYLTYPE             amanda::compiler::location
#define REFLEX_OPTION_YYSTYPE             amanda::compiler::DefaultParser::semantic_type
#define REFLEX_OPTION_batch               true
#define REFLEX_OPTION_bison_cc            true
#define REFLEX_OPTION_bison_cc_namespace  amanda::compiler
#define REFLEX_OPTION_bison_cc_parser     DefaultParser
#define REFLEX_OPTION_bison_complete      true
#define REFLEX_OPTION_bison_locations     true
#define REFLEX_OPTION_fast                true
#define REFLEX_OPTION_freespace           true
#define REFLEX_OPTION_header_file         "include/amanda-c/Scanner.h"
#define REFLEX_OPTION_lex                 lex
#define REFLEX_OPTION_lexer               Scanner
#define REFLEX_OPTION_namespace           amanda::compiler
#define REFLEX_OPTION_outfile             "compiler/Scanner.cpp"
#define REFLEX_OPTION_token_eof           amanda::compiler::DefaultParser::symbol_type(0, location())
#define REFLEX_OPTION_token_type          amanda::compiler::DefaultParser::symbol_type

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top user code                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 39 "specs/scanner.l"

    #include <amanda-c/Parser.h>            // Generated by Bison 3.2(+)
    #include <amanda-c/ParserLocations.h>   // Generated by Bison 3.2(+)


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  ABSTRACT LEXER CLASS                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/abslexer.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

namespace amanda {
namespace compiler {

class Scanner : public reflex::AbstractLexer<reflex::Matcher> {
#line 63 "specs/scanner.l"

    public:

        typedef DefaultParser::token    Tokens;

    protected:

        typedef struct Keyword
        {
            const char* name;
            int token;
        } Keyword;

    int getKeyWordToken(const char* str)
    {
        #define TOKEN(x)    DefaultParser::token::TOKEN_ ## x

        int result = 0;

        static const Keyword kwds[] =
        {
            { "break",      TOKEN(BREAK)        },
            { "case",       TOKEN(CASE)         },
            { "class",      TOKEN(CLASS)        },
            { "do",         TOKEN(DO)           },
            { "else",       TOKEN(ELSE)         },
            { "for",        TOKEN(FOR)          },
            { "if",         TOKEN(IF)           },
            { "interface",  TOKEN(INTERFACE)    },
            { "namespace",  TOKEN(NAMESPACE)    },
            { "switch",     TOKEN(SWITCH)       },
            { "return",     TOKEN(RETURN)       },
            { "using",      TOKEN(USING)        },
            { "while",      TOKEN(WHILE)        },
            // Data types
            { "void",       TOKEN(VOID) },
            { "bool",       TOKEN(BOOL) },
            { "int",        TOKEN(INT) },
            { "long",       TOKEN(LONG) },
            { "string",     TOKEN(STRING) },
            { "char",       TOKEN(CHAR) },
            { "float",      TOKEN(FLOAT) },
            { "double",     TOKEN(DOUBLE) },
            { NULL, 0 }
        };

        for (const Keyword* kwd = &kwds[0]; kwd->name != NULL; ++kwd)
        {
            if (::strcmp(kwd->name, str) == 0)
            {
                result = kwd->token;
                break;
            }
        }

        #undef TOKEN

        return result;
    }

    DefaultParser::symbol_type token(int id)
    {
        return DefaultParser::symbol_type(id, location());
    }

    DefaultParser::symbol_type integerLiteral()
    {
        return DefaultParser::make_INTEGER(text(), location());
    }

    void scannerException();

 public:
  typedef reflex::AbstractLexer<reflex::Matcher> AbstractBaseLexer;
  Scanner(
      const reflex::Input& input = reflex::Input(),
      std::ostream&        os    = std::cout)
    :
      AbstractBaseLexer(input, os)
  {
  }
  static const int INITIAL = 0;
  std::string filename;
  virtual amanda::compiler::location location(void)
  {
    amanda::compiler::location yylloc;
    yylloc.begin.filename = &filename;
    yylloc.begin.line = static_cast<unsigned int>(matcher().lineno());
    yylloc.begin.column = static_cast<unsigned int>(matcher().columno());
    yylloc.end.filename = &filename;
    yylloc.end.line = static_cast<unsigned int>(matcher().lineno_end());
    yylloc.end.column = static_cast<unsigned int>(matcher().columno_end());
    return yylloc;
  }
  virtual amanda::compiler::DefaultParser::symbol_type lex(void);
};

} // namespace amanda
} // namespace compiler

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  BISON C++                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#endif
