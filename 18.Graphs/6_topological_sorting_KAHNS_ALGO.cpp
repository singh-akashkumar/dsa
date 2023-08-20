#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int x,int y)
{
    adj[x].push_back(y);
}

// BFS based Kahn's Algorithm - O(V+E) time
void topological_sorting(vector<int> adj[],int n)
{
    vector<int> in_degree(n,0);    // vector of size n initialized with 0
    for(int u=0;u<n;u++)
        for(int v:adj[u])
            in_degree[v]++;
    
    queue<int> q;
    for(int i=0;i<n;i++)
        if(in_degree[i]==0)
            q.push(i);
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<"  ";

        for(int v:adj[u])
            if(--in_degree[v]==0)
                q.push(v);
    }
}

int main()
{
    int n=5;
    vector<int> adj[n];

    add_edge(adj,0,2);
    add_edge(adj,0,3);
    add_edge(adj,1,3);
    add_edge(adj,1,4);
    // add_edge(adj,3,4);
    // add_edge(adj,3,5);

    topological_sorting(adj,n);

    return 0;
}