#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
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

int main()
{
    fstream fp;
    struct Sym_Tab ST[20];
    struct Literal_Table LT[10];
    int i, j;
    int LC, ltc = 0, stc = 0;
    char label[20], opcode[20], operand[20];

    //Initializing literal table
    for (i = 0; i < 10; i++)
        LT[i].val = -1;
    fp.open("ass_prog.txt", ios::out);
    fp >> label >> opcode >> operand;

    cout << "\n The Source Program is";
    cout << "\n -----------------------------";
    cout << "\n Label\tOpcode\tOperand";
    cout << "\n -----------------------------";
    while (strcmp(opcode, "END") != 0)
    {
        cout << "\n " << label << " \t" << opcode << " \t" << operand;

        i = 0;
        while (operand[i] != '\0')
        {
            if (operand[i] == '=')
            {
                j = 0;
                while (operand[i] != '\0')
                    LT[ltc].literal[j++] = operand[i++];
                LT[ltc].literal[j] = '\0';
                ltc++;
            }
            else
            {
                i++;
            }
        }
        if (strcmp(opcode, "START") == 0)
        {
            if (strcmp(operand, "-") != 0)
            {
                LC = atoi(operand) - 1;
            }
            else
            {
                LC = -1;
            }
        }
        if (strcmp(opcode, "EQU") == 0)
        {
            strcpy(ST[stc].symbol, label);
            ST[stc].val = atoi(operand);
            stc++;
            LC--;
        }
        else if (strcmp(label, "-") != 0)
        {
            strcpy(ST[stc].symbol, label);
            ST[stc].val = atoi(operand);
            stc++;
            LC--;
        }
        else if (strcmp(label, "-") != 0)
        {
            strcpy(ST[stc].symbol, label);
            ST[stc].val = LC;
            stc++;
        }
        if (strcmp(opcode, "ORIGIN") == 0)
        {
            LC = atoi(operand) - 1;
        }

        if (strcmp(opcode, "LTORG") == 0)
        {
            for (i = 0; i < ltc; i++)
            {
                LT[i].val = LC;
                LC++;
            }
            LC--;
        }
        LC++;
        fp >> label >> opcode >> operand;
    }
    fp.close();
    for (i = 0; i < ltc; i++)
    {
        if (LT[i].val == -1)
        {
            LT[i].val = LC;
            LC++;
        }
    }
    cout << "\n The Symbol Table is ";
    cout << "\n ------------------------------------------- ";
    cout << "\nSymbol\tAddress";
    cout << "\n -------------------------------------------\n";
    for (i = 0; i < stc; i++)
    {
        cout << ST[i].symbol << "\t" << ST[i].val;
    }
    cout << "\n The Literal Table is ";
    cout << "\n ------------------------------------------- ";
    cout << "\nLiteral\tAddress";
    cout << "\n -------------------------------------------\n";
    for (i = 0; i < ltc; i++)
    cout<<LT[i].literal<<" \t "<<LT[i].val;
    cout << endl;
    return 0;
}
