#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int num_prod,nonter=0;
char input[20][20];
char first[20][20];
char follow[20][20];
char epi ='#';


char calFirst(char letter,int i){
	for(;i<num_prod;i++){
		if(letter == input[i][0]){
			if(islower(input[i][2])){
				return input[i][2];
			}else{
				return calFirst(input[i][2],i+1);
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
		printf("Enter the production %d : \t",i+1);
		scanf("%s",input[i]);
	}
	
	//Storing the non terminals
	for(i=0;i<num_prod;i++){
		if(nonter<1){
			first[0][0] =input[0][0];
			first[0][1]='\0';
			follow[0][0] =input[0][0];
			follow[0][1]='\0';
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
					follow[nonter][0]=input[i][0];
					follow[nonter][1]='\0';
					nonter++;
			}
		}
	}

	//calculating the first
	for(i=0;i<nonter;i++){
		for(j=0;j<num_prod;j++){
			if(input[j][0] == first[i][0]){
				int m,n;
				if(islower(input[j][2])){
					int len = strlen(first[i]);
					first[i][len] = input[j][2];
					first[i][len+1] ='\0';
					for(m=0;m<num_prod;m++){
						char text = calFirst(input[j][2],m);
						int len = strlen(first[i]);
						int flag=1;
						for(n=0;n<len;n++){
							if(first[i][n]==text){
								flag=0;
							}
						}
						if(flag==1){
							first[i][len] = text;
							first[i][len+1] ='\0';
						}
					}
				}else{
					
					for(m=0;m<num_prod;m++){
						char text = calFirst(input[j][2],m);
						int len = strlen(first[i]);
						int flag=1;
						for(n=0;n<len;n++){
							if(first[i][n]==text){
								flag=0;
							}
						}
						if(flag==1){
							first[i][len] = text;
							first[i][len+1] ='\0';
						}
					}
				}
			}
		}
	}

	//calculating follow
	for(i=0;i<nonter;i++){
		for(j=0;j<num_prod;j++){
			int k =strlen(input[j]);
			int l;
			for(l=2;l<k;l++){
				if(isupper(input[j][l])){
					if(input[j][l]==follow[i][0]){
					if(l+1<k){
						if(islower(input[j][l+1])){
							int len = strlen(follow[i]);
							follow[i][len] = input[j][l+1];
							follow[i][len+1] ='\0';
						}else{
							char text =calFirst(input[j][l+1],0);
							int len = strlen(follow[i]);
							follow[i][len] = text;
							follow[i][len+1] ='\0';
						}
						
					}else{
							int len = strlen(follow[i]);
							follow[i][len] = epi;
							follow[i][len+1] ='\0';						
					}
					}
				}
			}			
		}
	}

	//displaying the first and follow
	for(i=0;i<nonter;i++){
		if(strlen(first[i])==1){
			first[i][1] =epi;
			first[i][2] ='\0';

		}
		//printf("\n%d FIRST=> %s\tFOLLOW=> %s  \n",i+1,first[i],follow[i]);
		printf("------------\t");		
		printf("\nFIRST of %c : ",first[i][0]);
		int len = strlen(first[i]);
		int j;		
		for(j=1;j<len;j++){
			printf("%c,", first[i][j]);
		}	
		printf("\n");
		printf("FOLLOW of %c : ",follow[i][0]);
		int length = strlen(follow[i]);		
		for(j=1;j<length;j++){
			printf("%c," ,follow[i][j]);
		}	
		printf("\n");
	}
}
