#include<iostream>
#include<unordered_map>
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

int equal01(int arr[],int n)
{
    for(int i=0;i<n;i++)
        if(arr[i]==0)
            arr[i]=-1;
    
    return (longest_sum(arr,n,0));
}

int main()
{
    int arr[]={1,1,1,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<equal01(arr,n);

    return 0;
}