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

// O(h) time and O(1) Aux Space
node *floor(node *root,int x)
{
    node *curr=root;
    node *flr=NULL;
    while(curr!=NULL)
    {
        if(curr->key==x)
            return curr;
        else if(curr->key<x)
        {
            flr=curr;
            curr=curr->right;
        }
        else 
            curr=curr->left;
    }
    return flr;
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

    node *res=floor(root,19);
    cout<<res->key;

    return 0;
}