#include<bits/stdc++.h>
using namespace std;

void k_closest(int arr[],int n,int x,int k)
{
    priority_queue<pair<int,int>> pq;   // max heap
    for(int i=0;i<k;i++)
        pq.push({abs(arr[i]-x),i});
    
    for(int i=k;i<n;i++)
    {
        int diff=abs(arr[i]-x);
        if(diff<pq.top().first)
        {
            pq.pop();
            pq.push({diff,i});
        }
    }

    stack<int> s;
    while(!pq.empty())
    {
        s.push(arr[pq.top().second]);
        pq.pop();
    }
    while(!s.empty())
    {
        cout<<s.top()<<"  ";
        s.pop();
    }
}

int main()
{
    int arr[]={10,15,7,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=8;
    int k=2;

    k_closest(arr,n,x,k);

    return 0;
}