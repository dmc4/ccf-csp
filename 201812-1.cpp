#include <iostream> 

using namespace std;

int r[4];

int main()
{
	cin>>r[1]>>r[2]>>r[3];
	int n, sum = 0;
	cin>>n;
	
	while(n--)
	{
		int a, b;
		cin>>a>>b;
		if (a == 0 || a == 1)
		{
			sum = sum + b;
		}
		else if (a == 2)
		{
			sum = sum + b;
			sum = sum + r[1];
		}
		else if (a == 3)
		{
			
		}
	}
	
	cout<<sum<<endl;
	return 0;
}
