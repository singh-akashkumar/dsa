#include<iostream>
using namespace std;

// time = O((n-k)*k) - Quadratic
int max_sum(int arr[],int k,int n)
{
    int res=INT32_MIN;
    for(int i=0;i+k-1<n;i++)
    {
        int curr_sum=0;
        for(int j=0;j<k;j++)
        {
            curr_sum=curr_sum+arr[i+j];
        }
        res=max(res,curr_sum);
    }
    return res;
}

int main()
{
    int arr[]={1,8,30,-5,20,70};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<max_sum(arr,k,n);
}