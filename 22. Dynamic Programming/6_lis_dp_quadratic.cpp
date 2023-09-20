#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n)
{
    int lis[n];
    fill(lis,lis+n,1);

    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(arr[j]<arr[i])
                lis[i]=max(lis[i],lis[j]+1);
    
    int res=lis[0];
    for(int i=1;i<n;i++)
        res=max(res,lis[i]);
    
    return res;
}

int main()
{
    int arr[]={4,10,6,5,8,11,2,20};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<lis(arr,n);

    return 0;
}