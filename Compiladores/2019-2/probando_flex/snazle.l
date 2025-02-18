%{
  #include <cstdio>

  #include "snazle.tab.h"  // to get the token types from Bison

%}
%%
[ \t\n]           ;
[0-9]+\.[0-9]+    { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+            { yylval.ival = atoi(yytext); return INT; }
[a-zA-Z0-9]+      {
  yylval.sval = strdup(yytext);
  return STRING;
}
%%
