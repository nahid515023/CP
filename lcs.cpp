#include <bits/stdc++.h>
using namespace std;
int dp[55][55][55];
string s,p,r;

int lcs(int n, int m,int l)
{
    if (n == 0 || m == 0 || l==0)
    {
        return 0;
    }
    if(dp[n][m][l]!=-1)
    {
        return dp[n][m][l];
    }
    if (s[n - 1] == p[m - 1] && r[l-1]==s[n-1])
    {
        return dp[n][m][l]=1 + lcs(n - 1, m - 1,l-1);
    }
    else
    {
        return dp[n][m][l]=max(lcs(n-1,m,l),max(lcs(n,m-1,l),lcs(n,m,l-1)));
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,inx=0;
    cin>>t;
    inx=1;
    while(t--)
    {
        cout<<"Case "<<inx<<": ";
        memset(dp,-1,sizeof(dp));
        cin >> s >> p>>r;
        int n = s.size();
        int m = p.size();
        int l=r.size();
        cout<<lcs(n,m,l)<<endl;
        inx++;
    }
}