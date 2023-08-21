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

void inorder(node *root)
{
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->key<<"  ";
    inorder(root->right);
}

node *previ=NULL,*first=NULL,*second=NULL;      //Global
void fix_bst(node *root)
{
    if(root==NULL)
        return;

    fix_bst(root->left);
    if(previ!=NULL && root->key<previ->key)
    {
        if(first==NULL)
            first=previ;
        
        second=root;
    }
    previ=root;
    fix_bst(root->right);
}

int main()
{
    node *root=new node(30);
    root->left=new node(20);
    root->right=new node(40);
    root->right->right=new node(25);
    root->left->left=new node(15);
    root->left->right=new node(45);
    root->left->right->left=new node(22);
    root->left->right->right=new node(27);

    inorder(root);
    cout<<endl;
    fix_bst(root);
    int temp=first->key;
    first->key=second->key;
    second->key=temp;
    inorder(root);

    return 0;
}