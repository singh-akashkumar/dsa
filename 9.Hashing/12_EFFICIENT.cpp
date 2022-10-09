#include<iostream>
#include<unordered_map>
using namespace std;

int longest_sum(int arr[],int n,int sum)
{
    unordered_map<int,int> m;
    int presum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        if(presum==sum)
            res=i+1;
        if(m.find(presum)==m.end())     // if presum is already not present  
            m.insert({presum,i});       // ensures that only leftmost occurence of presum is inserted
        if(m.find(presum-sum)!=m.end())
            res=max(res,i-m[presum-sum]);
    }
    return res;
}

int main()
{
    int arr[]={1,1,1,1,-1,-1,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;

    cout<<longest_sum(arr,n,sum);

    return 0;
}