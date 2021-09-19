#include <iostream>
#include <cstring>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<char> op;

void eval()
{
	int b = num.top(); num.pop();
	int a = num.top(); num.pop();
	char c = op.top(); op.pop();
	int x;
	if (c == '+')
		x = a + b;
	else if (c == '-')
		x = a - b;
	else if (c == 'x')
		x = a * b;
	else
	{
		if (a * b >= 0) x = a/b;
		else
		{
			if (a % b == 0)
				x = a/b;
			else
				x = a/b -1;
		}
			
	}
	num.push(x);
}

int main()
{
	int n;
	cin>>n;
	
	unordered_map<char, int> pr;
	pr['+'] = pr['-'] = 1;
	pr['x'] = pr['/'] = 2;
	
	
	
	while(n--)
	{
		string s;
		cin>>s;
		num = stack<int>();
		op = stack<char>(); 
		
		for(auto c : s)
		{
			if (c >= '0' && c <= '9')
				num.push(c - '0');
			else
			{
				while (op.size() && pr[op.top()] >= pr[c])
					eval();
					
				op.push(c);
			}
		} 
		while (op.size())
			eval();
		if (num.top() == 24)
			cout<<"Yes"<<endl;
		else
			cout<<"No\n";
	}
	return 0; 
} 
