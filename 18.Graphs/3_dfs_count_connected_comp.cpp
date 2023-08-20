#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void dfsrec(vector<int> adj[],int s,bool visited[])
{
    visited[s]=true;

    for(int u:adj[s])
        if(visited[u]==false)
            dfsrec(adj,u,visited);
}

int dfs(vector<int> adj[],int n)
{
    bool visited[n]={false};
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfsrec(adj,i,visited);
            count++;
        }
    }
    return count;
}

int main()
{
    int n=6;
    vector<int> adj[n];

    add_edge(adj,0,1);
    
    add_edge(adj,2,3);
    add_edge(adj,3,4);
    add_edge(adj,2,4);

    cout<<dfs(adj,n);
    
    return 0;
}