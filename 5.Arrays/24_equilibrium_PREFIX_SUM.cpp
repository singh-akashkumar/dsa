#include<iostream>
using namespace std;

//O(n) TIME AND O(n) AUX SPACE
// int prefix_sum[10000];

// void presum(int arr[],int n)
// {
//     prefix_sum[0]=arr[0];
//     for(int i=1;i<n;i++)
//         prefix_sum[i]=prefix_sum[i-1]+arr[i];
// }

// int equi(int arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(i==0)
//             if(prefix_sum[n-1]-prefix_sum[i]==0)
//                 return true;
//         if(i==n-1)
//             if(prefix_sum[n-2]==0)
//                 return true;
        
//         if(i!=0 && i!=n-1)
//             if(prefix_sum[i-1]==prefix_sum[n-1]-prefix_sum[i])
//                 return true;
//     }
//     return false;
// }

//O(n) TIME AND O(1) AUX SPACE
bool equi(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    
    int left_sum=0;
    for(int i=0;i<n;i++)
    {
        if(left_sum==sum-arr[i])
            return true;
        left_sum+=arr[i];
        sum-=arr[i];
    }
    return false;
}

int main()
{
    int arr[]={2,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<equi(arr,n);

    return 0;
}