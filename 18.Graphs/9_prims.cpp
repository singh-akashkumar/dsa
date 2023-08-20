#include<bits/stdc++.h>
using namespace std;
#define n 4

// theta(n^2) time
int prims(int graph[n][n])
{
    bool mst[n]={false};    // true if vertex is in 1st set
    int key[n];
    fill(key,key+n,INT_MAX);
    key[0]=0;
    int res=0;

    for(int count=0;count<n;count++)
    {
        int u=-1;
        for(int i=0;i<n;i++)
            if(mst[i]==false && (u==-1 || key[i]<key[u]))
                u=i;
        
        mst[u]=true;
        res=res+key[u];

        for(int v=0;v<n;v++)
            if(graph[u][v]!=0 && mst[v]==false)
                key[v]=min(key[v],graph[u][v]);
    }

    return res;
}

int main()
{
    int graph[n][n]={{0,5,8,0},
                    {5,0,10,15},
                    {8,10,0,20},
                    {0,15,20,0}};
    
    cout<<prims(graph);

    return 0;
}