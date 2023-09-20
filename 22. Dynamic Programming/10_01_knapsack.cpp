#include<bits/stdc++.h>
using namespace std;

// O(2^n) time
// DP soln is O(n*cap) time. So if cap is very huge, say 4000, then Recusrsive soln is good else DP is good
// DP soln is optimal when cap is small
int knapsack(int vals[],int wts[],int cap,int n)
{
    if(n==0 || cap==0)
        return 0;

    if(wts[n-1]>cap)
        return knapsack(vals,wts,cap,n-1);
    else
        return max(knapsack(vals,wts,cap,n-1),vals[n-1] + knapsack(vals,wts,cap-wts[n-1],n-1));
}

int main()
{
    int vals[]={60,100,120};
    int wts[]={10,20,30};
    int n=sizeof(vals)/sizeof(vals[0]);
    int cap=50;

    cout<<knapsack(vals,wts,cap,n);

    return 0;
}