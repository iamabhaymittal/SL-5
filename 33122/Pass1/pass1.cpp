#include<bits/stdc++.h>
using namespace std;

typedef struct OPTAB
{
	char mnemonic_code[10];
	int machine_code;
	char class_of_is[3];
	int no_operands;
	int chain;
}OPTAB;

OPTAB optab[]={	{},
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
					{},
					{},
					{},
					{},
					{}

		};
		
typedef union length_or_value
{
	int length;
	char value[5];
}lorv;

typedef struct SYMTAB
{
	string sym_name;
	char address[20];
	lorv var;
}SYMTAB;

SYMTAB symtab[20];

typedef struct LITTAB
{
	string lit_name;
	char address[20];
}LITTAB;

LITTAB littab[20];

int pooltab[10];

int lc,ptp,ltp,stp;

enum rc{areg=1,breg=2,creg=3,dreg=4};

void initialise()
{
	lc=0;
	ptp=ltp=stp=1;
	pooltab[1]=1;
}

bool isMnemonic(string s)
{
    
if(s=="BC" || s=="ADD" || s=="SUB" || s=="START" || s=="COMP" || s=="DIV" || s=="END" || s=="EQU" || s=="DC" || s=="DS"||        s=="MOVER"  || s=="MOVEM" || s=="LTORG" || s=="MULT" || s=="ORIGIN" || s=="PRINT" || s=="READ" || s=="STOP")
        return true;    
    return false;
}


bool isLiteral(string s)
{
    int ascii=(int )s[0];

    if(ascii<65 || (ascii>90&&ascii<97) ||ascii>122)return true;
    return false;
}

bool isSymbol(string s)
{
    
    for(int i=0;i<s.size();i++)
    {
         int ascii=(int )s[i];
        if(ascii<65 || (ascii>90&&ascii<97) ||ascii>122)
        {
            return false;
        }
    }
    
    return true;
}

int checkSymtab(string s)
{
    for(int i=0;i<20;i++)
        if(s==symtab[i].sym_name)return i;
    return -1; 
}

int main(){
    initialise();
    fstream fp;
    string line,word;
    vector <string> s;
    enum rc r_code;
    
    
    fp.open("sample",ios::in);
    
    while(getline(fp,line))
    {
        s.clear();
        
        int word_count=0;
        for(int i=0;i<line.size();i++)
        {
               if(line[i]!=' ')word.push_back(line[i]);
               else
               {
                    s.push_back(word);
                    word.clear();
               }
        }
        s.push_back(word);
        word.clear();
        
      // for(int i=0;i<s.size();i++)cout<<s[i]<<" ";
       //cout<<endl;
       
        bool flag=false;
        int i=0;
        for(i=0;i<27;i++)
        {
            if(optab[i].mnemonic_code == s[0])
            {
                flag=true;
                break;
            };                      
        }
        
        if(flag==true)  //1st field is mnemonic
        {

            string class1=optab[i].class_of_is;
            int code=optab[i].machine_code;
            
            if(s.size()==2) //Only 1 operand is present
            {               
                cout<<"("<<class1<<","<<code<<") "<<"(C,"<<s[1]<<")"<<endl;
            }
            if(isLiteral(s[2]) && s.size()==3)
            {
                int temp=ltp;
                //r_code=s[1];
                littab[ltp++].lit_name=s[2];
                cout<<"(IS,"<<code<<") "<<"(R,"<<1<<") "<<"(L,)"<<temp<<")"<<endl;
            }
            
           /* if(isSymbol(s[2]) && s.size()==3)
            {
                int temp=stp;
                r_code=s[1];
                
                int result=checkSymtab(s[2]);
                if(result==-1)
                {
                    result=stp;
                    symtab[stp++].sym_name=s[2];
                }
                cout<<"(IS,"<<code<<") "<<"(R,"<<r_code<<") "<<"(S,)"<<result<<")"<<endl;
                
            }*/

        }
   }
        
        
        
        
    fp.close();
    return 0;
}
