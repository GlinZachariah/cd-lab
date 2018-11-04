%{
#include<stdio.h>
%}

%token NUM NL
%left '+''-'
%left '*''/'
%left '('')'

%%

S : E NL {printf("The result is: %d\n" , $1);}
  ;
E : E'+'E {$$=$1+$3;}
  | E'-'E {$$=$1-$3;}
  | E'*'E {$$=$1*$3;}
  | E'/'E {$$=$1/$3;}
  | '('E')' {$$=$2;}
  | NUM {$$=$1;}
  ;

%%

int yyerror()
{
	printf("Invalid\n");
}

void main()
{
	yyparse();
}
