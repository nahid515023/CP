#include <iostream>
using namespace std;

int partition(int b, int e, int arr[])
{
	int pivot = arr[b];
	int i = b, j = e;
	while (i < j)
	{
		while (pivot >= arr[i])
		{
			i++;
		}
		while (pivot < arr[j])
		{
			j--;
		}
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[b], arr[j]);
	return j;
}

void quickSort(int low, int high, int arr[])
{
	if (low < high)
	{
		int p = partition(low, high, arr);
		quickSort(low, p - 1, arr);
		quickSort(p + 1, high, arr);
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n + 1];
	srand(time(0));
	for(int i=0;i<n;i++)
	 arr[i]=rand()%n+1;
	time_t s,e;
	s =clock();
	quickSort(0, n - 1, arr);
	e = clock();
	double ts = (double)(e-s)/1000;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout<<"Time take :"<<ts<<"s"<<endl;
}
