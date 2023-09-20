#include<bits/stdc++.h>
using namespace std;

int min_jumps(int arr[],int n)
{
    int dp[n];
    fill(dp,dp+n,INT_MAX);
    dp[0]=0;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]+j>=i)
                if(dp[j]!=INT_MAX)
                    dp[i]=min(dp[i],dp[j]+1);
        }
    }
    return dp[n-1];
}

int main()
{
    int arr[]={3,4,2,1,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<min_jumps(arr,n);

    return 0;
}