#include<iostream>
using namespace std;

void move_zero(int arr[],int n)
{
    int count =0;   //count of non-zero elements
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[count]);
            count++;
        }
    }
}

int main()
{
    int arr[]={8,5,0,0,10,20,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    move_zero(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}