#include<iostream>
using namespace std;

int normal_max(int arr[],int n)
{
    int res=arr[0],maxend=arr[0];

    for(int i=1;i<n;i++)
    {
        maxend=max(maxend+arr[i] , arr[i]);
        res=max(res,maxend);
    }
    return res;
}

int overall(int arr[],int n)
{
    int normal=normal_max(arr,n);

    if(normal<0)
        return normal;
    
    int arr_sum=0;
    for(int i=0;i<n;i++)
    {
        arr_sum=arr_sum+arr[i];
        arr[i]=-arr[i];
    }
    int circular=arr_sum+normal_max(arr,n);

    return max(normal,circular);
}

int main()
{
    int arr[]={8,-4,3,-5,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<overall(arr,n);

    return 0;
}