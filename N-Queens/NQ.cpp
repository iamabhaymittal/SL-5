#include<iostream>
#include<stdlib.h>
using namespace std;

void NQueens(int k, int N, int x[])
{
	
	for(int i=0;i<N;i++)
	{
		if(Place(k,i,x))
		{
			
		}
	}
}
int Place(int k, int i, int x[])
{
	for(int j=0;j<k;j++)
	{
		if(x[j] == i || abs(j-k) == abs(x[j]-i))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}


int main()
{
	int N;
	cout<<"\nEnter the value of N:";
	cin>>N;
	
	return 0;
}
