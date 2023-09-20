#include<bits/stdc++.h>
using namespace std;

// O(2^n) time
int count_ways(int coins[],int n,int sum)
{
    if(sum==0)
        return 1;
    if(sum<0)
        return 0;
    if(n==0)
        return 0;
    
    return count_ways(coins,n,sum-coins[n-1]) + count_ways(coins,n-1,sum);
}

int main()
{
    int coins[]={2,5,3,6};
    int n=sizeof(coins)/sizeof(coins[0]);
    int sum=10;

    cout<<count_ways(coins,n,sum);

    return 0;
}