#include<bits/stdc++.h>
using namespace std;

int count_bst(int n)
{
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<n+1;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
            dp[i]+=dp[j]*dp[i-j-1];
    }
    return dp[n];
}

int main()
{
    int n=5;

    cout<<count_bst(n);

    return 0;
}