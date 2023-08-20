#include<iostream>
using namespace std;

int max_sum(int arr[],int k,int n)
{
    int curr_sum=0;
    for(int i=0;i<k;i++)
    {
        curr_sum+=arr[i];
    }
    int res=curr_sum;
    for(int i=k;i<n;i++)
    {
        curr_sum+=(arr[i]-arr[i-k]);
        res=max(res,curr_sum);
    }
    return res;
}

int main()
{
    int arr[]={1,8,30,-5,20,7};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_sum(arr,k,n);
}