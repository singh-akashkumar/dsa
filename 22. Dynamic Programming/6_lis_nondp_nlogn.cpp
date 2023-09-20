#include<bits/stdc++.h>
using namespace std;

int ceil_index(int tail[],int l,int r,int x)
{
    while(r>l)
    {
        int m=l + (r-l)/2;

        if(tail[m]>=x)
            r=m;
        else
            l=m+1;
    }
    return r;
}

int lis(int arr[],int n)
{
    int tail[n];
    tail[0]=arr[0];
    int len=1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]>tail[len-1])
        {
            tail[len]=arr[i];
            len++;
        }
        else
        {
            int c=ceil_index(tail,0,len-1,arr[i]);
            tail[c]=arr[i];
        }
    }
    return len;
}

int main()
{
    int arr[]={4,10,6,5,8,11,2,20};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<lis(arr,n);

    return 0;
}