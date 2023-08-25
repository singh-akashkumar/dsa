#include<bits/stdc++.h>
using namespace std;

// O(n) + O(k log n) time
void k_largest(int arr[],int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
        pq.push(arr[i]);
    
    int temp[k];
    for(int i=0;i<k;i++)
    {
        temp[i]=pq.top();
        pq.pop();
    }
    for(int i=k-1;i>=0;i--)
        cout<<temp[i]<<"  ";
}

int main()
{
    int arr[]={8,6,4,10,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    k_largest(arr,n,3);

    return 0;
}