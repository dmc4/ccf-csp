#include <iostream>
//#include <tuple>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAX_N = 1E3 + 5;
const int MAX_M = 21;

//tuple<int, int char> point[MAX_N];

struct Point{
	int x;
	int y;
	char tpye;
};
Point point[MAX_N];

struct Line{
	int t0;
	int t1;
	int t2;
};

Line line[MAX_N];

int main(int argc, char** argv) {
	
	int n, m;
	cin>>n>>m;
	
	for(int i = 0; i < n; i++)
	{
		cin>>point[i].x>>point[i].y>>point[i].tpye;
	}
	
	for(int i = 0; i < m; i++)
	{
		cin>>line[i].t0>>line[i].t1>>line[i].t2;
	}
	
	for(int i = 0; i < m; i++)
	{
		char sideA = 'c', sideB = 'c';
		bool NO = false;

		for(int j = 0; j < n; j++)
		{
			int res = line[i].t0 + line[i].t1 * point[j].x + line[i].t2 * point[j].y;
			if (res > 0)
			{
				if (sideA != 'c' && sideA != point[j].tpye)
				{
					cout<<"No"<<endl;
					NO = true;
					//cout<<"i: "<<i<<"j: "<<j<<endl;
					break;
				}
				else
				{
					sideA = point[j].tpye;
				}
			}
			else if (res < 0)
			{
				if (sideB != 'c' && sideB != point[j].tpye)
				{
					cout<<"No"<<endl;
					NO = true;
					//cout<<"i: "<<i<<"j: "<<j<<endl;
 
					break;
				}
				else
				{
					sideB = point[j].tpye;
				}
			}
		}
		if (!NO)
			cout<<"Yes"<<endl;
		
	}
	
	
	return 0;
}
