#include <iostream>
using namespace std;

void redixSort(int n,int a[],int pos)
{
	int c[9];
	int b[n];
	for(int i=0;i<=9;i++)
		c[i]=0;
	for(int i=0;i<n;i++)
	{
		c[(a[i]/pos)%10]++;
	}
	for(int i=1;i<=9;i++)
	{
		c[i]+=c[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		b[--c[(a[i]/pos)%10]]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		a[i]=b[i];
	}
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	int mx=-1;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		mx = max(mx,arr[i]);
	}
	for(int i=1;mx/i;i*=10)
		redixSort(n,arr,i);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}