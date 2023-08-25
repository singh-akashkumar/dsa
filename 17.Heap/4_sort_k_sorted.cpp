#include<bits/stdc++.h>
using namespace std;

void ksort(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;    //min heap
    for(int i=0;i<=k;i++)
        pq.push(arr[i]);
    
    int index=0;
    for(int i=k+1;i<n;i++)
    {
        arr[index++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty())
    {
        arr[index++]=pq.top();
        pq.pop();
    }
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
}

int main()
{
    int arr[]={10,9,7,8,4,70,50,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;

    print(arr,n);
    cout<<endl;
    ksort(arr,n,k);
    print(arr,n);

    return 0;
}