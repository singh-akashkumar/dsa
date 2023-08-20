#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void bfs(vector<int> adj[],int n,int s)
{
    bool visited[n]={false};
    
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<"  ";
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n=6;
    vector<int> adj[n];

    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,0,5);
    add_edge(adj,1,3);
    add_edge(adj,2,4);
    add_edge(adj,3,5);
    add_edge(adj,4,5);

    int s=0;

    cout<<"BFS Traversal is:"<<endl;
    bfs(adj,n,s);


    return 0;
}