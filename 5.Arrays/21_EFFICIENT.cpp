#include<iostream>
using namespace std;

int majority(int arr[],int n)
{
    int res=0,count=1;

    for(int i=1;i<n;i++)
    {
        if(arr[res]==arr[i])
            count++;
        else
            count--;
        
        if(count==0)
        {
            count=1;
            res=i;
        }
    }

    count=0;
    for(int i=0;i<n;i++)
        if(arr[i]==arr[res])
            count++;
    if(count<=n/2)
        res=-1;
    
    return res;
}

int main()
{
    int arr[]={3,7,4,7,7,5,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<majority(arr,n);

    return 0;
}