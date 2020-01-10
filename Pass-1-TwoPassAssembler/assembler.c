#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <ctype.h>

struct symbol{
	char symb[5];
	int addr;
};

struct literal{
	char lit[5];
	int addr;
};

struct cnd{
	char cndn[5];
	int code;
};

struct reg{
	char r[5];
	int code;
};

struct res{
	int lc;
	char mn[10];
	char op1[10];
	char mem[10];
};

struct rmn{
	char mn[10];
};

FILE *fp,*fp1; 
char mn[10],lb[10],op1[10],op2[10];  
int a1,a2,a3,a4,lc=0;  
char mn1[10],ty[5]; int op,sz,no;
char type[5]; int opcode=-1;
struct cnd c[7]={{"LT",1},{"GT",2},{"LE",3},{"GE",4},{"EQ",5},{"NE",6},{"ANY",7}};
struct reg r[4]={{"AREG",1},{"BREG",2},{"CREG",3},{"DREG",4}};
struct symbol s[50]; struct literal l[50]; //struct res r[50]; 
struct rmn rm[50];
int i=0,j=0,k=0;

// store result in file/struct ; read ; for lc add last mn's size
void generateLC(char mn[],char op2[],int *lc){
int temp;
	fp1=fopen("mot1","r");
	if(strcmp(mn,"START")==0){
	 		printf(" -  ");
	 }else{
	while(!feof(fp1)){
	 	fscanf(fp1, "%s %d %d %s %d",mn1,&op,&sz,ty,&no);
		if(strcmp(rm[k].mn,mn1)==0){
			*lc=*lc+sz;
			temp=*lc;
			printf("%d ",temp);
		}
	}
	
	}
	fclose(fp1);
	k++;
	strcpy(rm[k].mn,mn);
}

void handleMnemonic(char mn[]){
	fp1=fopen("mot1","r");
	if(fp1==NULL)
 	printf("cant open");
 	else{
 		while(!feof(fp1)){
 			fscanf(fp1, "%s %d %d %s %d",mn1,&op,&sz,ty,&no);
			if(strcmp(mn1,mn)==0){
		 			printf("(%s,%d) ",ty,op);
 			}
 		}
 	}
 	fclose(fp1);
}

int isNum(char a[]){
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0' && a[i]<='9')
		return 1;
	}
	return 0;
}

int searchS(char val[]){
	for(int k=0;k<j;k++){
		if(strcmp(s[k].symb,val)==0){
		return k;
		}
	}
	return -1;
}

int searchL(char val[]){
	for(int k=0;k<i;k++){
		if(strcmp(l[k].lit,val)==0){
		return k;
		}
	}
	return -1;
}

void handleOp2Val(char op[]){
//char *a; 
char s[10]; int o=0; int p[10]; char *t; int l=0;
	for(int i=0;i<strlen(op);i++){
		if(op[i]=='+' || op[i]=='-' || op[i]=='*' || op[i]=='/' || op[i]=='%'){
		s[o]=op[i];
		p[o]=i;
		o++;
		}
	}
	
	
	for(int i=0;i<o;i++){
	//printf("\ns %d %c\n",p[i],s[i]);
		//t=strtok(op,s[i]);
		for(int j=l;j<s[i];j++){
			strncpy(op,"(S,1)",5);
		}
		//strncpy(t,"SW",strlen("SW"));
	}
	printf(" %s\n",op);
	
}

void handleOp2(char op2[]){
int val=0; int val1=0;
		if(strcmp(op2,"-")==0)
		printf("-");
		
		else if(strncmp(op2,"'",1)==0){		// LITERAL
		val1=searchL(op2);
			if(val1==-1){
			strcpy(l[i].lit,op2);
			l[i].addr=-1;
			printf("(L,%d) ",i+1);
			i++;
			}else{
				printf("(L,%d) ",val1+1);
			}
		}
		
		else if(isNum(op2)==1){			// CONSTANT
		//printf(" %s ",op2);
		handleOp2Val(op2);
		//if(strstr(op2,"AGAIN")!=NULL)
		//printf("\nyoyoyoyooyoyoy\n");
		
		}
		
		
		else{										// SYMBOL
			val=searchS(op2);
				if(val==-1){
				strcpy(s[j].symb,op2);
				s[j].addr=-1;
				printf("(S,%d) ",j+1);
				j++;
			}else{
				printf("(S,%d) ",val+1);
			}
		}
}

void handleOp1(char op1[10]){
int a=0;
			if(strcmp(op1,"-")==0)
			printf("  -  ");
			
			for(int i=0;i<sizeof(r)/sizeof(struct reg);i++){
				if(strcmp(r[i].r,op1)==0){
				a=r[i].code;
				printf("(R,%d) ",a);
				}
			}
			for(int i=0;i<sizeof(c)/sizeof(struct cnd);i++){
				if(strcmp(c[i].cndn,op1)==0){
				a=c[i].code;
				printf("(C,%d) ",a);
				}
			}
}



int handleLabel(char lb[],int lc){
		/*strcpy(s[j].symb,lb);
		s[j].addr=lc;
		j++;		*/
}


int main()
{
	
 	fp=fopen("Assembly_Program3.txt","r");
 	if(fp==NULL)
 	printf("cant open");
 	else{

 	  while(!feof(fp)){

 			fscanf(fp,"%s%s%s%s",lb,mn,op1,op2);
 			
 			 if(strcmp(mn,"START")==0)
 			 {
 			 strcpy(rm[k].mn,"START");
 				if(strcmp(op2,"-")==0)
 				lc=0;
 				else
 				lc=atoi(op2);
 			}
 			
 			generateLC(mn,op2,&lc);
 			
 			if(strcmp(mn,"-")==0)
 			printf("\nmnemonic required!\n");
 			else
 			handleMnemonic(mn);
 			
 			if(strcmp(lb,"-")!=0){
 			handleLabel(lb,lc);
 			}
 			
 			handleOp1(op1);
 			
 			handleOp2(op2);
 			
			printf("\n");
 		}
 	} 	

		printf("\nsymbol table\n");
		for(int k=0;k<j;k++)
		printf("%s %d\n",s[k].symb,s[k].addr);
		printf("\nliteral table\n");
		for(int k=0;k<i;k++)
		printf("%s %d\n",l[k].lit,l[k].addr);
		/*for(int i=0;i<k;i++)
		printf("%d %s\n",i,rm[i].mn);*/

	fclose(fp);
 return 0;
}
