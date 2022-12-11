#include<iostream>
using namespace std;
const int MX = 100000;
int pi[MX];

void createPiTable(string p)
{
	int m = p.size();
	pi[0]=0;
	int i=1;
	int j=0;
	while(i<m)
	{
		if(p[i]==p[j])
		{
			pi[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
		{
			j=pi[j-1];
		}
		else{
			pi[i]=0;
			i++;
		}
	}
}

int KmpSearch(string s,string p)
{
	int n = s.size();
	int m = p.size();
	createPiTable(p);
	int i=0,j=0;
	while(i<n)
	{
		if(s[i]==p[j])
		{
			if(j==m-1)
				{
					return i-j;
				}
			else
			{
				i++;
				j++;
			}
		}
		else{
			if(j>0)
			{
				j=pi[j-1];
			}
			else{
				i++;
			}
		}
	}

	return -1;
}


int main()
{
	string s,p;
	cin>>s>>p;
	int ans = KmpSearch(s,p);
	if(ans!=-1)
	{
		cout<<ans+1<<endl;
		cout<<"Pattern is match.."<<endl;
	}
	else{
		cout<<"Pattern is not match.."<<endl;
	}

}