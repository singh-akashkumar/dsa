#include<iostream>
using namespace std;

int find_largest(int arr[],int n)
{
    int ans=0;
    for(int i=1;i<n;i++)
        if(arr[ans]<arr[i])
            ans=i;
    return ans;
}

int main()
{
    int arr[]={120,34,56,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    int largest=find_largest(arr,n);

    cout<<"The index of the largest element is: "<<largest;

    return 0;
}