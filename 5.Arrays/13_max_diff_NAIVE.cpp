#include<iostream>
using namespace std;

int max_diff(int arr[],int n)
{
    int ans=arr[1]-arr[0];

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((arr[j]-arr[i])>ans)
                ans=arr[j]-arr[i];
        }
    }
    return ans;
}

int main()
{
    int arr[]={7,9,5,6,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_diff(arr,n);

    return 0;
}