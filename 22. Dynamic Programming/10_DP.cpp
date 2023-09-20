#include<bits/stdc++.h>
using namespace std;

// theta(n*cap) time - not polynomial, it is pseudo polynomial
// np hard problem
int knapsack(int vals[],int wts[],int cap,int n)
{
    int dp[n+1][cap+1];
    //dp[i][j] = max value that we can collect with first i items and knapsack capacity j

    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=0;i<=cap;i++)
        dp[0][i]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cap;j++)
        {
            if(wts[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],vals[i-1]+dp[i-1][j-wts[i-1]]);
        }
    }
    return dp[n][cap];
}

int main()
{
    int vals[]={10,40,30,50};
    int wts[]={5,4,6,3};
    int n=sizeof(vals)/sizeof(vals[0]);
    int cap=10;

    cout<<knapsack(vals,wts,cap,n);

    return 0;
}