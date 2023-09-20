#include<bits/stdc++.h>
using namespace std;

int soln(int arr[],int i,int j)
{
    if(i+1==j)
        return max(arr[i],arr[j]);
    
    return max(arr[i]+min(soln(arr,i+2,j),soln(arr,i+1,j-1)),   // we have chosen i
                arr[j]+min(soln(arr,i,j-2),soln(arr,i+1,j-1))); // we have chosen j
    
    // min(...) bcz opponent tries to minimize our value
}

int main()
{
    int arr[]={20,5,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<soln(arr,0,n-1);

    return 0;
}