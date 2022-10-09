#include<bits/stdc++.h>
using namespace std;

void distwindow(int arr[],int n,int k)
{
    for(int i=0;i<=n-k;i++)
    {
        unordered_set<int> s;
        for(int j=0;j<k;j++)
            s.insert(arr[i+j]);
        
        cout<<s.size()<<"  ";
    }
}

int main()
{
    int arr[]={10,20,20,10,30,40,10};
    int  k=4;
    int n=sizeof(arr)/sizeof(arr[0]);

    distwindow(arr,n,k);

    return 0;
}