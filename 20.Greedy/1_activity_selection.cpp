#include<bits/stdc++.h>
using namespace std;

bool mycomp(pair<int,int> a,pair<int,int> b)
{
    return (a.second<b.second);
}

int maxActivities(pair<int,int> arr[],int n)
{
    sort(arr,arr+n,mycomp);

    int res=1;
    int prev=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first>=arr[prev].second)
        {
            res++;
            prev=i;
        }
    }
    return res;
}

int main()
{
    pair<int,int> arr[]={{12,25},{10,20},{20,30},{2,17},{3,8}};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<maxActivities(arr,n);

    return 0;
}