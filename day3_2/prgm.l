%{
    #include "y.tab.h"
%}
num [0-9]+
%%
"+" { return SUM; }
"-" { return MI; }
"*" { return MUL; }
"/" { return DIV; }
"(" { return OB; }
")" { return CB; }
"\n" { return NL; }
{num} { return NUM; }
%%
int yywrap()
{
    return 0;
}
