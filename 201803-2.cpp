#include <iostream>
#include <map>
using namespace std;
const int N = 101;


pair<int, int> b[N];
map<int, int> m;
int main()
{
	int n, L, t;
	cin>>n>>L>>t;
	
	for (int i = 0; i < n; i++)
	{
		cin>>b[i].first;
		b[i].second = 1;
	}
	
	while(t--)
	{
		m.clear();
		for (int i = 0; i < n; i++)
		{
			b[i].first = b[i].first + b[i].second;
			if (b[i].first == L || b[i].first == 0)
				b[i].second = -b[i].second;
			
			map<int, int>::iterator it =  m.find(b[i].first);
			if (it == m.end())
			{
				m.insert(make_pair(b[i].first, i));
			}
			else
			{
				b[it->second].second = -b[it->second].second;
				b[i].second = -b[i].second;
			}
			
		}	
		/*
		for (int i = 0; i < n; i++)
		{
			cout<<b[i].first<<" "<<b[i].second<<endl;
		}
		cout<<"-----------------------\n";
		*/
	}
	
	for (int i = 0; i < n; i++)
	{
		cout<<b[i].first<<" ";
	}
	
	return 0;	
} 
