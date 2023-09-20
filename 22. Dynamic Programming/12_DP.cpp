#include<bits/stdc++.h>
using namespace std;

int max_trials(int e,int f)
{
    int dp[f+1][e+1];

    for(int i=1;i<e+1;i++)
    {
        dp[0][i]=0;
        dp[1][i]=1;
    }
    for(int i=1;i<f+1;i++)
        dp[i][1]=i;
    
    for(int i=2;i<f+1;i++)
    {
        for(int j=2;j<e+1;j++)
        {
            dp[i][j]=INT_MAX;
            for(int x=1;x<=i;x++)
                dp[i][j]=min(dp[i][j], 1 + max(dp[x-1][j-1],dp[i-x][j]));
        }
    }
    return dp[f][e];
}

int main()
{
    int e=1,f=10;

    cout<<max_trials(e,f);

    return 0;
}