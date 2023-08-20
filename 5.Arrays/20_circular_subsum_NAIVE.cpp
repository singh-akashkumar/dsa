#include<iostream>
using namespace std;

int circ_subsum(int arr[],int n)
{
    int res=arr[0];

    for(int i=0;i<n;i++)
    {
        int curr_max=arr[i];
        int curr_sum=arr[i];

        for(int j=1;j<n;j++)
        {
            int index=(i+j)%n;
            curr_sum=curr_sum+arr[index];
            curr_max=max(curr_max,curr_sum);
        }
        res=max(res,curr_max);
    }
    return res;
}

int main()
{
    int arr[]={10,5,-5};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<circ_subsum(arr,n);

    return 0;
}