#include<bits/stdc++.h>
using namespace std;
vector<int> g[100],r_g[100];
vector<bool>used;
vector<int>order;

void dfs1(int v)
{
	used[v]=true;
	for(int &ch:g[v])
	{
		if(!used[ch])
		{
			dfs1(ch);
		}
	}
	order.push_back(v);
}

void dfs2(int v)
{
	used[v]=true;
	cout<<v<<" ";
	for(int &ch:r_g[v])
	{
		if(!used[ch])
		{
			dfs2(ch);
		}
	}
}



int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		int U,V;
		cin>>U>>V;
		g[U].push_back(V);
		r_g[V].push_back(U);
	}
	
	used.assign(v,false);
	for(int i=0;i<v;i++)
	{
		if(!used[i])
		{
			dfs1(i);
		}
	}

	reverse(order.begin(),order.end());

	used.assign(v,false);

	for(int &x:order)
	{
		if(!used[x])
		{
			dfs2(x);
			cout<<endl;
		}
	}

}