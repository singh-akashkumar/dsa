#include<bits/stdc++.h>
using namespace std;

// theta(2^n) time
int count_subsets(int arr[],int n,int sum)
{
    if(n==0)
        return (sum==0)?1:0;
    
    return count_subsets(arr,n-1,sum-arr[n-1])+count_subsets(arr,n-1,sum);
}

int main()
{
    int arr[]={10,5,2,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=15;

    cout<<count_subsets(arr,n,sum);

    return 0;
}