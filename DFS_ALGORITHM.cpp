#include <bits/stdc++.h>
using namespace std;
vector<int>g[100];
char color[100];
int timeStart[100];
int timeFinish[100];
vector<int>visited_vertex;
int t = 0;

void dfs(int p)
{
	visited_vertex.push_back(p); // visited vertext push in list
	t++;
	timeStart[p]=t;
	color[p]='G';
	for(auto &child:g[p])
	{
		if(color[child]=='W')
		{
			dfs(child);
		}
	}
	color[p]='B';
	t++;
	timeFinish[p]=t;
}

int main()
{
	int n,m; // n number of vertex and m number of node
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v); // taking directed graph input
	}

	for(int i=1;i<=n;i++)
	{
		color[i]='W'; // all vertex color white
	}

	for(int i=1;i<=n;i++)
	{
		visited_vertex.clear();
		if(color[i]=='W')
		{
			dfs(i); // dfs calling
			for(auto &x:visited_vertex)
			{
				cout<<x<<" time : "<<timeStart[x]<<"/"<<timeFinish[x]<<endl;
			}
			cout<<endl;
		}
		
	}
}