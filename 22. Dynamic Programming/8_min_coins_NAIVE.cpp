#include<bits/stdc++.h>
using namespace std;

int min_coins(int coins[],int n,int val)
{
    if(val==0)
        return 0;
    
    int res=INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(coins[i]<=val)
        {
            int curr=min_coins(coins,n,val-coins[i]);
            
            if(curr!=INT_MAX)
                res=min(res,curr+1);
        }
    }
    return res;

}

int main()
{
    int coins[]={10,2};
    int n=sizeof(coins)/sizeof(coins[0]);
    int val=20;

    cout<<min_coins(coins,n,val);

    return 0;
}