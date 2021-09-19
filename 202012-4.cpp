#include <iostream> 
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110, M = 11, K = 11, S = 1 << 10;

int need[N][M];
int n, m, k;
int tot = 0;
int ver[N * 2], edge[N * 2], ne[N * 2], head[N];
int d[N][M];
int f[S], state[N];


void add(int a, int b, int c)
{
	ver[++tot] = b, edge[tot] = c;
	ne[tot] = head[a], head[a] = tot;
}

pair<int, int> dfs(int a, int father, int b)
{
	pair<int, int> res(0, -1);
	if (need[a][b] != 0)
		res.second = 0;
	
	for (int i = head[a]; ~i; i = ne[i])
	{
		int v = ver[i];
		if (v == father)
			continue;
		auto r = dfs(v, a, b);
		if (r.second != -1)
		{
			res.first = res.first + r.first + edge[i] * 2;
			res.second = max(res.second, r.second + edge[i]);
		}
	}
	
	return res;
}

bool check(int mid)
{
	memset(state, 0, sizeof state);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (d[i][j] <= mid)
				state[i] |= 1 << j;
		}
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < 1 << k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i | state[j]] = min(f[i | state[j]], f[i] + 1);
		}
	}
	return f[(1 << k) - 1] <= m;
}

int main()
{
	cin>>n>>m>>k;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
			cin>>need[i][j];
	}
	
	memset(head, -1, sizeof(head));
	for (int i = 0; i < n - 1; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a, b, c);
		add(b, a, c);
	}
	
	for(int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
				auto r = dfs(i, -1, j);
				if (r.second != -1)
				{
					d[i][j] = r.first - r.second;
				}
		}	
	} 

	int l = 0, r = 2e8;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	
	cout<<r<<endl;
	
/* 
	cout<<"______________________\n"; 
	for(int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"______________________\n"; 
*/	
	/*
	for (int i = 1; i <= n; i++ )
	{
		for (int j = head[i]; ~j; j = ne[j])
		{
			cout<<i<<" "<<ver[j]<<" "<<edge[j]<<" "<<j<<" "<<~j<<ne[j]<<endl;
		}
		cout<<"-----------\n";
	}
	*/
	return 0;
}
