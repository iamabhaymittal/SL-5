#include<stdio.h>
#include<string.h>

int MCP = 0;
int i;

char FIRST[5];
char SECOND[5];
char THIRD[5];
char FORTH[5];
char FIFTH[5];
char SIXTH[5];
char SEVENTH[5];
char ANS[10];


char empty[2]="-";
  
char R[2]="R";
char C[2]="C";
char S[2]="S";
char L[2]="L";
char IS[3]="IS";
char AD[3]="AD";
  

typedef struct MCode
{
	char first[5];
	char second[5];
	char third[5];
}MCode;

MCode m[30];

int sym_search(char *s)
{
	FILE *f1;
	f1 = fopen("symtab.txt" , "r");
	char s1[5] , s2[5] , s3[5] , s4[5];
	int found;
	while(!feof(f1))
	{
		fscanf(f1 , "%s%s%s%s" , s1,s2,s3,s4);		
		found = strcmp(s1 , s);
		
		if(found==0)
		{
			strcpy(ANS , s3);
			return 1;
		}		
	} 
	return 0;
}

int littab_search(char *s)
{
	FILE * f2;
	char s1[10] , s2[10] , s3[10];
	int found;
	f2 = fopen("littab.txt" , "r");
	
	while(!feof(f2))
	{
		fscanf(f2 , "%s%s%s",s1,s2,s3);
		
		found = strcmp(s1 , s);
		
		if(found==0)
		{
			strcpy(ANS , s3);
			return 1;		
		}
	}
	return 0;
}

void print_tables()
{
	FILE *f3;
	//int j=0;
	f3 = fopen("Mcode.txt" , "w");
	
	for(i=0 ; i<MCP ; i++)
	{
		fprintf(f3 , "%s\t%s\t%s\n" , m[i].first , m[i].second , m[i].third);
	}
}

void main()
{

	FILE *f4;
	int i;
	
	f4 = fopen("IC.txt" , "r");
	
	fscanf(f4 , "%s\t%s\t%s\t%s\t%s\t%s\t%s",FIRST,SECOND,THIRD,FORTH,FIFTH,SIXTH,SEVENTH);
	
	printf("**************INTERMEDIATE CODE*************\t\t*****************MACHINE CODE******************\n");
		
	for(i=0 ; i<25 ; i++)
	{
		strcpy(m[i].first , empty);
		strcpy(m[i].second , empty);
		strcpy(m[i].third , empty);
	}	
	
	while(!feof(f4))
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s",FIRST,SECOND,THIRD,FORTH,FIFTH,SIXTH,SEVENTH);
		
		if(strcmp(SECOND , IS)==0)
			strcpy(m[MCP].first , THIRD);
			
		if(strcmp(FORTH , R)==0)	
			strcpy(m[MCP].second , FIFTH);
		
		if(strcmp(SIXTH , C)==0)
			strcpy(m[MCP].third , SEVENTH);
			
		if(strcmp(SIXTH , S)==0)
		{
			if(sym_search(SEVENTH)==1)
				strcpy(m[MCP].third , ANS);
		}
		
		if(strcmp(SIXTH , L)==0)
		{
			if(littab_search(SEVENTH)==1)
				strcpy(m[MCP].third , ANS);
		}	
		
		if(strcmp(SECOND , AD)==0)
		{
			strcpy(m[MCP].first , "0");
			strcpy(m[MCP].second , empty);
			strcpy(m[MCP].third , empty);
		}
			
		
		 
        printf("\t|  %s\t%s\t%s\n",m[MCP].first,m[MCP].second,m[MCP].third);
        MCP++;
        fscanf(f4,"%s\t%s\t%s\t%s\t%s\t%s\t%s",FIRST,SECOND,THIRD,FORTH,FIFTH,SIXTH,SEVENTH);	
		
	
	}
	
	print_tables();
	fclose(f4);
	
	
	

}