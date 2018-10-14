keyword []

identifier [a-zA-Z]([a-zA-Z0-9])* 

%{
	#include<stdio.h>
	int i , j=0 , flag;
    	char id[20][20];
%}

%%

[;?\*.()+-/%<>=]|#.*|auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while|"{"|"}"

[0-9]+

{identifier}(\[[0-9]*\])? {    flag=0;
                for(i=0 ; i<20 ; i++)
                {
                    if(!strcmp(id[i] , yytext))
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("\tID: %s",yytext);
                    strcpy(id[j] , yytext);
                                        j += 1;
                }
                }

%%
int main()
{
char filename[25];
FILE *file;
printf("\nFilename :");
scanf("%s", filename);
file = fopen(filename,"r");
if(!file)
{
printf("Could'nt open %s \n",filename);
exit(0);
}
yyin = file;
printf("The identifiers are :\n");
yylex();
return 0;
}
int yywrap()
{
return 1;

}
