#include<iostream>
using namespace std;

int profit(int arr[],int n)
{
    int profit=0;

    for(int i=0;i<n-1;i++)
        if(arr[i]<arr[i+1])
            profit=profit+(arr[i+1]-arr[i]);
    
    return profit;
}

int main()
{
    int arr[]={1,5,3,8,12};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<profit(arr,n);

    return 0;
}