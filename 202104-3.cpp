#include <iostream>
#include <string>

using namespace std;

const int maxN = 10010;
struct IP{
	int status; // 0 - noalloacte, 1 - wait for alloacte
				// 2 - occpuied, 3 - expired
	string owner;  // 0 do not have owner
	int expireTime; //only for 1, 2. 0 if donot have
} ipPool[maxN];

int N, Tdef, Tmax, Tmin;
string H;

void maintainIPpool(int t)
{
	for(int i = 1; i <= N; i++)
	{
		if (ipPool[i].expireTime > 0 && ipPool[i].expireTime <= t)
		{
			if (ipPool[i].status == 1)
			{
				ipPool[i].status = 0;
				ipPool[i].owner = "";
				ipPool[i].expireTime = 0;
			}
			else
			{
				ipPool[i].status = 3;
				ipPool[i].expireTime = 0;
			}
			
		}
	}
}

void calTime(int ip, int expiredTime, int t)
{
	if (expiredTime == 0)
	{
		ipPool[ip].expireTime = t + Tdef;
	}
	else
	{
		if (expiredTime - t > Tmax)
		{
			ipPool[ip].expireTime = t + Tmax;
		}
		else if (expiredTime - t < Tmin)
		{
			ipPool[ip].expireTime = t + Tmin;
		}
		else
		{
			ipPool[ip].expireTime = expiredTime;
		}
	}
} 

int main()
{
	cin>>N>>Tdef>>Tmax>>Tmin>>H;
	
	//start with 1
	for (int i = 1; i <= N; i++)
	{
		ipPool[i].status = 0;
		ipPool[i].owner = "";
		ipPool[i].expireTime = 0;
	}
	
	int n;
	cin>>n;
	while(n--)
	{
		int t;
		cin>>t;
		string sender, reciver, type;
		int ip, expiredTime;
		cin>>sender>>reciver>>type>>ip>>expiredTime;
		
		maintainIPpool(t);
		
		if (reciver != H && reciver != "*")
		{
			if (type != "REQ")
				continue;
		}
			
		if (type != "DIS" && type != "REQ")
			continue;
		
		if (reciver == "*" && type != "DIS")
			continue;
			
		if (reciver == H && type == "DIS")
			continue;
		
		//process Discover 	
		if (type == "DIS")
		{
			int selectIP = -1;
			//step 1
			for (int i = 1; i <= N; i++)
			{
				if (sender == ipPool[i].owner)
				{
					selectIP = i;
					break;
				}
			}
			//search in 0
			if (selectIP == -1)
			{
				for (int i = 1; i <= N; i++)
				{
					if (ipPool[i].status == 0)
					{
						selectIP = i;
						break;
					}
				}
			}
			
			//search in 3
			if (selectIP == -1)
			{
				for (int i = 1; i <= N; i++)
				{
					if (ipPool[i].status == 3)
					{
						selectIP = i;
						break;
					}
				}
			}
			
			//no avaluable
			if (selectIP == -1)
			{
				continue;
			}
			
			//step 2
			ipPool[selectIP].status = 1;
			ipPool[selectIP].owner = sender;
			
			//step 3
			calTime(selectIP, expiredTime, t);
			
			//step 4
			cout<<H<<" "<<sender<<" OFR "<<selectIP<<" "<<ipPool[selectIP].expireTime<<endl;
		}
		
		//Request 
		if (type == "REQ")
		{
			//step 1;
			if (reciver != H)
			{
				for (int i = 1; i <= N; i++)
				{
					if (ipPool[i].status == 1 && ipPool[i].owner == sender) 
					{
						ipPool[i].status = 0;
						ipPool[i].owner = "";
						ipPool[i].expireTime = 0;
						
					}
				}
				continue;
			}
			
			//step 2
			if (ip > N)
			{
				cout<<H<<" "<<sender<<" NAK "<<ip<<" "<<0<<endl;
				continue;
			}
			
			if (ipPool[ip].owner != sender)
			{
				cout<<H<<" "<<sender<<" NAK "<<ip<<" "<<0<<endl;
				continue;
			}
			
			//step 3
			ipPool[ip].status = 2;
			ipPool[ip].owner = sender;
			//step 4
			calTime(ip, expiredTime, t);
			
			//step 5
			cout<<H<<" "<<sender<<" ACK "<<ip<<" "<<ipPool[ip].expireTime<<endl;
		}
	}
	
	return 0; 
} 
