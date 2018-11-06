#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int num_prod,nonter=0;
char input[20][20];
char first[20][20];


char calFirst(char letter,int i){
	for(;i<num_prod;i++){
		if(letter == input[i][0]){
			if(islower(input[i][2])){
				return input[i][2];
			}else{
				calFirst(input[i][2],i+1);
			}
		}
	}
}

void main(){
	int i,j;
	//Getting the prouctions 
	printf("Enter the number of productions: \t");
	scanf("%d",&num_prod);
	for(i=0;i<num_prod;i++){
		printf("Enter the production %d : \n",i+1);
		scanf("%s",input[i]);
	}
	
	//Storing the non terminals
	for(i=0;i<num_prod;i++){
		if(nonter<1){
			first[0][0] =input[0][0];
			first[0][1]='\0';
			nonter++;
		}else{
			int flag=0;
			for(j=0;j<nonter;j++){				
				if(first[j][0]== input[i][0]){
					flag =1;
					break;
				}				
			}
			if(flag ==0){
					first[nonter][0]=input[i][0];
					first[nonter][1]='\0';
					nonter++;
			}
		}
	}

	//calculating the first
	for(i=0;i<nonter;i++){
		for(j=0;j<num_prod;j++){
			if(input[j][0] == first[i][0]){
				if(islower(input[j][2])){
					int len = strlen(first[i]);
					first[i][len] = input[j][2];
					first[i][len+1] ='\0';
				}else{
					char text = calFirst(input[j][2],0);
					int len = strlen(first[i]);
					first[i][len] = text;
					first[i][len+1] ='\0';
				}
			}
		}
	}
	printf("count is %d ",nonter);
	for(i=0;i<nonter;i++){
		printf("\n%d = %s\n",i+1,first[i]);	
	}
}
