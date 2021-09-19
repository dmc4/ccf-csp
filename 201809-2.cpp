#include <iostream>

using namespace std;

const int N = 2001;
pair<int, int> a[N], b[N];

int main()
{
	int n;
	cin>>n;
	
	int sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	
	for (int i = 0; i < n; i++)
	{
		cin>>b[i].first>>b[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i].second < b[j].first)
				break;
			
			if (a[i].first > b[j].second)
				continue;
			
			if (a[i].first >= b[j].first && a[i].second <= b[j].second)
			{
				sum = sum + a[i].second - a[i].first;
				continue;	
			}
			
			if (a[i].first <= b[j].first && a[i].second >= b[j].second)
			{
				sum = sum + b[j].second - b[j].first;
				continue;	
			}
			
			if (a[i].first > b[j].first && a[i].second > b[j].second)
			{
				sum = sum + b[j].second - a[i].first;
				continue; 
			}
			
			if (a[i].first < b[j].first && a[i].second < b[j].second)
			{
				sum = sum + a[i].second - b[j].first;
				continue;
			}
		}
	}
	cout<<sum;
	return 0;
}
