//algorithm design manual



#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAX_N = 500 + 2;
const int MAX_S = 10000 + 2; 
const int MAX_K = 5 + 2;

struct Node {
	int func;
	vector<int> in;
	vector<int> out;
}; 

Node nodes[MAX_N]; 
vector<int> edges[MAX_N];
int fan_in[MAX_N];

/* 
class GRAPH{
	private:
		int m, n;
		int input[MAX_N]; 
		GRAPH(int m, int n);
		
	public:
	
};

GRAPH::GRAPH(int m, int n)
{
	
}
*/

bool topological_sorting(int n)
{
	int count = 0;
	queue<int> q; 
	
	for(int i = 1; i <= n; ++i)
	{
		if (!fan_in[i])
		{
			q.push(i);
		}
	}
	
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		count++;
		
		int size = edges[v].size();
		for (int i = 0; i < size; i++)
		{
			int u = edges[v][i];
			if (!(--fan_in[u]))
			{
				q.push(u);
			}
		}
	}

	return count==n; 
}

//to do dfs 
//read algorithm
int visit[MAX_N] = {0}; // 0 undiscovered, 1 discovered, 2 processed
int parent[MAX_N] = {0};
int visit_in[MAX_N] = {0}; //mark node visit in which i?
//loop 
bool dfs_find(int n)
{
	//queue<int> q;		//bfs
	stack<int> q;		//dfs
	//q.push(1);
	
	for (int i = 1; i <= n; ++i)
	{
		//cout<<i<<": "<<visit[i]<<endl;
		if (visit[i] == 0)
		{
			q.push(i);
			//cout<<"Push: "<<i<<endl;
		}
			
		while (!q.empty())
		{
			set<int> sset;
			sset.clear();
			//int pro = q.front();
			int pro = q.top();
			q.pop();
			//cout<<pro<<" ";
			if (visit[pro] != 0 && visit_in[pro] == i)
			{
				//cout<<"return false; in "<<pro<<endl;
				return false;
			}
			visit[pro] = 1;
			vector<int>:: iterator it;
			for (it = edges[pro].begin(); it != edges[pro].end(); it++)
			{
				if (sset.count(*it) == 0)
				{
					sset.insert(*it);
					q.push(*it);
				}
				
			}
			
			visit[pro] = 2;
			visit_in[pro] = i;
		}
		//cout<<endl;

	}
	
	return true;
}

//recursion
bool dfs_find_re(int start, int i)
{
	if (visit[start] != 0 && visit_in[start] == i)
		return false;
	
	if (visit[start] != 0)
		return true;
	visit[start] = 1;

	bool a = true;
	vector<int>:: iterator it;
	for (it = edges[start].begin(); it != edges[start].end(); it++)
	{
		a = dfs_find_re(*it, i);
	}
	
	
	visit[start] = 2;
	visit_in[start] = i;
	
	return a;
}


//operation
/*
"NOT", 1
"AND", 2
"OR", 3
"XOR", 4
"NAND", 5
"NOR", 6
*/
int input[MAX_S][MAX_N];
int operation(vector<int> q, int opt)
{
	if (opt == 1)
		return !q[0];
		
	int res = q[0];
	
	int size = q.size();
	for (int i = 1;i < size; i++)
	{
		switch(opt)
		{
			case 2:
			case 5:
				res = res & q[i];
				break;
				
			//XOR ^
			case 4:
				res = res ^ q[i];
				break;
				
			//OR
			case 3:
			case 6:
				res = res | q[i];
				break;
		}
	}
	
	switch (opt)
	{
		case 5:
		case 6:
			res = !res;
			break;
	}
	
	return res;
}
 
//dfs use nodes.out
//jth time of input, num: number of node
int calVal[MAX_N + 1]; 
int dfs_use_node(int j, int num)
{
	vector<int> input_for_node;
	
	if (calVal[num] != -1)
		return calVal[num];
	
	//from in
	vector<int>::iterator it;
	for (it = nodes[num].in.begin(); it != nodes[num].in.end(); it++ )
	{
		input_for_node.push_back(input[j][*it]);
	}
	
	for (it = nodes[num].out.begin(); it != nodes[num].out.end(); it++ )
	{
		input_for_node.push_back(dfs_use_node(j, *it));
	}
	int res = operation(input_for_node, nodes[num].func);
	calVal[num] = res;
	return res;
}
 
//display
void display(int j)
{
	cout<<"Node: "<<j<<endl;
	cout<<"Func "<<nodes[j].func<<endl;
	cout<<"fan-in: "<<fan_in[j]<<endl;
	cout<<"in: ";
			
	vector<int>::iterator it;
			
	for (it = nodes[j].in.begin(); it != nodes[j].in.end(); it++)
			cout<<*it<<" ";
				
				
	cout<<endl<<"out: ";
	for (it = nodes[j].out.begin(); it != nodes[j].out.end(); it++)
		cout<<*it<<" ";
			
	cout<<endl<<"edges: ";
	for (it = edges[j].begin(); it != edges[j].end(); it++)
		cout<<*it<<" ";
				
	cout<<endl<<"---------------"<<endl; 
}

void dfs()
{
	int state[MAX_N] = {0};//unfind find processed 
	int parents[MAX_N] = {0}; 
	//queue<int> tt;		//to bfs 
	stack<int> tt;
	
	tt.push(1);
	state[1] = 1;
	
	while (!tt.empty())
	{
		//int temp = tt.front();
		int temp = tt.top();
		tt.pop();
		vector<int>::iterator it;
		for (it = edges[temp].begin(); it != edges[temp].end(); it++)
			tt.push(*it);
		
		display(temp);
		
		state[temp] = 2;
	}
}


int main(int argc, char** argv) {
	int q, m, n;
	cin>>q;
	
	map<string, int> opt;
	opt.insert(pair<string, int>("NOT", 1));
	opt.insert(pair<string, int>("AND", 2));
	opt.insert(pair<string, int>("OR", 3));
	opt.insert(pair<string, int>("XOR", 4));
	opt.insert(pair<string, int>("NAND", 5));
	opt.insert(pair<string, int>("NOR", 6));
	
	for (int i = 0; i < q; i++)
	{
		cin>>m>>n;
		//init graph
		for (int j = 1; j <=n; ++j)
		{
			edges[j].clear();
			fan_in[j] = 0;
			
			
			visit[j] = 0; // 0 undiscovered, 1 discovered, 2 processed
			//parent[j] = 0;
			visit_in[j] = 0; //mark node visit in which i?

			nodes[j].in.clear();
			nodes[j].out.clear();
		}
		
		//input
		for (int j = 1; j <= n; ++j)
		{
			int k;
			string str;
			cin>>str;
			nodes[j].func = opt[str];
			cin>>k;
			for (int ii = 0; ii < k; ii++)
			{
				char t;
				cin>>t;
				
				int no;
				cin>>no;
				
				
				if ('I' == t)
				{
				 	nodes[j].in.push_back(no);
				}
				else
				{
					edges[no].push_back(j);
					fan_in[j]++;
					
					nodes[j].out.push_back(no);
				}
			}
		}
		
		bool fg = true, mark = false;
		for (int j = 1; j <= n; ++j)	//20 marks
		{
			//display(j);
			fg = dfs_find_re(j, j);
			if (!fg)
			{
				mark = true;
				cout<<"LOOP";
				break;
			}
		}
		
		
		if (mark)
			fg = false;
		
		int S;
		cin>>S;
		for (int j = 0; j < S; j++)
		{
			for (int ii = 1; ii <= m; ii++)
				cin>>input[j][ii];
		}
		
		//bool fg = topological_sorting(n);	//100 marks
		//if (!fg)
		//	cout<<"LOOP";
		
		//bool fg = dfs_find(n);	// zero marks
		//if (!fg)
		//	cout<<"LOOP";	
		
		//if(!fg)
			//return 1;
		
		for (int j = 0; j < S; j++)
		{
			int size, num;
			cin>>size;
			//memset(calVal, -1, sizeof(calVal));
			for(int jj = 1; jj <= n; jj++)
				calVal[jj] = -1;
			
			//jth time of input, num: number of node
			for (int ii = 0; ii < size; ii++)
			{
				cin>>num;
				if (fg) 	//check flag!
					cout<<dfs_use_node(j, num)<<" ";
			}
			
			cout<<endl;
		}

	}
	 
	return 0;
}
