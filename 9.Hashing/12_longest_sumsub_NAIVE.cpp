#include<iostream>
using namespace std;

int longest_sum(int arr[],int n,int sum)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=0;
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==sum)
            {
                curr=j-i+1;
                res=max(res,curr);
            }
        }
    }
    return res;
}

int main()
{
    int arr[]={3,1,0,1,8,2,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=5;

    cout<<longest_sum(arr,n,sum);

    return 0;
}