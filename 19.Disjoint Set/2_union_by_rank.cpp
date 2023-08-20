#include<bits/stdc++.h>
using namespace std;
#define n 5

int parent[n];
int _rank[n];
void initialize()
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        _rank[i]=0;
    }
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
    if(x_rep==y_rep)
        return;
    
    if(_rank[x_rep]>_rank[y_rep])
        parent[y_rep]=x_rep;
    else if(_rank[x_rep]<_rank[y_rep])
        parent[x_rep]=y_rep;
    else
    {
        parent[y_rep]=x_rep;
        _rank[x_rep]++;
    }
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