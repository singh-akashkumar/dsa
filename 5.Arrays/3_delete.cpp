#include<iostream>
using namespace std;

int del(int arr[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==x)
            break;
    
    if(i==n)
        return n;
    
    for(int j=i;j<n-1;j++)
        arr[j]=arr[j+1];
    
    return n-1;
}

int main()
{
    int arr[]={12,34,56,78,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=12;

    n=del(arr,n,x);
    
    cout<<"The modified array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    
    return 0;
}