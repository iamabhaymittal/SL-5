#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include<string.h>
using namespace std;


int main()
{
    int i = 0;
    vector<int> indices;
    vector<char> word;
    vector<int>::iterator ptr;
    vector<char>::iterator it2;
    fstream fp, fp1;
    fp.open("file1.txt", ios::out);
    char write_buffer[100];
    char read_buffer[100];

    cout << "Enter paragraph:";
    cin.getline(write_buffer, sizeof(write_buffer));
    fp.write(write_buffer, sizeof(write_buffer));
    //cout<<endl<<write_buffer;
    fp.close();
    fp.open("file1.txt", ios::in);
    fp.read(read_buffer, sizeof(read_buffer));
  
    
    for (int i = 0; i < sizeof(read_buffer); i++)
    {
        if (read_buffer[i] == ' ' || read_buffer[i] == '\0' )
        {
            indices.push_back(i);
        }
    }
    int start = 0;


    fp1.open("outfile.txt",ios::out);

    for (ptr = indices.begin(); ptr < indices.end(); ptr++)
    {
        //cout << *ptr;
        while (start != *ptr)
        {
            if(start > strlen(write_buffer))
            break;
            //cout<<read_buffer[start];
            fp1<<read_buffer[start];
            start++;
        }
        if (start == *ptr)
        {
            fp1<<"\n";    
            start++;
        }
        /*for (it2 = word.begin(); it2 < word.end(); it2++)
        {
            cout << *it2;
        }*/
        word.clear();
    }
    fp.close();
    cout << endl;
    return 0;
}