#include<bits/stdc++.h>
using namespace std;
int dp[100005];
vector<array<int,3>>a(100007);
int n;

int func(int i)
{
	int cost =0;
	if(i>=n) return 0;

	if(dp[i]!=-1) return dp[i];
	cost=func(i+1);
	int f=i,l=n-1;
	int x = a[i][1];

	while(f<l)
	{
		int m = (int)(f+l)/2;
		if(a[m][0]<=x)
		{
			f=m+1;
		}
		else{
			l=m;
		}
	}
	if(f < n && a[f][0] <=x) {
       f++;
    }


	cost = max(cost,func(f)+a[i][2]);
	// cout<<cost<<endl;
	return dp[i]=cost;
}


int main()
{
	cin>>n;
	vector<array<int,3>>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		a[i][0]=arr[i][0];
		a[i][1]=arr[i][1];
		a[i][2]=arr[i][2];
	}
	memset(dp,-1,sizeof(dp));
	cout<<func(0)<<endl;
}