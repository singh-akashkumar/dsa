#include<iostream>
#include<unordered_set>
using namespace std;

bool pairsum(int arr[],int n,int sum)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum-arr[i])!=s.end())
            return true;
        
        s.insert(arr[i]);
    }
    return false;
}

int main()
{
    int arr[]={11,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=10;

    cout<<pairsum(arr,n,sum);

    return 0;
}