#include <iostream>
#include <vector>
#include <cstring> 

typedef long long LL;
using namespace std;

const int N = 10005, M = 100010, mod = 1e9+7;


int a[N];
int f[N] = {0};
vector<int> q[M];
bool st[M];

int main()
{
	for (int i = 1; i < M; i++)
	{
		for (int j = i * 2; j < M; j = j + i)
			q[j].push_back(i);
	}
	
	int n;
	cin>>n;
	
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
	f[0] = 1;
	for (int i = 0; i < n; i++)
	{
		memset(st, 0, sizeof st); 
		for (int j = i - 1; j >= 0; j--)
		{
			int d = a[i] - a[j], count = 0;
			for (int k : q[d])
			{
				if (!st[k])
				{
					count++;
					st[k] = true;
				}
			}
			st[d] = true;
			f[i] = (f[i] + (LL) f[j] * count) % mod;
		}
	}
	
	cout<<f[n - 1]<<endl;
	return 0;	
} 
