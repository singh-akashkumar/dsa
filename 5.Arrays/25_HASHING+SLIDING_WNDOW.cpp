#include<bits/stdc++.h>
using namespace std;

void dist_window(int arr[],int n,int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<k;i++)
        m[arr[i]]++;
    cout<<m.size()<<"  ";
    for(int i=k;i<n;i++)
    {
        m[arr[i-k]]--;
        if(m[arr[i-k]]==0)
            m.erase(arr[i-k]);
        m[arr[k]]++;
        cout<<m.size()<<"  ";
    }
}

int main()
{
    int arr[]={1,2,1,3,4,3,3};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);

    dist_window(arr,n,k);

    return 0;
}