%{
    #include<stdio.h>
    int yylex();
%}
%token SUM MI MUL DIV CB OB NUM NL
%%
S : X  NL{ printf("Valid"); return 0;}
;
X :  OEXP OP CEXP
;
OEXP : OB NUM | NUM 
;
CEXP : NUM | NUM CB
; 
OP : SUM | MI | MUL | DIV 
;
%%
int main()
{
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}
int yyerror()
{
    printf("Invalid");
    return 0;
}
