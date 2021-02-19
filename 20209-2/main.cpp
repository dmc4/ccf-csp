//get line

#include <iostream>

using namespace std;
ostream &debug = cout; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAX_N = 20 + 1;
const int MAX_T = 1E3 + 1;
//vector<pair<int, int>> people[MAX_T]
int stay = 0, th = 0;

int main(int argc, char** argv) {
	
	int n, k, t;	
	int xl, yd, xr, yu;
	
	cin>>n>>k>>t;
	cin>>xl>>yd>>xr>>yu;
	
	//if(n > 20 || t > 1E3 || k > 1E3)
		//return 1;
	
	if (n < 1)
		return 2;
	
	int i, j, b[MAX_N] = {0};
	for(i = 0; i < n; ++i)
	{
		int throu = 0; //jinguo
		
		for (j = 0; j < t; ++j)
		{
			//debug<<endl<<":"<<j<<":"<<endl;
			int x, y;
			cin>>x>>y;
			//debug<<x<<" "<<y;	
			if (x >= xl && x <= xr && y >= yd && y <= yu)
			{
				throu = 1;
				b[i]++;
			}
			else if(b[i] < k)
			{
				b[i] = 0;
			}	
		}	
		
		if  (b[i] >= k)
			stay++;
		
		th = th + throu;
		
		//cout<<endl;
		//debug<<endl<<"-----"<<i<<"------"<<"th: "<<th<<"stay: "<<stay<<"b: "<<b[i]<<endl;
	} 
	
	cout<<th<<endl<<stay;
	
	return 0;
}
