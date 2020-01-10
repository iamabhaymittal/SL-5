#include<iostream>
#include<stdlib.h>
using namespace std;
int Place(int k, int i, int x[])
{
	for(int j=0;j<k;j++)
	{
		if(x[j] == i || abs(j-k) == abs(x[j]-i))
		{
			return 0;
		}
			
	}
	return 1;
}

void printBoard(int x[], int N)
{
	cout<<endl<<endl;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			
			if(x[i]==j)
			{
				cout<<"Q ";
			}
			else
			{
				cout<<"- ";
			}
			
		}
		cout<<endl;
	}
}

void NQueens(int k, int N, int x[])
{
	
	for(int i=1;i<=N;i++)
	{
	
		if(Place(k,i,x))
		{
		//printArray(x,N);
			x[k] = i;
			//printBoard(x,N);
			if(k==N)
			{
				cout<<"Solution:";
				printBoard(x,N);
				//cout<<"abc"<<endl;
			}
			else
			{
				NQueens(k+1,N,x);
			}
			
		}
		
	
	}
	
}


int main()
{
	int N;
	cout<<"\nEnter the value of N:";
	cin>>N;
	int x[N+1]={0};
	NQueens(1,N,x);
	return 0;
}
