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
    cout<<s<<"  ";
    for(int u:adj[s])
        if(visited[u]==false)
            dfsrec(adj,u,visited);
}

void dfs(vector<int> adj[],int n,int s)
{
    bool visited[n]={false};
    dfsrec(adj,s,visited);    
}

int main()
{
    int n=6;
    vector<int> adj[n];

    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,1,3);
    add_edge(adj,2,3);
    add_edge(adj,1,4);
    add_edge(adj,4,5);
    //add_edge(adj,5,6);

    int s=0;

    cout<<"DFS Traversal is:"<<endl;
    dfs(adj,n,s);
    
    return 0;
}