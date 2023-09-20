#include<bits/stdc++.h>
using namespace std;

// theta(n*val) time
int min_coins(int coins[],int n,int val)
{
    int dp[val+1];  // dp[i] = min coins required to get value i
    fill(dp,dp+val+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<val+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j]<=i)
            {
                int curr=dp[i-coins[j]];
                if(curr!=INT_MAX)
                    dp[i]=min(dp[i],1+curr);
            }
        }
    }

    return dp[val];
}

int main()
{
    int coins[]={10,2};
    int n=sizeof(coins)/sizeof(coins[0]);
    int val=20;

    cout<<min_coins(coins,n,val);

    return 0;
}