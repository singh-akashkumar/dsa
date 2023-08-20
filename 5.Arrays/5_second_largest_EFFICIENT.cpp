#include<iostream>
using namespace std;

int second_largest(int arr[],int n)
{
    int largest=0,ans=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[largest])
        {
            ans=largest;
            largest=i;
        }
        else if(arr[i]!=arr[largest])
            if(ans==-1 || arr[ans]<arr[i])
                ans=i;
    }
    return ans;
}

int main()
{
    int arr[]={12,34,56,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    int sec=second_largest(arr,n);

    cout<<"The index of the second largest element is: "<<sec;

    return 0;
}