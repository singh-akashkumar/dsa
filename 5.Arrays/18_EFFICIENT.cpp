#include<iostream>
using namespace std;

int subsum(int arr[],int n)
{
    int res=arr[0];
    int max_ending=arr[0];

    for(int i=1;i<n;i++)
    {
        max_ending=max(max_ending+arr[i],arr[i]);
        res=max(res,max_ending);
    }
    return res;
}

int main()
{
    int arr[]={2,3,-8,7,-1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<subsum(arr,n);

    return 0;
}