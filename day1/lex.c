#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int keyword(char temp[25]){
	char keywords[32][10] = {"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","const","	float","short","unsigned","continue","for","signed","void","default","goto","sizeof","volatile","do","if","static","while"};		
	int state =0,i;
	for(i=0;i<32;i++){
		if(strcmp(keywords[i],temp)==0){
			state =1;
			break;
		}
	}
	return state;	
}


void main(){	
	FILE *file;
	file =fopen("input.txt","r");
	int x;
	int state=0; 
	char temp[25],ch; 
	if(file == NULL){
		printf("Error in reading file");
		exit(0);
	}
	ch  =fgetc(file);
	while(ch!= EOF){
		switch(state){
			case 0: if(ch =='<'){
					state=1;
				}else if(ch == '='){
					state =5;
				}else if(ch == '>'){
					state =6;
				}else if(ch >= 'a'&& ch <= 'z'|| ch >= 'A'&& ch <= 'Z' || ch == '_'){
					x=0;
					temp[x] =ch;
					state =2;
				}else if(ch >= '0'&& ch <= '9'){
					x=0;
					temp[x] =ch;
					state =3;
				}else if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%'){
                    			state  = 0;
                    			printf("Arithmetic operator :\t%c\n",ch);
                    			break;
                 		} else{
					state=0;
				}break;
			case 1: if(ch == '='){
					printf("Realational operator:\t<=\n");state=0;
				}else if(ch == '>'){
					printf("Realational operator:\t!=\n");state=0;
				}else {
					fseek(file,-1,SEEK_CUR);
					printf("Realational operator:\t<\n");state=0;
				} break;
			case 2:if((ch >= 'a'&& ch <= 'z')|| (ch >= 'A'&& ch <= 'Z') || (ch >= '0'&& ch <= '9') || ch == '_'){
					x++;
					temp[x] =ch;
				}else{
					fseek(file,-1,SEEK_CUR);
					x++;
					temp[x] = '\0';
					int result = keyword(temp);
					if(result == 1){
						printf("Keyword:\t%s\n",temp);state=0;break;
						
					}else{
						printf("Identifier:\t%s\n",temp);	state=0;break;				
					}
					state =0;
				}break;
			case 3:if(ch >= '0'&& ch <= '9'){
					x++;
					temp[x] =ch;
					state =3;
				}else{
					fseek(file,-1,SEEK_CUR);
					x++;
					temp[x] = '\0';
					printf("Constant:\t%s\n",temp);state=0;
				}break;
			case 5:if(ch == '='){
					printf("Realational operator:\t==\n");
					state=0;	
				}else{
					fseek(file,-1,SEEK_CUR);
					printf("Asssignment operator:\t=\n");
					state=0;	
				}break;
			case 6:if(ch == '='){
					printf("Realational operator:\t>=\n");
					state=0;			
					break;
				}else{
					fseek(file,-1,SEEK_CUR);
					printf("Realational operator:\t>\n");state=0;break;
				} break;
			default : state=0;		
			
		}
		ch = fgetc(file);	
	}
}
