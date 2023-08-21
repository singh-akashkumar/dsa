#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

map<int,int> m;
void vertical_sum(node *root,int hd)
{
    if(root==NULL)
        return;
    m[hd]+=root->key;
    vertical_sum(root->left,hd-1);
    vertical_sum(root->right,hd+1);
}

int main()
{
    node *root=new node(30);
    root->left=new node(20);
    root->right=new node(40);
    root->right->right=new node(16);
    root->left->left=new node(15);
    root->left->right=new node(25);
    root->left->right->left=new node(22);
    root->left->right->right=new node(47);

    vertical_sum(root,0);
    for(auto x:m)
        cout<<x.second<<"  ";

    return 0;
}