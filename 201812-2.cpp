#include <iostream>

using namespace std;

typedef long long LL;

int r[4];//int r, y, g;

int main()
{
	cin>>r[1]>>r[2]>>r[3];
	int c = r[1] + r[2] + r[3]; 
	int n;
	LL sum = 0;
	cin>>n;
	while (n--)
	{
		LL k, t;
		cin>>k>>t;
		if (k == 0)
		{
			sum = sum + t;
		}
		else 
		{
			if (k == 1)
			{
				t = r[1] - t;
			}
			else if (k == 2)
			{
				t = c - t;
			}
			else
			{
				t = r[1] + r[3] - t;
			}
			t = t + sum;
			t = t % c;
			if (t < r[1])
				sum = sum + r[1] - t;
			else if (t >= r[1] + r[3])
				sum = sum + c - t + r[1];
		}
	} 
	cout<<sum;
	return 0;
} 
