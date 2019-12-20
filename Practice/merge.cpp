#include<iostream>
#include<stdlib.h> 
#include<stdio.h> 
using namespace std;

void printArray(int A[], int size)
{
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return ;
}

//Function to merge two arrays
void merge(int arr[], int l, int m, int r)
{
	int i,j,k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1], R[n2];
	
	
	for(i=0; i<n1; i++)
	{
		L[i] = arr[l+i];
	}
	for(i=0; i<n2; i++)
	{
		R[i] = arr[m+1+i];
	}
	
	
	
	
	//Intial values of each
	i = 0;
	j = 0;
	k = l;
	
	//Comparing mini-array
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k] = R[j];
		k++;
		j++;
	}
	
	
}
//Function to sort an array
void mergeSort(int arr[], int l, int r)
{
	int m = l + (r-l)/2;
	if(l<r)
	{
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr, l, m, r);
	}
	
	
}

int main()
{
	int arr[] = {2, 5, 6, 1, 99, 7, 0, 3};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,arr_size);
	mergeSort(arr,0,arr_size-1);
	cout<<endl<<"Elements after merge sort:";
	printArray(arr,arr_size);
	return 0;
}


































