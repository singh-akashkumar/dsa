#include<bits/stdc++.h>
using namespace std;

// O(n log n) time
void left_ceiling(int arr[],int n)
{
    set<int> s;
    s.insert(arr[0]);
    cout<<-1<<"  ";
    for(int i=1;i<n;i++)
    {
        if(s.lower_bound(arr[i])==s.end())
            cout<<-1<<"  ";
        else
            cout<<*(s.lower_bound(arr[i]))<<"  ";
        
        s.insert(arr[i]);
    }
}

int main()
{
    int arr[]={2,8,30,15,25,12};
    int n=sizeof(arr)/sizeof(arr[0]);

    left_ceiling(arr,n);

    return 0;
}