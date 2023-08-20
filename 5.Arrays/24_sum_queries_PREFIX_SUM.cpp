#include<iostream>
using namespace std;

int prefix_sum[10000];

void presum(int arr[],int n)
{
    prefix_sum[0]=arr[0];
    for(int i=1;i<n;i++)
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
}

int getsum(int l,int r)
{
    if(l!=0)
        return prefix_sum[r]-prefix_sum[l-1];
    else
        return prefix_sum[r];
}

int main()
{
    int arr[]={2,8,3,9,6,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    presum(arr,n);

    cout<<getsum(0,3)<<endl;
    cout<<getsum(2,5)<<endl;
    cout<<getsum(3,6)<<endl;
    cout<<getsum(1,4)<<endl;

    return 0;
}