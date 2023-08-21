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

node *successor(node *curr)
{
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}

node *delet(node *root,int x)
{
    if(root==NULL)
        return NULL;
    
    if(root->key<x)
        root->right=delet(root->right,x);
    else if(root->key>x)
        root->left=delet(root->left,x);
    else
    {
        if(root->left==NULL)    // also handles the case when both children are null
        {
            node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            node *succ=successor(root);
            root->key=succ->key;
            root->right=delet(root->right,succ->key);
        }
    }
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

    root=delet(root,30);
    inorder_print(root);
    // cout<<endl;
    // root=insert_rec(root,42);
    // inorder_print(root);

    return 0;
}