#include<iostream>
using namespace std;

int search(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
        if(arr[i]==x)
            return i;
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int x;
    cout<<"Enter the element to be searched:";
    cin>>x;

    int index=search(arr,n,x);
    cout<<index;

    return 0;
}