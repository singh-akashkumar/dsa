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

void dfs(vector<int> adj[],int n)
{
    bool visited[n]={false};
    for(int i=0;i<n;i++)
        if(visited[i]==false)
            dfsrec(adj,i,visited);    
}

int main()
{
    int n=5;
    vector<int> adj[n];

    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,1,2);

    add_edge(adj,3,4);
    // add_edge(adj,1,4);
    // add_edge(adj,4,5);
    //add_edge(adj,5,6);

    cout<<"DFS Traversal is:"<<endl;
    dfs(adj,n);
    
    return 0;
}