#include<bits/stdc++.h>
using namespace std;

// theta(n^2) time and aux space
int soln(int arr[],int n)
{
    int dp[n][n];

    for(int i=0;i<n-1;i++)
        dp[i][i+1]=max(arr[i],arr[i+1]);
    
    for(int gap=3;gap<n;gap=gap+2)
    {
        for(int i=0;i+gap<n;i++)
        {
            int j=i+gap;
            dp[i][j]=max(arr[i]+min(dp[i+1][j-1],dp[i+2][j]),
                        arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }

    return dp[0][n-1];
}

int main()
{
    int arr[]={20,5,4,6,8,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<soln(arr,n);

    return 0;
}