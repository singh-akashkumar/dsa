#include<bits/stdc++.h>
using namespace std;

bool mycomp(pair<int,int> a,pair<int,int> b)
{
    double r1=a.second/a.first;
    double r2=b.second/b.first;

    return (r1>r2);
}

double fractional_knapsack(pair<int,int> arr[],int n,int cap)
{
    sort(arr,arr+n,mycomp);

    double res=0;
    double curr_cap=cap;

    for(int i=0;i<n;i++)
    {
        if(arr[i].first<=curr_cap)
        {
            res=res+arr[i].second;
            curr_cap=curr_cap-arr[i].first;
        }
        else
        {
            res=res+((curr_cap/arr[i].first)*arr[i].second);
            break;
        }
    }
    return res;
}

int main()
{
    pair<int,int> arr[]={{50,600},{20,500},{30,400}};   // pairs of wts and values
    int n=sizeof(arr)/sizeof(arr[0]);
    int cap=70;

    cout<<"Max values in the knapsaack is: "<<fractional_knapsack(arr,n,cap);

    return 0;
}