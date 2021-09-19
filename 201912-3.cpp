#include <iostream>
#include <string> 
#include <map> 
using namespace std;

typedef map<string, int> mti;

mti work(string str)
{
	//find inital digit and spilt +
	for (int i = 0; i < str.size(); i++)
	{
		int k = 0;
		while(k < str.size() && isdigit(str[k]))
			k++;
		int count = 0;
		if (k > 0)
			
	}
}

int main()
{
	int n;
	cin>>n;
	
	while(n--)
	{
		string str;
		cin>>str;
		size_t p = str.find("=");
		string a = str.substr(0, p), b = str.substr(p+1);
		auto al = work(a), br = work(b);
		if (al == br)
			cout<<"Y\n";
		else
			cout<<"N\n";
	}
	
	return 0;	
}
