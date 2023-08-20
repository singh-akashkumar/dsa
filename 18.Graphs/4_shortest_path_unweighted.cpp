#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void shortest_path(vector<int> adj[],int s,int n)
{
    int dist[n]={INT_MAX};
    bool visited[n]={false};
    queue<int> q;
    q.push(s);
    visited[s]=true;
    dist[s]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                dist[v]=dist[u]+1;
                visited[v]=true;
                q.push(v);
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<dist[i]<<"  ";
}

int main()
{
    int n=6;
    vector<int> adj[n];

    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,0,4);
    add_edge(adj,1,3);
    add_edge(adj,2,3);
    add_edge(adj,2,4);
    add_edge(adj,3,5);
    add_edge(adj,4,5);

    int s=0;

    shortest_path(adj,s,n);
    
    return 0;
}