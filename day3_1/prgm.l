%{
    #include "y.tab.h"
%}
id [a-zA-Z]([a-zA-Z]|[0-9])*
num [0-9]+
%%
"switch" { return SW; }
"break" { return BR; }
"case" { return CS; }
"default" { return DF; }
"(" { return OB; }
")" { return CB; }
{num} { return NUM; }
";" { return SEM; }
{id} { return ID; }
"\n" { return NL; }
":" { return Q; }
"{" { return COB; }
"}" { return CCB; }
%%
int yywrap()
{
    return 0;
}
