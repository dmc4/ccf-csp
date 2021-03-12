//
//  main.cpp
//  playground
//
//  Created by Changze Huang on 2021/3/11.
//

#include <iostream>

int fab(int in)
{
    //if (in == 2)
        //return 2;
    if (in == 1)
        return 1;
    return in + fab(in - 1);
}

int resutList[1001];

int fab_dp_cache(int in)
{
    int res = 0;
    
    if (resutList[in] != -1 && in < 1001)
        return resutList[in];
    
    if (in == 0)
        return 0;
    for (int i = 1; i <= in; i++)
    {
        res = res + i;
    }
    
    
    resutList[in] = res;
    return res;
}


int times(int input)
{
    if (input == 0)
        return 1;
    
    int res = 1;
    for (int i = 1; i <= input; i++)
    {
        res = res * i;
    }
    
    return res;
}

//nCr = (n - 1)C(r - 1) + (n - 1)C(r)
int combination_dp(int n, int r)
{
    if (r == 0)
        return 1;
    if (r == 1)
        return n;
    if (r == n)
        return n;
    
    return combination_dp(n - 1, r - 1) + combination_dp(n - 1, r);
}


int combination(int n, int r)
{
    
    if (r == 0)
        return 1;
    
    if (r == 1)
        return n;
    
    if (n == r)
        return 1;
    
    int top = times(n);
    int bottom = times(n - r) * times(r);
    
    return top/bottom;
}

int permutations(int n, int r)
{
    int top = times(n);
    int bottom = times(n - r);
    
    return top/bottom;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    for (int i = 0; i < 1001; i++)
    {
        resutList[i] = -1;
    }
    int res = fab_dp_cache(5);

    std::cout<<res<<std::endl;
    std::cout << "Hello, World!\n";


    return 0;
}
