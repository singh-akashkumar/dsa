#include<bits/stdc++.h>
using namespace std;

int min_jumps(int arr[],int n)
{
    if(n==1)
        return 0;
    int res=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]+i>=n-1)
        {
            int sub_res=min_jumps(arr,i+1);
            res=min(res,sub_res+1);
        }
    }
    return res;
}

int main()
{
    int arr[]={4,1,5,3,1,3,2,1,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<min_jumps(arr,n);

    return 0;
}