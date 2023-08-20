#include<bits/stdc++.h>
using namespace std;
#define n 4

// theta(n^2) time
vector<int> dijkstra(int graph[n][n],int src)
{
    vector<bool> fin(n,false);      // vector of vertices that have been finalized
    vector<int> dist(n,INT_MAX);
    dist[src]=0;

    for(int count=0;count<n;count++)
    {
        int u=-1;
        for(int i=0;i<n;i++)
            if(fin[i]==false && (u==-1 || dist[i]<dist[u]))
                u=i;
        
        fin[u]=true;

        for(int v=0;v<n;v++)
            if(graph[u][v]!=0 && fin[v]==false)
                dist[v]=min(dist[v],dist[u]+graph[u][v]);
    }
    return dist;
}

int main()
{
    int graph[n][n]={{0,5,10,0},
                    {5,0,3,20},
                    {10,3,0,2},
                    {0,20,2,0}};
    int src=0;
    vector<int> res=dijkstra(graph,src);
    for(int x:res)
        cout<<x<<"  ";

    return 0;
}