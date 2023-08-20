#include<iostream>
using namespace std;

// Time=Theta(n*d) and Aux Space=Theta(1)

void left_rotate(int arr[],int n,int d)
{
    for(int i=0;i<d;i++)
    {
        int temp=arr[0];
        for(int j=0;j<n-1;j++)
            arr[j]=arr[j+1];
        arr[n-1]=temp;
    }
}

int main()
{
    int arr[]={10,5,13,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int d=8;

    left_rotate(arr,n,d);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}