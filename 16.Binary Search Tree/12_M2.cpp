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

bool pair_sum(node *root,int sum,unordered_set<int> &s)
{
    if(root==NULL)
        return false;
    if(pair_sum(root->left,sum,s)==true)
        return true;
    
    if(s.find(sum-root->key)!=s.end())
        return true;
    else
        s.insert(root->key);
    
    return pair_sum(root->right,sum,s);
}

int main()
{
    node *root=new node(30);
    root->left=new node(20);
    root->right=new node(40);
    root->right->right=new node(45);
    root->left->left=new node(15);
    root->left->right=new node(25);
    root->left->right->left=new node(22);
    root->left->right->right=new node(27);

    unordered_set<int> s;
    cout<<pair_sum(root,67,s);

    return 0;
}