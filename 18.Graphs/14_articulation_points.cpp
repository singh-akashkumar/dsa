#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void APutil(vector<int> adj[],int u,bool visited[],int &tim,int parent,bool isAP[],int disc[],int low[])
{
    visited[u]=true;
    int children=0;     // count of children of u
    disc[u]=low[u]=++tim;  // initialize disc and low value for u

    for(int v:adj[u])
    {
        if(visited[v]==false)
        {
            children++;
            APutil(adj,v,visited,tim,u,isAP,disc,low);

            low[u]=min(low[u],low[v]);

            if(parent!=-1 && low[v]>=disc[u])
                isAP[u]=true;
        }
        else if(v!=parent)
            low[u]=min(low[u],disc[v]);
    }

    if(parent==-1 && children>1)
        isAP[u]=true;
}

void articulation_pts(vector<int> adj[],int n)
{
    bool visited[n]={false};
    int disc[n]={0};
    int low[n];
    bool isAP[n]={false};
    int tim=0,parent=-1;

    for(int u=0;u<n;u++)
        if(visited[u]==false)
            APutil(adj,u,visited,tim,parent,isAP,disc,low);
    
    for(int i=0;i<n;i++)
        if(isAP[i]==true)
            cout<<i<<"  ";
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

    articulation_pts(adj,n);

    return 0;
}