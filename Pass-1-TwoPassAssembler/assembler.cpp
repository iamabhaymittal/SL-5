#include<iostream>
#include<fstream>
using namespace std;
struct Sym_Tab
{
    char symbol[10];
    int val;
};

struct Literal_Table
{
    char literal[10];
    int val;
};

void main()
{
    fstream fp;
    struct Sym_Tab ST[20];
    struct Literal_Table LT[10];
    int i,j;
    int LC, ltc = 0, stc = 0;
    char label[20], opcode[20], operand[20];

    //Initializing literal table
    for(i=0;i<10;i++)
    LT[i].val = -1;
    fp.open("ass_prog.txt","r");
    

    
}
