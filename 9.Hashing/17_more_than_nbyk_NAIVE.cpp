#include<bits/stdc++.h>
using namespace std;

void nbyk(int arr[],int n,int k)
{
    sort(arr,arr+n);
    int count=1;
    int i=1;
    for(i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            count++;
        }
        else
        {
            if(count>n/k)
                cout<<arr[i-1]<<"  ";
            count=1;
        }
    }
    if(count>n/k)
        cout<<arr[i-1]<<"  ";
}

int main()
{
    int arr[]={10, 10, 20, 30, 20, 10,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;

    nbyk(arr,n,k);

    return 0;
}