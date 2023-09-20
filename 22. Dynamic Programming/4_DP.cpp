#include<bits/stdc++.h>
using namespace std;

// O(n*sum) time and Aux Space
// O(n*sum) is pseudo polynomial bcz we depend on sum and it might go very high
// Coin Change Prob is np complete or np hard bcz there is no known polynomial soln
int count_ways(int coins[],int n,int sum)
{
    int dp[n+1][sum+1];
    
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    
    for(int j=0;j<=sum;j++)
        dp[0][j]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(coins[i-1]<=j)
                dp[i][j]+=dp[i][j-coins[i-1]];
        }
    }
    return dp[n][sum];
}

int main()
{
    int coins[]={1,2,3};
    int n=sizeof(coins)/sizeof(coins[0]);
    int sum=4;

    cout<<count_ways(coins,n,sum);

    return 0;
}