#include <iostream>

using namespace std;


int main()
{
	
	int n,m;
	cin>>n>>m;
	
	int sum = 0, maxCount = 0, maxIndex = -1;
	for (int i = 1; i <= n; i++)
	{
		int c;
		cin>>c;
		int tempCount = 0;
		for(int j = 0; j < m; j++)
		{
			int temp;
			cin>>temp; 
			c = c + temp;
			tempCount = tempCount - temp;
		} 
		if (tempCount > maxCount)
		{
			maxCount = tempCount;
			maxIndex = i;
		}
		
		sum = sum + c;
	}
	
	cout<<sum<<" "<<maxIndex<<" "<<maxCount;
	return 0;	
} 
