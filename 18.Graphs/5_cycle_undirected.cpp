#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

bool dfsrec(vector<int> adj[],int s,bool visited[],int parent)
{
    visited[s]=true;

    for(int v:adj[s])
    {
        if(visited[v]==false)
        {
            if(dfsrec(adj,v,visited,s)==true)
                return true;
        }
        else if(v!=parent)
            return true;
    }
    return false;
}

bool cycle(vector<int> adj[],int n)
{
    bool visited[n]={false};
    for(int i=0;i<n;i++)
        if(visited[i]==false)
            if(dfsrec(adj,i,visited,-1)==true)
                return true;
    
    return false;
}

int main()
{
    int n=5;
    vector<int> adj[n];

    add_edge(adj,0,1);
    add_edge(adj,2,3);
    add_edge(adj,3,4);
    add_edge(adj,2,4);

    cout<<cycle(adj,n);
    
    return 0;
}