#include<iostream>
#include<unordered_map>
using namespace std;

void freq(int arr[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    
    for(auto x:m)
        cout<<x.first<<"  "<<x.second<<endl;

    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(m[arr[i]]!=-1)
        {
            cout<<arr[i]<<"  "<<m[arr[i]]<<endl;
            m[arr[i]]=-1;
        }
    }
}

int main()
{
    int arr[]={10,13,10,17,12,13,14,20,12,18,17,12};
    int n=sizeof(arr)/sizeof(arr[0]);

    freq(arr,n);

    return 0;
}