#include<iostream>
using namespace std;

int ones(int arr[],int n)
{
    int res=0,curr=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
            curr=0;
        else if(arr[i]==1)
        {
            curr++;
            res=max(res,curr);
        }
    }
    return res;
}

int main()
{
    int arr[]={0,0,1,0,1,1,0,1,1,1,1,0,0,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<ones(arr,n);

    return 0;
}