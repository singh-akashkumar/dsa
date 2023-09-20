#include<bits/stdc++.h>
using namespace std;

int max_trials(int e,int f)
{
    if(f==1 || f==0)
        return f;
    if(e==1)
        return f;
    
    int curr,res=INT_MAX;
    for(int x=1;x<=f;x++)
    {
        curr=max(max_trials(e-1,x-1),max_trials(e,f-x));
        res=min(res,curr);
    }   
    return res+1;
}

int main()
{
    int e=2,f=10;

    cout<<max_trials(e,f);

    return 0;
}