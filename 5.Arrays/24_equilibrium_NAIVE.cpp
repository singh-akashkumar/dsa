#include<iostream>
using namespace std;

bool equi(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        int left=0,right=0;
        for(int j=0;j<i;j++)
            left+=arr[j];
        for(int j=i+1;j<n;j++)
            right+=arr[j];
        
        if(left==right)
            return true;
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