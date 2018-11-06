#include<stdio.h>
#include<stdlib.h>

//Initial variables
int i=0;
char input[20];

//Functions used as Non-terminal expansions
int S();
int A();
int B();
/**
The recursive descent grammar is the following

S->cd|AB
B->cAd|b
A->a|b

**/

void main()
{
        scanf("\n%s" , input);
	printf("\n");
        if(S())
        	printf("\nValid expression!\n");
	else
		printf("\nNot a valid expression!\n");
}

int S()
{
	if(input[i] == 'c' && input[i+1] == 'd')
	{
		printf("S-->cd\n");
		i += 2;
		return 1;
	}
	else if(input[i] == 'c' || input[i] == 'b')
        {
                if(B())
                {
                        printf("S-->B\n");
                        return 1;
                }
        }
	else if(input[i] == 'a' || input[i] == 'b')
	{
		if(A() && B())
		{
			printf("S-->AB\n");
			return 1;
		}
	}
	else
	{
		printf("invalid\n");
		return 0;
	}
}

int A()
{
	if(input[i] == 'a')
	{
		printf("A-->a\n");
		i++;
		return 1;
	}
	else if(input[i] == 'b')
	{
		printf("A-->b\n");
		i++;
		return 1;
	}
	else
	{
		printf("invalid\n");
		return 0;
	}
}

int B()
{
	if(input[i] == 'b')
	{
		printf("B-->b\n");
		i++;
		return 1;
	}
	else if(input[i] == 'c')
	{
		i++;
		if(A())
		{
			if(input[i] == 'd')
			{
				printf("B-->cAd\n");
				i++;
				return 1;
			}
		}
	}
	else
	{
		printf("invalid\n");
		return 0;
	}
}
