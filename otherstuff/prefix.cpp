#include <iostream>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int maxsumofSubarray(vector<int>& arr) 
{
        // write code here
        int res = 12;
        if (arr.size() < 1)
            return 0;
        if (arr.size() == 1)
            return arr.front();
        
        vector<int> prefix(arr.size(), 0);
        int max = 0, sum = 0;
        
        
        for(int i = 0; i < arr.size(); i++)
        {
            if (prefix[i - 1] > 0)
                prefix[i] = arr[i] + prefix[i - 1];
            else
                prefix[i] = arr[i];
            
            /*
            sum = arr[i] + sum;
            
            if (sum > 0)
                prefix[i] = sum;
             else 
             {
                 sum = arr[i];
                 prefix[i] = arr[i];
                }
                */

            cout<<i<<": "<<prefix[i]<<endl; 
            if (max < prefix[i])
                max = prefix[i];
        }
        /*
        for(int i = 1; i < arr.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                int s = prefix[i] - prefix[j];
                if (s > max)
                    max = s;
            }
        }
        */
        return max;
}

int main(int argc, char** argv) {
	
	int a[] = {1, -2, 3, 5, -2, 6, -1};
	vector<int> arr(a, a + sizeof(a)/ sizeof(int));
	
	cout<<"res: "<<maxsumofSubarray(arr)<<endl;
	
	return 0;
}
