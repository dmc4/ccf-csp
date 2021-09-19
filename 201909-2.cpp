#include <iostream>

using namespace std;

const int N = 10010;
int n;
bool drop[N] = {false};
int main()
{
	int T = 0, D = 0, E = 0; 
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int m, num;
		cin>>m>>num;
		for (int j = 0; j < m - 1; j++)
		{
			int a;
			cin>>a;
			
			//process
			if (a <= 0)
			{
				num = num + a;
			}
			else
			{
				if (num > a)
				{
					if (!drop[i])
						D++;
					drop[i] = true;
				}
				num = a;
			}
				
		} 
		T = T + num;
	}
	
	if (drop[0] && drop[1] && drop[n - 1])
		E++;
	if (drop[0] && drop[n - 1] && drop[n - 2])
		E++;
		
	for (int i = 1; i < n - 1; i++)
	{
		if (drop[i] && drop[i - 1] && drop[i + 1])
			E++;
	}
	
	cout<<T<<" "<<D<<" "<<E;
	return 0;
} 
