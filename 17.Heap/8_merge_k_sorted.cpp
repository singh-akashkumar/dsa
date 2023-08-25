#include<bits/stdc++.h>
using namespace std;

struct triplet
{
    int val,arr_index,value_index;
    triplet(int v,int ap,int vp)
    {
        val=v;
        arr_index=ap;
        value_index=vp;
    }
};

struct mycomp
{
    bool operator()(triplet t1,triplet t2)
    {
        return t1.val>t2.val;
    }
};

// O(nk log k) time
vector<int> merge(vector<vector<int>> v)
{
    priority_queue<triplet,vector<triplet>,mycomp> pq;

    for(int i=0;i<v.size();i++)
    {
        triplet t(v[i][0],i,0);
        pq.push(t);
    }

    vector<int> res;
    while(!pq.empty())
    {
        triplet curr=pq.top();
        pq.pop();
        res.push_back(curr.val);

        int ap=curr.arr_index,vp=curr.value_index;
        if(vp+1<v[ap].size())
        {
            triplet t(v[ap][vp+1],ap,vp+1);
            pq.push(t);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> v={{10,20},
                            {5,15},
                            {4,9,11}};
    
    vector<int> res=merge(v);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<"  ";

    return 0;
}