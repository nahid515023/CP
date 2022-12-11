#include <bits/stdc++.h>
using namespace std;

void countSort(int n, int a[], int k)
{
	int c[k+1];
	int b[n+1];

	for(int i=0;i<=k;i++)
		c[i]=0;

	for(int i=0;i<n;i++)
	{
		c[a[i]]++;
	}

	for(int i=1;i<=k;i++)
	{
		c[i]+=c[i-1];
	}

	for(int i=n-1;i>=0;i--)
	{
		b[(--c[a[i]])]=a[i];
	}

	for (int i = 0; i < n; i++)
	{
		a[i]=b[i];
	}
}

int main()
{

	int n;
	cin >> n;
	int arr[n];
	int mx = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	countSort(n, arr, mx);
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout << endl;
	return 0;
}