#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,wt;
};

struct Graph
{
    int V,E;
    struct Edge* edge;
};

struct Graph* create_graph(int V,int E)
{
    struct Graph* graph=new Graph;
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[E];
    return graph;
}

void print(int dist[],int n)
{
    cout<<"Vertex distance from Source to:"<<endl;
    for(int i=0;i<n;i++)
        cout<<i<<"  "<<dist[i]<<endl;
}

void bellman_ford(struct Graph* graph,int source)
{
    int V=graph->V;
    int E=graph->E;
    int dist[V]={INT_MAX};
    //fill(dist,dist+V,INT_MAX);
    dist[source]=0;

    for(int i=1;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int weight=graph->edge[j].wt;

            if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight)
                dist[v]=dist[u]+weight;
        }
    }

    for(int i=0;i<E;i++)
    {
        int u=graph->edge[i].src;
        int v=graph->edge[i].dest;
        int weight=graph->edge[i].wt;

        if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight)
        {
            cout<<"Negative Weight Cycle found.";
            return;
        }
    }
    
    print(dist,V);
    return;
}

int main()
{
    int V=4;
    int E=5;
    struct Graph *graph=create_graph(V,E);

    graph->edge[0].src=0;
    graph->edge[0].dest=1;
    graph->edge[0].wt=1;

    graph->edge[1].src=0;
    graph->edge[1].dest=2;
    graph->edge[1].wt=4;

    graph->edge[2].src=1;
    graph->edge[2].dest=2;
    graph->edge[2].wt=-3;

    graph->edge[3].src=1;
    graph->edge[3].dest=3;
    graph->edge[3].wt=2;

    graph->edge[4].src=2;
    graph->edge[4].dest=3;
    graph->edge[4].wt=3;

    bellman_ford(graph,0);

    return 0;
}