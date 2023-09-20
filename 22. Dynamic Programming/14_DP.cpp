#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[],int n)
{
    int dp[n];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++)
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    
    return dp[n-1];
}

int main()
{
    int arr[]={8};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_sum(arr,n);

    return 0;
}