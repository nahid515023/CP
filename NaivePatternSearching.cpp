#include<iostream>
using namespace std;

bool Search(string s,string p)
{
	int n = s.size();
	int m = p.size();

	for(int i=0;i<n-m+1;i++)
	{
		if(s[i]==p[0])
		{
			int ok =1;
			for(int j=0;j<m;j++)
			{
				if(s[i+j]!=p[j])
				{
					ok = 0;
					break;
				}
			}
			if(ok ==1)
			{
				cout<<i<<endl;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	string s,p;
	cin>>s>>p;
	if(Search(s,p))
	{
		cout<<"Pattern is match.."<<endl;
	}
	else{
		cout<<"Pattern is not match.."<<endl;
	}

}