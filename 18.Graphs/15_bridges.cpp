#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bridge_util(vector<int> adj[],int u,bool visited[],int disc[],int low[],int &time,int parent)
{
    disc[u]=low[u]=++time;
    visited[u]=true;

    for(int v:adj[u])
    {
        if(visited[v]==false)
        {
            bridge_util(adj,v,visited,disc,low,time,u);

            low[u]=min(low[u],low[v]);

            if(low[v]>disc[u])
                cout<<u<<" - "<<v<<" is a Bridge."<<endl;
        }
        else if(v!=parent)
            low[u]=min(low[u],disc[v]);
    }
}

void bridges(vector<int> adj[],int n)
{
    bool visited[n]={false};
    int disc[n]={0};
    int low[n];
    int time=0,parent=-1;

    for(int u=0;u<n;u++)
        if(visited[u]==false)
            bridge_util(adj,u,visited,disc,low,time,parent);
}

int main()
{
    int n=5;
    vector<int> adj[n];

    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,1,2);
    add_edge(adj,2,3);
    add_edge(adj,3,4);

    bridges(adj,n);

    return 0;
}