#include<iostream>
using namespace std;

bool zerosubsum(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==0)
                return true;
        }
    }
    return false;
}

int main()
{
    int arr[]={1,4,13,-4,-10,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<zerosubsum(arr,n);

    return 0;
}