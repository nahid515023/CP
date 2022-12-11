#include<bits/stdc++.h>
using namespace std;

void Print(int arr[],int i,int n)
{
	cout<<"Bass "<<i<<": ";
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" ";
	}
	cout<<endl;
}

void insertionSort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int j=i;
		int key = arr[i];
		while(j>0 && arr[j-1]>key)
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=key;

		Print(arr,i,n);
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++) cin>>arr[i];
		insertionSort(arr,n);
}