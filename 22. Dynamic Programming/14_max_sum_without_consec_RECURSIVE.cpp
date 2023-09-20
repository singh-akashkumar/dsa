#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[],int n)
{
    if(n==1)
        return arr[0];
    else if(n==2)
        return max(arr[0],arr[1]);
    else
        return max(max_sum(arr,n-1),max_sum(arr,n-2)+arr[n-1]);
}

int main()
{
    int arr[]={10,5,15,20,2,30};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_sum(arr,n);

    return 0;
}