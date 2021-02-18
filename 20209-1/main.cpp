#include <iostream>
#include <utility> 

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAX_M = 200;

int main(int argc, char** argv) {
	
	int m; 
	std::cin>>m;
	
	if (m < 3 || m > MAX_M)
		return 1;
	
	pair<int, int> guy;
	cin>>guy.first>>guy.second;
	//pair<int, int> point[MAX_M];
	pair<int, int> first = make_pair(-1, 999999999);
	pair<int, int> second = make_pair(-1, 999999999);
	pair<int, int> third = make_pair(-1, 999999999);
	
	for(int i = 1; i <= m; ++i)
	{
		int x, y, d;
		cin>>x>>y;
		d = (guy.first - x) * (guy.first - x) + (guy.second - y) * (guy.second - y);
		
		if (d < first.second)
		{
			third.first = second.first;
			third.second = second.second;
			second.first = first.first;
			second.second = first.second;
			first.first = i;
			first.second = d;
		}
		else if (d < second.second)
		{
			third.first = second.first;
			third.second = second.second;
			second.first = i;
			second.second = d;
		}
		else if (d < third.second)
		{
			third.first = i;
			third.second = d;
		}
	}
	
	cout<<first.first<<endl<<second.first<<endl<<third.first<<endl;
	
	
	return 0;
}
