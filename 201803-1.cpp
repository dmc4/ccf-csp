#include <iostream>

using namespace std;

int main()
{
	int a = 1, sum = 0, acc = 0;
	
	
	while(a != 0)
	{
		cin>>a;
		if (a == 0)
			break;
		else if (a == 1)
		{
			sum = sum + 1;
			acc = 0;
		}
		else
		{
			acc = acc + 2;
			sum = sum + acc;
		}
	}
	
	cout<<sum;
	return 0;
}
