#include<bits/stdc++.h>
using namespace std;

int ed(string s1,string s2,int m,int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;
    
    if(s1[m-1]==s2[n-1])
        return ed(s1,s2,m-1,n-1);
    else
        return 1 + min(ed(s1,s2,m,n-1),min(ed(s1,s2,m-1,n),ed(s1,s2,m-1,n-1)));
}

int main()
{
    string s1="saturday";
    string s2="sunday";

    cout<<ed(s1,s2,s1.length(),s2.length());

    return 0;
}