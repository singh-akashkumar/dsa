#include<iostream>
using namespace std;

// theta(n^2) time
int rain(int arr[],int n)
{
    int res=0;

    for(int i=1;i<n-1;i++)  // i from 1 to (n-2) bcz corner blocks cannot hold any water over them
    {
        int lmax=arr[i];
        for(int j=0;j<i;j++)
            lmax=max(lmax,arr[j]);
        
        int rmax=arr[i];
        for(int j=i+1;j<n;j++)
            rmax=max(rmax,arr[j]);
        
        res=res+(min(lmax,rmax)-arr[i]);
    }
    return res;
}

int main()
{
    int arr[]={4,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<rain(arr,n);

    return 0;
}