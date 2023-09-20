#include<bits/stdc++.h>
using namespace std;

int no_of_multi(int arr[],int i,int j)
{
    if(i+1==j)          // only 1 matrix
        return 0;
    
    int res=INT_MAX;
    for(int k=i+1;k<j;k++)
        res=min(res,no_of_multi(arr,i,k)+no_of_multi(arr,k,j)+arr[i]*arr[k]*arr[j]);
    
    return res;
}

int main()
{
    int arr[]={3,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<no_of_multi(arr,0,n-1);

    return 0;
}