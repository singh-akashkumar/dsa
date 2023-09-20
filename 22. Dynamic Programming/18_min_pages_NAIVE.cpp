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
    if(k==1)
        return sum(arr,0,n-1);

    if(n==1)
        return arr[0];

    int res=INT_MAX;
    for(int i=1;i<n;i++)
        res=min(res, max(min_pages(arr,i,k-1),sum(arr,i,n-1)));
    
    return res;
}

int main()
{
    int arr[]={10,20,30,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=1;

    cout<<min_pages(arr,n,k);

    return 0;
}