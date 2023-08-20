#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int x,int y)
{
    adj[x].push_back(y);
}

void ordering(vector<int> adj[],int u,stack<int> &s,bool visited[])
{
    visited[u]=true;
    for(int v:adj[u])
        if(visited[v]==false)
            ordering(adj,v,s,visited);
    
    s.push(u);
}

void dfsrec(vector<int> adj[],int u,bool visited2[])
{
    visited2[u]=true;
    cout<<u<<"  ";
    for(int v:adj[u])
        if(visited2[v]==false)
            dfsrec(adj,v,visited2);
}

void kosaraju(vector<int> adj[],int n)
{
    stack<int> s;    
    vector<int> step1;
    bool visited[n]={false};
    for(int u=0;u<n;u++)
        if(visited[u]==false)
            ordering(adj,u,s,visited);
    
    while(!s.empty())
    {
        step1.push_back(s.top());
        s.pop();
    }

    vector<int> reverse[n];
    for(int u=0;u<n;u++)
        for(int v:adj[u])
            add_edge(reverse,v,u);
    
    bool visited2[n]={false};
    for(int u:step1)
    {
        if(visited2[u]==false)
        {
            dfsrec(reverse,u,visited2);
            cout<<endl;
        }
    }

}

int main()
{
    int n=5;
    vector<int> adj[n];

    add_edge(adj,0,1);
    add_edge(adj,1,2);
    add_edge(adj,2,0);
    add_edge(adj,1,3);
    add_edge(adj,3,4);
    //add_edge(adj,4,3);

    kosaraju(adj,n);

    return 0;
}