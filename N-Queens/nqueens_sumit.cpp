#include<bits/stdc++.h>
using namespace std;

int x[10];
bool place(int k,int pos)
{
	for(int i=1;i<k;i++)
	{
		if((x[i]==pos) || (abs(x[i]-pos)==abs(i-k)))return false;
	}
		return true;
}
void nQueens(int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n){
				cout<<"---------------------"<<endl;
				for(int j=1;j<=n;j++){
					for(int i=1;i<=n;i++){

						if(x[j]==i)cout<<"Q"<<" ";
						else cout<<0<<" ";
					}
					cout<<endl;
				}
				cout<<"---------------------"<<endl;
			}
			else
				nQueens(k+1,n);
		}

	}
}

int main()
{
	int n=4;
	for(int i=1;i<=n;i++)
		nQueens(i,n);

	return 0;
}