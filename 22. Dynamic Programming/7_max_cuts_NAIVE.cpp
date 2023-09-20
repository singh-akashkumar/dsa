#include<bits/stdc++.h>
using namespace std;

// O(3^n) time
int maxcuts(int rope,int a,int b,int c)
{
    if(rope<0)
        return -1;
    if(rope==0)
        return 0;
    
    int res=max(maxcuts(rope-a,a,b,c),max(maxcuts(rope-b,a,b,c),maxcuts(rope-c,a,b,c)));

    if(res==-1)
        return -1;
    else
        return res+1;
}

int main()
{
    int rope=3;
    int a=2,b=4,c=2;

    cout<<maxcuts(rope,a,b,c);

    return 0;
}