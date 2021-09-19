#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;
int n;
int q[N];

int main()
{
	cin>>n;
	for (int i = 0; i < n; i++)
		cin>>q[i];
	int res[3];
	res[0] = q[0] * 2;
	res[1] = q[n - 1] * 2;
	
	if (n % 2)
		res[2] = q[n/2] * 2;
	else
	{
		res[2] = q[n/2 - 1] + q[n / 2];
	}
	sort(res, res + 3);
	
	for (int i = 2; i >= 0; i--)
	{
		if (res[i] % 2)
			cout<<(double) res[i]/ 2.0<<" ";
		else
			printf("%d ", res[i]/2);
	}
	return 0;	
} 
