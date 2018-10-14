%{
	#include<stdio.h>
	int count=0;
%}
zero    [0]
one    	[1]
%%
	
{zero}({one}{zero}|{zero}{one})* {count++; return 0;}
.* {count = 0;return 0;}
%%
int main(void){
	yylex();
	if(count >0){
		printf("Pattern is Valid.");
	}else{
		printf("Pattern is not Valid.");
	}
	return 0;
}	
int yywrap(){
	return(1);
}
