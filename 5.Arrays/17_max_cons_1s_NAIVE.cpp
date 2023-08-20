#include<iostream>
using namespace std;

// O(n^2) time - Worst case when all array elements are 1
int ones(int arr[],int n)
{
    int res=0;

    for(int i=0;i<n;i++)
    {
        int curr=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==1)
                curr++;
            else
                break;
        }
        res=max(res,curr);
    }
    return res;
}

int main()
{
    int arr[]={0,0,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<ones(arr,n);

    return 0;
}