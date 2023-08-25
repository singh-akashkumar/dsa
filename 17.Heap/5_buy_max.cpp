#include<bits/stdc++.h>
using namespace std;

int max_items(int cost[],int n,int sum)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
        pq.push(cost[i]);
    
    int res=0;
    while(pq.top()<=sum && pq.empty()==false)
    {
        sum=sum-pq.top();
        pq.pop();
        res++;
    }

    return res;
}

int main()
{
    int cost[]={1,12,5,111,200};
    int n=sizeof(cost)/sizeof(cost[0]);
    int sum=10;

    cout<<max_items(cost,n,sum);

    return 0;
}