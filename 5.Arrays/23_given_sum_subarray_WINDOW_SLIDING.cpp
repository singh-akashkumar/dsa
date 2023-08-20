#include<iostream>
using namespace std;

bool subsum(int arr[],int n,int sum)
{
    int curr_sum=arr[0],s=0;    //s means start index
    for(int e=1;e<=n;e++)       //e means end index
    {
        while(curr_sum>sum && s<e-1)
        {
            curr_sum=curr_sum-arr[s];
            s++;
        }
        if(curr_sum==sum)
            return true;
        if(e<n)
            curr_sum=curr_sum+arr[e];
    }
    return false;
}

int main()
{
    int arr[]={43,3,10,20,21};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=33;

    cout<<subsum(arr,n,sum);

    return 0;
}