#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct OPTAB
{
	char mnemonic_code[10];
	int machine_code;
	char class[2];
	int no_operands;
	int chain;
}OPTAB;
OPTAB optab[27]={	{},
					{"ADD",1,"IS",2,-1},
					{"BC",7,"IS",1,-1},
					{"COMP",6,"IS",2,-1},
					{"DIV",8,"IS",2,7},
					{"END",2,"AD",0,6},
					{"EQU",5,"AD",0,-1},
					{"DC",1,"DL",1,8},
					{"DS",2,"DL",1,-1},
					{"MOVER",4,"IS",2,10},
					{"MOVEM",5,"IS",2,-1},
					{},
					{"LTORG",3,"AD",0,-1},
					{"MULT",3,"IS",2,9},
					{},
					{"ORIGIN",4,"AD",0,-1},
					{"PRINT",10,"IS",1,-1},
					{},
					{"READ",9,"IS",1,-1},
					{"STOP",0,"IS",0,20},
					{"SUB",2,"IS",0,21},
					{"START",1,"AD",0,-1},
					{},{},{},{},{}
				};
typedef union length_or_value
{
	int length;
	char value[5];
}lorv;
typedef struct SYMTAB
{
	char sym_name[10];
	char address[20];
	lorv var;
}symtab[20];

typedef struct LITTAB
{
	char lit_name[10];
	char address[20];
}littab[20];

int pooltab[10];
int lc,ptp,ltp,stp;
enum rc{areg=1,breg=2,creg=3,dreg=4};
void initialise()
{
	lc=0;
	ptp=ltp=stp=1;
	pooltab[1]=1;
}

int main()
{
	initialise();
	FILE * fp;
	int line_count=1,no_of_tokens;
	char *line_buf=NULL,*token=NULL,ch;
	ssize_t line_size;
	size_t line_buf_size=0;
	fp=fopen("input.txt","r");
	while(!feof(fp))
	{
		ch=getc(fp);
		if(ch=='\n')
		{
			line_count++;
		}
	}
	printf("no of lines:%d\n",line_count);
	rewind(fp);
	line_size = getline(&line_buf, &line_buf_size, fp);
	while (line_size > 0)
	{
		no_of_tokens=0;
	    //printf("%s",line_buf);
	    token = strtok(line_buf, " "); 
    	while (token != NULL) 
		{ 
			no_of_tokens++;
	        printf("%s\n", token); 
	        token = strtok(NULL, " "); 
    	} 
    	printf("no of tokens ::%d\n",no_of_tokens);
	    line_size = getline(&line_buf, &line_buf_size, fp);   
	}
	line_buf=NULL;
	return 0;
}
