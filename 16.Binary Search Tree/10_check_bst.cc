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

bool check_bst(node *root,int min,int max)
{
    if(root==NULL)
        return true;
    
    return (root->key>min && root->key<max && check_bst(root->left,min,root->key) &&
            check_bst(root->right,root->key,max));
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

    cout<<check_bst(root,INT_MIN,INT_MAX);

    return 0;
}