#include<iostream>
using namespace std;

int count_dist(int arr[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=0;j<i;j++)
        {
            if(arr[j]==arr[i])
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
            count++;
    }
    return count;
}

int main()
{
    int arr[]={12,13,18,12,14,13,15,16,15};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<count_dist(arr,n);

    return 0;
}