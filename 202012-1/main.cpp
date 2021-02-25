#include <iostream>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//ostream& nullstream
//ostream& // = std::cout;


int main(int argc, char** argv) {
	
	int size;
	cin>>size;
	if (size < 2 || size > (100000))
		return 1;
	
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		int wi = 0, scroe = 0;
		
		cin>>wi>>scroe;
		
		int temp = wi*scroe;
		//<<"------------"<<endl;
		//<<temp<<endl;
		//<<"------------"<<endl;

		res = res + temp;
	}
	
	if (res > 0)  
		cout<<res<<endl;
	else
		cout<<0<<endl;
	return 0;
}

