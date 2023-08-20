#include<iostream>
using namespace std;

int max_diff(int arr[],int n)
{
    int ans=arr[1]-arr[0];
    int minval=arr[0];

    for(int j=1;j<n;j++)
    {
        ans=max(ans,arr[j]-minval);
        minval=min(minval,arr[j]);
    }
    return ans;
}

int main()
{
    int arr[]={7,9,5,6,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_diff(arr,n);

    return 0;
}