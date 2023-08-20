#include<iostream>
using namespace std;

int remDup(int arr[],int n)
{
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(arr[res-1]!=arr[i])
        {
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    int arr[n];

    cout<<"Enter the array elements:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int res=remDup(arr,n);
    cout<<"The array after removal of duplicates is: ";
    for(int i=0;i<res;i++)
        cout<<arr[i]<<"  ";
    
    return 0;
}