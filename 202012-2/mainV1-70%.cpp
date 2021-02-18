#include <iostream>
#include <map> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//ostream& // = std::cout;

enum result {fail = 0, pass = 1};
struct inputSet
{
	int y;
	result res;
};



int main(int argc, char** argv) {
	
	int m;
	inputSet *inputset;
	
	std::cin>>m;
	
	if (m < 2 || m > 100000)
		return 1;
	
	inputset = new inputSet [m];
	
	map<int, int> val;
	
	for (int i = 0; i < m; i++)
	{
		int res;
		cin>>inputset[i].y;
		cin>>res;
		inputset[i].res = static_cast<result>(res);
		if (val.find(inputset[i].y) == val.end())
		{
			val.insert(pair<int, int>(inputset[i].y, 0));
		}
		
	}
	
	int max = 0, maxIndex = 0;
	
	for (int i = 0; i < m; i++)
	{
		if (val[inputset[i].y] != 0)
		{
			val.insert(pair<int, int>(inputset[i].y, 0));
		}

	}
	
	/*
	map<int, int>::iterator pos;
	for (pos = val.begin(); pos != val.end(); ++pos)
	{
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			if ((inputset[i].y < pos->first) && inputset[i].res == fail)
			{
				count++;
			}
			else if ((inputset[i].y >= pos->first) && inputset[i].res == pass)
			{
				count++;
			}
		}
		
		
		//<<pos->first<<": "<<count<<endl;
		if (count>=max)
		{
			max = count;
			//if (pos->first > maxIndex)
			maxIndex = pos->first;
		}
		//<<"-----------"<<endl;
	}
	*/
	cout<<maxIndex<<endl;
	delete [] inputset;
	return 0;
}
