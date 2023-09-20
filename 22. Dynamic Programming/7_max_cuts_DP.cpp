#include<bits/stdc++.h>
using namespace std;

// theta(n) time and aux space
int maxcuts(int rope,int a,int b,int c)
{
    int dp[rope+1];
    dp[0]=0;

    for(int i=1;i<rope+1;i++)
    {
        dp[i]=-1;
        if(i-a>=0)   dp[i]=max(dp[i],dp[i-a]);
        if(i-b>=0)   dp[i]=max(dp[i],dp[i-b]);
        if(i-c>=0)   dp[i]=max(dp[i],dp[i-c]);

        if(dp[i]!=-1)
            dp[i]++;
    }

    return dp[rope];
}

int main()
{
    int rope=5;
    int a=2,b=4,c=2;

    cout<<maxcuts(rope,a,b,c);

    return 0;
}