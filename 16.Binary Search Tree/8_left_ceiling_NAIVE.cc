#include<bits/stdc++.h>
using namespace std;

// O(n^2) time
void left_ceiling(int arr[],int n)
{
    cout<<-1<<"  ";
    for(int i=1;i<n;i++)
    {
        int diff=INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
                diff=min(diff,arr[j]-arr[i]);
        }
        if(diff==INT_MAX)
            cout<<-1<<"  ";
        else
            cout<<diff+arr[i]<<"  ";
    }
}

int main()
{
    int arr[]={96,34,56,101,89,73,55};
    int n=sizeof(arr)/sizeof(arr[0]);

    left_ceiling(arr,n);

    return 0;
}