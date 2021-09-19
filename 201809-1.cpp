#include <iostream>

using namespace std;

const int N = 1001;
int a[N];

int main()
{
	int n;
	cin>> n;
	
	
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			cout<<(a[i + 1] + a[i]) / 2<<" ";
		else if (i == n)
			cout<<(a[i] + a[i - 1]) / 2<<" ";
		else
			cout<<(a[i + 1] + a[i] + a[i - 1]) / 3<<" ";
	}
	
	return 0;	
} 
