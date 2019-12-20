#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	fstream fp;
	fp.open("file1.txt",ios::out);	
	char buffer[100];
	cout<<"Enter data:";
	cin.getline(buffer,sizeof(buffer));
	
	fp.close();
	return 0;
}
