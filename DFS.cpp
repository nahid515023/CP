#include<bits/stdc++.h>
using namespace std;
vector<int>g[100];
vector<bool>visited(100,false);

bool dfs(int v,int p)
{
	visited[v]=true;
	for(int &x:g[v])
	{
		if(!visited[x])
		{
			if(dfs(x,v)==true) return true;
		}
		else{
			if(x!=v)
				return true;
		}
	}
	return false;
}

void bfs(int v)
{
	stack<int>q;
	q.push(v);
	while(!q.empty())
	{
		int t = q.top();
		visited[t]=true;
		cout<<t<<"-->";
		 q.pop();
		for(int &x:g[t])
		{
			if(!visited[x])
			{
				q.push(x);
			}
		}
	}
}


int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout<<dfs(1,-1)<<endl;
	// bfs(6);
}
