#include<bits/stdc++.h>
using namespace std;
const int n=4;

void add_edge(vector<pair<int,int>> adj[],int x,int y,int wt)
{
    adj[x].push_back({y,wt});
}

void shortestpath_dag(vector<pair<int,int>> adj[],int s)
{
        int dist[n];
        fill(dist,dist+n,INT_MAX);
        dist[s]=0;
       
        queue<int> q;
        int indegree[n]={0};
        for(int u=0;u<n;u++)
            for(auto v:adj[u])
                indegree[v.first]++;
       
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
       
        vector<int> topo;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
           
            topo.push_back(u);
           
            for(auto v:adj[u])
                if(--indegree[v.first]==0)
                    q.push(v.first);
        }
       
        for(int u:topo)
        {
            for(auto p:adj[u])
            {
                int v=p.first;
                int wt=p.second;
                if(dist[v]>dist[u]+wt)
                    dist[v]=dist[u]+wt;
            }
        }

        for(int i=0;i<n;i++)
            cout<<dist[i]<<"  ";
}

int main()
{
    vector<pair<int,int>> adj[n];

    add_edge(adj,0,1,1);
    add_edge(adj,1,2,3);
    add_edge(adj,1,3,2);
    add_edge(adj,2,3,4);
    // add_edge(adj,4,2,2);
    // add_edge(adj,4,5,4);
    // add_edge(adj,5,3,1);

    int s=0;

   shortestpath_dag(adj,s);

    return 0;
}
