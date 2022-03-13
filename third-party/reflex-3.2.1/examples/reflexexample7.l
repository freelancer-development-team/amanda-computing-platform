/* Scanner for "C" assignment statements... sort of. */
/* Compile: reflex --bison-locations reflexexample7.l */
/* Compile: bison -d -y flexexample7.y */

%top{
#include "y.tab.h"  /* Generated by bison. */
}

%option bison-locations header-file

%%

\d+           { yylval.num = atoi(text());   return NUMBER; }
\w+           { yylval.str = strdup(text()); return STRING; }
"="|";"       { return text()[0]; }
.|\n          {}

%%