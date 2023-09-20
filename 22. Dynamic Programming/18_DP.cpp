#include<bits/stdc++.h>
using namespace std;

int sum(int arr[],int x,int y)
{
    int sum=0;
        for(int i=x;i<=y;i++)
            sum=sum+arr[i];

    return sum;
}

int min_pages(int arr[],int n,int k)
{
    int dp[k+1][n+1];
    for(int i=1;i<n+1;i++)
        dp[1][i]=sum(arr,0,i-1);
    
    for(int i=1;i<k+1;i++)
        dp[i][1]=arr[0];
    
    for(int i=2;i<k+1;i++)
    {
        for(int j=2;j<n+1;j++)
        {
            int res=INT_MAX;
            for(int p=1;p<j;p++)
                res=min(res, max(dp[i-1][p],sum(arr,p,j-1)));
            
            dp[i][j]=res;
        }
    }
    return dp[k][n];
}

int main()
{
    int arr[]={10,5,30,1,2,5,10,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;

    cout<<min_pages(arr,n,k);

    return 0;
}