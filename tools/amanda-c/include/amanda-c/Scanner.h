// include/amanda-c/Scanner.h generated by reflex 3.2.1 from specs/scanner.l

#ifndef REFLEX_INCLUDE_AMANDA_C_SCANNER_H
#define REFLEX_INCLUDE_AMANDA_C_SCANNER_H
#define yyIN_HEADER 1
#define REFLEX_VERSION "3.2.1"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#undef REFLEX_OPTION_batch
#undef REFLEX_OPTION_bison
#undef REFLEX_OPTION_fast
#undef REFLEX_OPTION_flex
#undef REFLEX_OPTION_header_file
#undef REFLEX_OPTION_lex
#undef REFLEX_OPTION_lexer
#undef REFLEX_OPTION_namespace
#undef REFLEX_OPTION_noyywrap
#undef REFLEX_OPTION_outfile
#undef REFLEX_OPTION_prefix
#undef REFLEX_OPTION_unicode

#define REFLEX_OPTION_batch               true
#define REFLEX_OPTION_bison               true
#define REFLEX_OPTION_fast                true
#define REFLEX_OPTION_flex                true
#define REFLEX_OPTION_header_file         "include/amanda-c/Scanner.h"
#define REFLEX_OPTION_lex                 yylex
#define REFLEX_OPTION_lexer               Scanner
#define REFLEX_OPTION_namespace           amanda::compiler
#define REFLEX_OPTION_noyywrap            true
#define REFLEX_OPTION_outfile             "compiler/Scanner.cpp"
#define REFLEX_OPTION_prefix              yy
#define REFLEX_OPTION_unicode             true

#ifdef __cplusplus

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  FLEX-COMPATIBLE ABSTRACT LEXER CLASS                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/flexlexer.h>

namespace amanda {
namespace compiler {

typedef reflex::FlexLexer<reflex::Matcher> FlexLexer;

} // namespace amanda
} // namespace compiler
#undef yytext
#undef yyleng
#undef yylineno

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

namespace amanda {
namespace compiler {

class Scanner : public FlexLexer {
 public:
  Scanner(
      const reflex::Input& input = reflex::Input(),
      std::ostream        *os    = NULL)
    :
      FlexLexer(input, os)
  {
  }
  virtual int yylex(void);
  int yylex(const reflex::Input& input)
  {
    in(input);
    return yylex();
  }
  int yylex(const reflex::Input& input, std::ostream *os)
  {
    in(input);
    if (os)
      out(*os);
    return yylex();
  }
};

} // namespace amanda
} // namespace compiler

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  BISON                                                                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

extern amanda::compiler::Scanner YY_SCANNER;

#ifndef YY_EXTERN_C
#define YY_EXTERN_C
#endif

#else // !__cplusplus

#undef YY_EXTERN_C
#define YY_EXTERN_C

#endif // __cplusplus

#ifndef yy_size_t
#define yy_size_t size_t
#endif

extern char *yytext;
extern yy_size_t yyleng;
extern int yylineno;

YY_EXTERN_C int yylex(void);

#endif