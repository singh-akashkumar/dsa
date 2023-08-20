#include<iostream>
using namespace std;

bool arrsorted(int arr[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i]>arr[j])
            {
                return false;
            }
    return true;
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
    
    bool res=arrsorted(arr,n);
    cout<<res;

    return 0;
}