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

// O(h) time and O(h) Aux Space
bool search_tree(node *root,int x)
{
    if(root==NULL)
        return false;
    else if(root->key==x)
        return true;
    else if(root->key>x)
        return search_tree(root->left,x);
    else if(root->key<x)
        return search_tree(root->right,x);
}

// O(h) time and O(1) Aux Space
bool search_it(node *root,int x)
{
    node *curr=root;
    while(curr!=NULL)
    {
        if(curr->key==x)
            return true;
        else if(curr->key<x)
            curr=curr->right;
        else
            curr=curr->left;
    }
    return false;
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

    cout<<search_tree(root,23)<<endl;
    cout<<search_it(root,23);

    return 0;
}