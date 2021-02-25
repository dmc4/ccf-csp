#include <iostream>
#include <map>
#include <set>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

map<long int, long int> A, B;
set<long int> aSet;
set<long int> bSet;


int main(int argc, char** argv) {
	long int n, a, b;
	cin>>n>>a>>b;
	long long res = 0;
	
	//if (n > 1E9 || a >)
	
	for(long int i = 0; i < a; i++)
	{
		long int in, val;
		cin>>in>>val;
		aSet.insert(in);
		A.insert(pair<int, int>(in, val));
	}
	
	for(long int i = 0; i < b; i++)
	{
		long int in, val;
		cin>>in>>val;
		//bSet.insert(in);
		//if (aSet.count(in) == 1)
		{
			//B.insert(pair<int, int>(in, val));
		}
		
		res += val * A[in];
	}
	
	set<long int>::iterator it;
	
	
	/*
	for (it = aSet.begin(); it != aSet.end(); it++)
	{
		long int product, a = A[*it], b = B[*it];
		product = a * b;
		res = res + product;
	}
	*/
	cout<<res;
	return 0;
}
