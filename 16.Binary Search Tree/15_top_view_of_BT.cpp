#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left,*right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

void vertical_traversal(node *root)
{
    map<int,int> m;     // key is horizontal dist and value is node key
    queue<pair<node *,int> > q;  //pair of node and its horizontal distance

    q.push({root,0});
    while(!q.empty())
    {
        auto p=q.front();
        node *curr=p.first;
        int hd=p.second;
        q.pop();
       
        if(m.find(hd)==m.end())
            m[hd]=curr->key;

        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    for(auto x:m)
        cout<<x.second<<"  ";
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);

    vertical_traversal(root);

    return 0;
}