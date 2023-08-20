#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int x,int y) // for undirected graph
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void print(vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<"  ";
        for(int x:adj[i])
            cout<<x<<"  ";
        cout<<endl;
    }
}

int main()
{
    int v=4;
    vector<int> adj[v];     // array of vectors // vector of vectors can also be used if v is not known
    
    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,1,2);
    add_edge(adj,1,3);

    print(adj,v);

    return 0;
}