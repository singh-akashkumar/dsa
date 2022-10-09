#include<bits/stdc++.h>
using namespace std;

int subseq(int arr[],int n)
{
    sort(arr,arr+n);
    int res=1,curr=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1]+1)
            curr++;
        else if(arr[i]!=arr[i-1])       // to handle eg: {2,3,3,4} len of subseq here is 3
        {
            res=max(res,curr);
            curr=1;
        }
    }
    return max(res,curr);
}

int main()
{
    int arr[]={2,3,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<subseq(arr,n);

    return 0;
}