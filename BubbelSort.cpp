#include <bits/stdc++.h>
using namespace std;

void bubbelSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        cout << "Bass " << i + 1 << ":" << endl;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
            cout << j + 1 << " --> ";
            for (int k = 0; k < n; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubbelSort(arr, n);
}