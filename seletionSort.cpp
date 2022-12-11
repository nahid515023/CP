#include<bits/stdc++.h>
using namespace std;

void seletionSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		cout<<"Bass "<<i+1<<": ";
		int mi = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[mi]>arr[j])
			{
				mi = j;
			}
		}
		swap(arr[mi],arr[i]);

		for(int j=0;j<n;j++)
		{
			cout<<arr[j]<<" ";
		}
		cout<<endl;
	}
}


int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++) cin>>arr[i];
	seletionSort(arr,n);
}