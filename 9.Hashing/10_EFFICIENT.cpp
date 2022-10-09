#include<iostream>
#include<unordered_set>
using namespace std;

bool zerosubsum(int arr[],int n)
{
    unordered_set<int> s;
    int presum=0;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        if(s.find(presum)!=s.end())
            return true;
        if(presum==0)
            return true;
        s.insert(presum);
    }
    return false;
}

int main()
{
    int arr[]={1,4,13,-4,-10,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<zerosubsum(arr,n);

    return 0;
}