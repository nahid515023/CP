#include <bits/stdc++.h>
using namespace std;
const int lg = 17;
const int mx = 100007;
int table[mx][lg];
int bin_log[mx];

int query(int L, int R)
{
    int len = R - L + 1;
    int j = bin_log[len];
    return min(table[L][j], table[R - (1 << j) + 1][j]);
}

void SparseTable(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        table[i][0] = a[i];
    }
    bin_log[0] = 0;
    bin_log[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        bin_log[i] = bin_log[i / 2] + 1;
    }

    for (int k = 1; k < lg; k++)
    {
        for (int i = 0; (i + (1 << k) - 1) < n; i++)
        {
            table[i][k] = min(table[i][k - 1], table[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SparseTable(n,arr);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l-1, r-1) << endl;
    }
}