#include<bits/stdc++.h>
using namespace std;

int longest_sum(int arr[],int n,int sum)
{
    unordered_map<int,int> m;
    int presum=0,res=0;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        if(presum==sum)
            res=i+1;
        if(m.find(presum)==m.end())
            m.insert({presum,i});
        if(m.find(presum-sum)!=m.end())
            res=max(res,i-m[presum-sum]);
    }
    return res;
}

int common_span(int a[],int b[],int n)
{
    int temp[n];
    for(int i=0;i<n;i++)
        temp[i]=a[i]-b[i];
    
    return longest_sum(temp,n,0);
}

int main()
{
    int a[]={0,1,0,0,0,0};
    int b[]={1,0,1,0,0,1};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<common_span(a,b,n);

    return 0;
}