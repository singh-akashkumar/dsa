#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
}

void tarjans_util(vector<int> adj[],int u,int disc[],int low[],stack<int> &s,int &time,int parent,bool in_stk[])
{
    disc[u]=low[u]=++time;
    s.push(u);
    in_stk[u]=true;

    for(int v:adj[u])
    {
        if(disc[v]==0)
        {
            tarjans_util(adj,v,disc,low,s,time,u,in_stk);
            low[u]=min(low[u],low[v]);
        }
        else if(in_stk[v]==true)
            low[u]=min(low[u],disc[v]);
    }

    if(low[u]==disc[u])
    {
        while(s.top()!=u)
        {
            cout<<s.top()<<"  ";
            in_stk[s.top()]=false;
            s.pop();
        }
        cout<<s.top()<<endl;
        in_stk[s.top()]=false;
        s.pop();
    }
}

void tarjans(vector<int> adj[],int n)
{
    int disc[n]={0};
    int low[n];
    stack<int> s;
    bool in_stk[n]={false};
    int time=0;

    for(int u=0;u<n;u++)
        if(disc[u]==0)
            tarjans_util(adj,u,disc,low,s,time,-1,in_stk);
}

int main()
{
    int n=5;
    vector<int> adj[n];

    add_edge(adj,1,0);
    add_edge(adj,0,2);
    add_edge(adj,2,1);
    add_edge(adj,0,3);
    add_edge(adj,3,4);

    tarjans(adj,n);

    return 0;
}