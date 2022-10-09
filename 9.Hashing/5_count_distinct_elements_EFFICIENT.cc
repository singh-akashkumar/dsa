#include<iostream>
#include<unordered_set>
using namespace std;

// Time theta(n) and Aux Space O(n)
int count_dist(int arr[],int n)
{
    unordered_set<int> s(arr,arr+n);
    return s.size();
}

int main()
{
    int arr[]={12,13,18,14,13};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<count_dist(arr,n);

    return 0;
}