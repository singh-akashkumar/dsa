#include<iostream>
using namespace std;

// O(n) time and O(n) space
int remove_duplicates(int arr[],int n)
{
    int temp[n];
    temp[0]=arr[0];
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(temp[res-1]!=arr[i])
        {
            temp[res]=arr[i];
            res++;
        }
    }

    for(int i=0;i<n;i++)
        arr[i]=temp[i];
    
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
    
    int res=remove_duplicates(arr,n);
    cout<<"The array after removal of duplicates is: ";
    for(int i=0;i<res;i++)
        cout<<arr[i]<<"  ";
    
    return 0;
}