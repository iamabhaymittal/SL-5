#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct terminalTable{
	char symbol[50];
	int index;
}terminal;

typedef struct identifierTable{
	char symbol[50];
	int index;
}identifier;

typedef struct literalTable{
	char symbol[50];
	int index;
}literal;

typedef struct universalSymbolTable{
	char symbol[50];
	char type[50];
	int index;
}ust;
/*
void displayTerminalTable(terminal T[], int n)
{
	int i = 0;
	printf("\nTERMINAL TABLE\nSYMBOL\tINDEX");

	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("%s\t%d",T[i].symbol, T[i].index);
	}
}*/

int main()
{
	int i;
	int j;
	int line;
	char buffer[500];
	char temp[500];
	char c;
	terminal T[32];
	char* token[2];

	FILE* fin = NULL;
	FILE* fterm = NULL;
	FILE* fid = NULL;
	FILE* flit = NULL;
	FILE* fust = NULL;

	fin = fopen("sourceCode.txt", "r");
	fterm = fopen("terminals.txt", "r");

	printf("\nReading terminal table ..");
	line = 0;

	if(fterm != NULL)
	{
		i = 0;
		while(fgets(buffer, 500, fterm) != NULL)
		{
			j=0;
			token[j] = strtok(buffer, " ");
			while(token[j] != NULL)
			{
				j++;				
				token[j] = strtok(NULL, " ");
				
			}
			j-=1;
			strcpy(temp, token[j]);
			strtok(temp, "\n");
			temp[strlen(temp)+1] = '\0';
			strcpy(token[j], temp);
			strcpy(T[i].symbol, token[j-1]);
			T[i].index = atoi(token[j]);
			printf("\ntoken [0] : [%s]\nToken[1] : [%d]",T[i].symbol, T[i].index); 
			i++;

		}
		for(j=0;j<i;j++)
			printf("\n%s\t%d",T[j].symbol, T[j].index);
	}
	fclose(fterm);
	fclose(fin);
	return 0;
}



