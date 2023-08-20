#include<bits/stdc++.h>
using namespace std;

void dist_window(int arr[],int n,int k)
{
    for(int i=0;i<=n-k;i++)
    {
        unordered_set<int> s;
        for(int j=i;j<k+i;j++)
            s.insert(arr[j]);
        cout<<s.size()<<"  ";
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