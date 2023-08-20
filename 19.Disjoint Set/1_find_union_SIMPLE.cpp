#include<bits/stdc++.h>
using namespace std;
#define n 5

int parent[n];
void initialize()
{
    for(int i=0;i<n;i++)
        parent[i]=i;
}

int find(int x)
{
    if(parent[x]==x)
        return x;
    else
        return find(parent[x]);
}

void _union(int x,int y)
{
    int x_rep=find(x);
    int y_rep=find(y);

    if(x==y)
        return;
    
    parent[y_rep]=x_rep;
}

int main()
{
    initialize();

    _union(2,3);
    _union(0,2);
    cout<<find(0)<<endl;
    cout<<find(3)<<endl;
    cout<<find(2)<<endl;
    cout<<find(1)<<endl;

    return 0;
}