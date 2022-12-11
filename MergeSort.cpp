#include<bits/stdc++.h>
using namespace std;
int r,x=0;

void print(int arr[])
{
	// cout<<"Bass "<<++x<<": ";
	for(int i=0;i<r;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void merge(int arr[],int b,int mid,int e)
{
	int n1 = mid-b+1;
	int n2 = e-mid;
	int leftArr[n1];
	int rightArr[n2];
	for(int i=0;i<n1;i++)
	{
		leftArr[i]=arr[b+i];
	}
	for(int j=0;j<n2;j++)
	{
		rightArr[j]=arr[mid+j+1];
	}
	int i=0,j=0,k=b;
	while(i<n1 && j<n2)
	{
		if(leftArr[i]<rightArr[j])
		{
			arr[k]=leftArr[i];
			i++;
		}
		else{
			arr[k]=rightArr[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=leftArr[i];
			i++;
			k++;
	}
	while(j<n2)
	{
		arr[k]=rightArr[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int b,int e)
{
	if(b<e)
	{
		int mid = (int)(b+e)/2;
		mergeSort(arr,b,mid);
		mergeSort(arr,mid+1,e);
		merge(arr,b,mid,e);
	}
}


int main()
{
	int n;
	cin>>n;
	r=n;
	int arr[n+1];
	srand(time(0));
	for(int i=0;i<n;i++)
	 arr[i]=rand()%n+1;
	time_t s,e;
	s =clock();
	mergeSort(arr,0,n-1);
	e = clock();
	// print(arr);
	double ts = (double)(e-s)/1000;
	cout<<"Time take :"<<ts<<endl;
	return 0;
}