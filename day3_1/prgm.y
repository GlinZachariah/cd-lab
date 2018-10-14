%{
    #include<stdio.h>
    int yylex();
%}
%token SW OB ID CB NL COB CCB CS NUM Q BR SEM DF
%%
S : X NL { printf("Valid"); return 0;}
;
X : SW OB ID CB NL COB NL EXP CCB
;
EXP : C | C D
;
C : C C | CS NUM Q ID SEM NL | BR SEM NL
;
D : DF Q ID SEM NL BR SEM NL
;
%%
int main()
{
    printf("Enter the switch statement :\n");
    yyparse();
    return 0;
}
int yyerror()
{
    printf("Invalid");
    return 0;
}
