#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1000000;
vector<int> lp(N + 1);
vector<int> pr;

set<pair<int, int>> s1;

void linear_sieve()
{
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j)
        {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i])
            {
                break;
            }
        }
    }
}

void prime_fact(int x, int id)
{
    for (int i = 0; i < pr.size() && pr[i] * pr[i] <= x; i++)
    {
        while (x % pr[i] == 0)
        {
            x /= pr[i];
            s1.insert({pr[i], id});
        }
    }
    if (x > 1)
    {
        s1.insert({x, id});
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        prime_fact(x, i + 1);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    linear_sieve();
    while (t--)
    {
        solve();
    }
    return 0;
}
