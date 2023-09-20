#include<bits/stdc++.h>
using namespace std;

int memo[100];

int fib(int n)
{
    if(memo[n]==-1)
    {
        int res;
        if(n==0 || n==1)
            res=n;
        else
            res=fib(n-1)+fib(n-2);
        
        memo[n]=res;
    }
    return memo[n];
}

int main()
{
    int n=10;
    memset(memo,-1,sizeof(memo));
    cout<<fib(n)<<endl;
    for(int i=0;i<n;i++)
        cout<<memo[i]<<"  ";
    return 0;
}