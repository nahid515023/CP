#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int parent,int a[],int n)
{
	int left_child = parent*2+1;
	int right_child = parent*2+2;
	int largest = parent;
	if(left_child<n && a[largest]<a[left_child])
	{
		largest = left_child;
	}
	if(right_child<n&&a[right_child]>a[largest])
	{
		largest = right_child;
	}
	if(largest!=parent)
	{
		swap(a[largest],a[parent]);
		maxHeapify(largest,a,n);
	}
}

void buildMaxHeap(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		maxHeapify(i,a,n);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(a[i],a[0]);
		maxHeapify(0,a,i);
	}
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	buildMaxHeap(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}