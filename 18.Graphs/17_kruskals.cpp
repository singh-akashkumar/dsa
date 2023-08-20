#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<vector<int>> &edges,int x,int y,int wt)
{
    edges.push_back({x,y,wt});
}

int find(int x,int parent[])
{
    if(parent[x]==x)
        return x;
    else 
        return find(parent[x],parent);
}

void _union(int x,int y,int parent[],int rank1[])
{
    int xrep=find(x,parent);
    int yrep=find(y,parent);
    if(xrep==yrep)
        return;
    
    if(rank1[xrep]<rank1[yrep])
        parent[xrep]=yrep;
    else if(rank1[xrep]>rank1[yrep])
        parent[yrep]=xrep;
    else
    {
        parent[yrep]=xrep;
        rank1[xrep]++;
    }
}

static bool mycomp(vector<int> &a,vector<int> &b)
{
    return a[2]<b[2];
}

int kruskal(vector<vector<int>> edges,int n)
{
    int parent[n+1];
    int rank1[n+1];
    for(int i=1;i<n+1;i++)
    {
        parent[i]=i;
        rank1[i]=0;
    }
    sort(edges.begin(),edges.end(),mycomp);

    int res=0;
    int count=0;

    for(vector<int> edge:edges)
    {
        int x=edge[0];
        int y=edge[1];
        int wt=edge[2];

        if(find(x,parent)!=find(y,parent))
        {
            res=res+wt;
            count++;
            _union(x,y,parent,rank1);
        }
        if(count==n-1)
            break;
    }
    return res;
}

int main()
{
    int n=4;

    vector<vector<int>> edges;
    
    add_edge(edges,1,2,5);
    add_edge(edges,2,3,6);
    add_edge(edges,1,4,7);
    add_edge(edges,2,4,8);
    add_edge(edges,3,4,7);
    //add_edge(edges,3,4,2);

    cout<<kruskal(edges,n);

    return 0;
}