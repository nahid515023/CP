#include<bits/stdc++.h>
using namespace std;

long long dp[100007];

long long func(int n)
{
	if(n==1) return 1;
	if(n==2) return 2;
	if(dp[n]!=-1) return dp[n];
	long long a = func(n-1)+func(n-2);
	return dp[n]=a%100007;
}

int main()
{
	long long n;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	cout<<func(n)<<endl;
}