#include<bits/stdc++.h>
using namespace std;

vector<int> three_parts(int arr[],int n)
{
    vector<int> v;
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    if(sum%3!=0)
    {
        v.push_back(-1);
        return v;
    }

    int s1=sum/3;
    int s2=2*(sum/3);
    int presum=arr[0];

    for(int i=1;i<n-1;i++)
    {
        if(presum==s1)
            v.push_back(i-1);
        if(presum==s2)
        {
            v.push_back(i-1);
            return v;
        }
        presum+=arr[i];
    }
    if(v.size()==0)
        v.push_back(-1);

    return v;
}

int main()
{
    int arr[]={1,3,4,0,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    vector<int> v=three_parts(arr,n);
    for(int x:v)
        cout<<x<<"  ";

    return 0;
}