#include<iostream>
using namespace std;

int countSubsets(int arr[],int n,int sum)
{
    if(n==0)
        return (sum==0)?1:0;
    return countSubsets(arr,n-1,sum)+countSubsets(arr,n-1,sum-arr[n-1]);
}

int main()
{
    int arr[]={10,20,15,37,27};
    int sum=37;
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<countSubsets(arr,n,sum);

    return 0;
}