#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void search();

typedef struct data
{
	string mne, type;
	string opcode;
	int n_operand, size;
}data;

typedef struct symtab
{
   int no;
   string symbol;
   int address;
   int length;
}symtab;

typedef struct littab
{
  int no;
  string literal;
  int address;
}littab;

int pooltab[10];

int main()
{
    data d[20];
	int l,i;
	
	fstream f1;
	int wc,line=0;
	string buffer;
    f1.open("Assembly_Program3.txt"); 
      if(f1.fail())
         return 0;
         
    while(getline(f1,buffer))
    {
         wc=0;
		line++;
		cout<<line<<" "<<buffer<<endl;
    }
    f1.close();	
    
    for(l=0;l<18;l++)
		d[l].size=1;
	for(l=0;l<10;l++)
		d[l].type="IS";
		
		
	d[0].mne="MOVER";
	d[0].opcode="04";
	d[0].n_operand=2;
	
	d[1].mne="MOVEM";
	d[1].opcode="05";
	d[1].n_operand=2;
	
	d[2].mne="ADD";
	d[2].opcode="01";
	d[2].n_operand=2;
	
	d[3].mne="SUB";
	d[3].opcode="02";
	d[3].n_operand=2;
	
	d[4].mne="MULT";
	d[4].opcode="03";
	d[4].n_operand=1;
	
	d[5].mne="DIV";
	d[5].opcode="08";
	d[5].n_operand=2;
	
	d[6].mne="BC";
	d[6].opcode="07";
	d[6].n_operand=0;
	
	d[7].mne="COMP";
	d[7].opcode="06";
	d[7].n_operand=1;
	
	d[8].mne="PRINT";
	d[8].opcode="10";
	d[8].n_operand=0;
	
	d[9].mne="READ";
	d[9].opcode="09";
	d[9].n_operand=1;
	
	d[10].mne="STOP";
	d[10].type="IS";
	d[10].opcode="00";
	d[10].n_operand=0;
	
	for(l=11;l<16;l++)
		d[l].type="AD";
	
	d[11].mne="START";
	d[11].opcode="01";
	d[11].n_operand=0;
	
	d[12].mne="END";
	d[12].opcode="02";
	d[12].n_operand=0;
	
	d[13].mne="EQU";
	d[13].opcode="03";
	d[13].n_operand=0;
	
	d[14].mne="ORIGIN";
	d[14].opcode="04";
	d[14].n_operand=0;
	
	d[15].mne="LTORG";
	d[15].opcode="05";
	d[15].n_operand=0;
	
	d[16].mne="DC";
	d[16].type="DS";
	d[16].opcode="01";
	d[16].n_operand=0;
	
	d[17].mne="DS";
	d[17].type="DS";
	d[17].opcode="02";
	d[17].n_operand=0;
	
	cout<<"\n================================MOT TABLE=====================================\n";
	cout<<"Mnemonics\tType\tOpcode\tNo_of_operands\tLength\n\n";
	cout<<"==============================================================================\n";
	for(i=0;i<18;i++)
	{
	   cout<<d[i].mne<<"\t\t"<<d[i].type<<"\t"<<d[i].opcode<<"\t"<<d[i].n_operand<<"\t\t"<<d[i].size<<"\t\t"<<endl;
	}
	cout<<"\n=====================================================================\n";	
	
	search();
} 
void search()
{
    data d[20];
    fstream f1;
    int i,j,k,line,wc,found=0;
    char c;
    string buffer,temp;
    f1.open("1.txt"); 
      
    while(getline(f1,buffer))
    {
         wc=0;
         line++;
		
		for(i=0;i<buffer.size();i++)
		{
			c=buffer[i];
			if(c==' ' || c=='\n')
				wc++;
		}
		if(wc<4)
		{
		   for(j=0;j<buffer.size();j++)
		    {
		       if(buffer[j]==' ' || buffer[j]=='\n')
		          break;
		       else
		       {
		          temp[j]=buffer[j]; 
		       }    
		    }
		    
		    
		}
		else if(wc==4)
		{
		    for(j=0;j<buffer[j]!=' ';j++);
		    
		    for(k=j;k<buffer.size();k++)
		    {
		       if(buffer[k]==' ' || buffer[k]=='\n')
		          break;
		       else
		       {
		          temp[k]=buffer[k];  
		          cout<<temp[j];  
		       }   
		    }
		    
		}
		for(k=0;k<18;k++)
		{ 
		   if(temp==d[k].mne)
		   {
		      cout<<"\nMnemonics Found is"<<temp<<"\n";
		      break;
		   }      
		}
		if(k==18)
		   cout<<"\nMnemonics not found is"<<temp<<"\n";
	}
}        
         
	
