#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[],int n)
{
    if(n==1)
        return arr[0];
    
    int prev_prev=arr[0];
    int prev=max(arr[0],arr[1]);

    int res=prev;
    for(int i=2;i<n;i++)
    {
        res=max(prev,prev_prev+arr[i]);
        prev_prev=prev;
        prev=res;
    }
    return res;
}

int main()
{
    int arr[]={10,5,15,20,2,30};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_sum(arr,n);

    return 0;
}