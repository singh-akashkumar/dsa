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

void inorder_print(node *root)
{
    if(root==NULL)
        return;
    
    inorder_print(root->left);
    cout<<root->key<<"  ";
    inorder_print(root->right);
}

node *insert_func(node *root,int x)
{
    node *temp=new node(x);
    node *curr=root, *parent=NULL;
    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key<x)
            curr=curr->right;
        else if(curr->key>x)
            curr=curr->left;
        else
            return root;
    }
    if(parent==NULL)    // if empty tree is given
        return temp;
    
    if(parent->key>x)
        parent->left=temp;
    else
        parent->right=temp;
    
    return root;
}

node *insert_rec(node *root,int x)
{
    if(root==NULL)
        return new node(x);
    else if(root->key>x)
        root->left=insert_rec(root->left,x);
    else if(root->key<x)
        root->right=insert_rec(root->right,x);
    else
        return root;
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

    root=insert_func(root,23);
    inorder_print(root);
    cout<<endl;
    root=insert_rec(root,42);
    inorder_print(root);

    return 0;
}