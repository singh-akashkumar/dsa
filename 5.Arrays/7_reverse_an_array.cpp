#include<iostream>
using namespace std;

// void reverse(int arr[],int n)
// {   THIS SOLUTION TAKES THETA(n) AUXILIARY SPACE
//     int temp[n];
//     int j=n-1;
//     for(int i=0;i<n;i++)
//     {
//         temp[j]=arr[i];
//         j--;
//     }
//     for(int i=0;i<n;i++)
//         arr[i]=temp[i];
// }

void reverse(int arr[],int n)
{
    int low=0,high=n-1;

    while(low<high)
    {
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;

        low++;
        high--;
    }
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
    
    reverse(arr,n);
    cout<<"The reversed array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";

    return 0;
}