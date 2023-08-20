#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int x,int y)
{
    adj[x].push_back(y);
}

bool cycle(vector<int> adj[],int n)
{
    vector<int> indegree(n,0);
    for(int u=0;u<n;u++)
        for(int v:adj[u])
            indegree[v]++;
    
    queue<int> q;
    for(int i=0;i<n;i++)
        if(indegree[i]==0)
            q.push(i);
    
    int count=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
        count++;

        for(int v:adj[u])
            if(--indegree[v]==0)
                q.push(v);
    }

    return (count!=n);
}

int main()
{
    int n=4;
    vector<int> adj[n];

    add_edge(adj,0,1);
    add_edge(adj,1,2);
    add_edge(adj,2,3);
    add_edge(adj,1,3);
    // add_edge(adj,3,4);
    // add_edge(adj,3,5);

    cout<<cycle(adj,n);

    return 0;
}