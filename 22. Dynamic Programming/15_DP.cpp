#include<bits/stdc++.h>
using namespace std;

// theta(n * sum) time and aux space
int count_subsets(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    dp[0][0]=1;
    for(int i=1;i<sum+1;i++)
        dp[0][i]=0;
    for(int i=1;i<n+1;i++)
        dp[i][0]=1;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(j<arr[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
        }
    }
    
    return dp[n][sum];
}

int main()
{
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=4;

    cout<<count_subsets(arr,n,sum);

    return 0;
}