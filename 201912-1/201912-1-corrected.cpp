/*
提交编号	用户名	姓名	试题名称	提交时间	代码长度	编程语言	评测结果	得分	时间使用	空间使用
2355041	<田鹏>	<田鹏>	报数	03-08 06:00	1.177KB	C++	正确	100	0ms	2.882MB
*/


//string
#include <iostream>
#include <string>
#include <sstream>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool has7(int i)
{
	stringstream ss;
	ss<<i;
	string s;
	ss>>s;
	
	//string::iterator it;
	//c++ library second book p680
	//cout<<s<<endl;
	string::size_type idx = s.find("7");
	if (idx == string::npos )
		return false;
	
	return true;
}

bool has7v2(int i)
{
	while(i)
	{
		if (i % 10 == 7)
			return true;
		i = i / 10;
	}
	return false;
}


int main(int argc, char** argv) {
	int n;
	
	cin>>n;
	int i = 1, t = 0;
	
	//cout<<"49%7: "<<49%7<<endl<<"17%10"<<17%10;
	//if (n > 666)
	//	return 1;
	
	int player[5] = {0}; // for a b c d
	/* 
	for (int i = 1, t = 1; t <= n; i++)
	{
		if (i%7 == 0 || has7(i))
			player[i%4]++;
		else t++;
	}
	*/
	 
	while (true) // !!!  (t < n) 	四个人报完数后，才检查，这时可能已经超出了 n
	{
		// cout<<i<<endl;
		for (int j = 0; j < 4; j++)
		{
			if (i % 7 == 0 || has7(i))
			{
				player[j]++;
				//t--;
			}
			else 
				t++;

			if ((t >= n)) {	// !!! 随时检查是否达到 n
				goto end;
			}

			i++;
			
			//t++;
		}
	}
	// cout<<"i: "<<i<<" t: "<<t<<endl;

end:		
	for (int j = 0; j < 4; j++)
	{
		cout<<player[j]<<endl;
	}
	return 0;
}

