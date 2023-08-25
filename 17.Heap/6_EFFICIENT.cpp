#include<bits/stdc++.h>
using namespace std;

void k_largest(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++)
        pq.push(arr[i]);
    
    for(int i=k;i<n;i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<"  ";
        pq.pop();
    }
}

int main()
{
    int arr[]={8,6,4,10,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    k_largest(arr,n,3);

    return 0;
}