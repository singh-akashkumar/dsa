#include<iostream>
using namespace std;

void move_zero(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i+1;j<n;j++)
                if(arr[j]!=0)
                    swap(arr[i],arr[j]);
        }
    }
}

int main()
{
    int arr[]={0,0,0,10,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    move_zero(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}