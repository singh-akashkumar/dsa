#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    int lcount;     // lcount is the count of nodes in the left subtree
    node(int x)
    {
        key=x;
        left=right=NULL;
        lcount=0;
    }
};

node *insert_bst(node *root,int x)
{
    if(root==NULL)
        return new node(x);
    
    if(x<root->key)
    {
        root->left=insert_bst(root->left,x);
        root->lcount++;
    }
    else if(x>root->key)
        root->right=insert_bst(root->right,x);
    
    return root;
}

// O(h) time
// Augmented Tree Data Structure - maintain rank of each node
node *ksmall(node *root,int k)
{
    if(root==NULL)
        return NULL;
    
    if(root->lcount+1==k)
        return root;
    else if(root->lcount+1>k)
        return ksmall(root->left,k);
    else
        return ksmall(root->right,k-root->lcount-1);
}

int main()
{
    node *root=NULL;
    int arr[]={30,20,40,45,15,25,22,27};
    for(int x:arr)
        root=insert_bst(root,x);

    node *res;
    res=ksmall(root,9);
    if(res==NULL)
        cout<<"The tree has less number of nodes than given k.";
    else
        cout<<res->key;

    return 0;
}