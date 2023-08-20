#include<iostream>
using namespace std;

int insert(int arr[],int size,int n,int x,int pos)
{
    if(n==size)
        return n;
    
    int index=pos-1;    //index at which x is to be inserted

    for(int i=n-1;i>=index;i--)
        arr[i+1]=arr[i];
    
    arr[index]=x;

    return (n+1);
}

int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;

    int n;
    cout<<"Enter the number of elements to be initialized:";
    cin>>n;

    int arr[size];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int x;
    cout<<"Enter the element to be inserted:";
    cin>>x;

    int pos;
    cout<<"Enter the position of insertion:";
    cin>>pos;

    n=insert(arr,size,n,x,pos);

    cout<<"The revised array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";

    return 0;
}