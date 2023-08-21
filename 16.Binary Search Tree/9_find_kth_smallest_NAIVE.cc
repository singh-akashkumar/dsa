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

//O(h+k) time
void ksmall(node *root,int k,int &count)       // &count as reference so that it does not get changed
{
    if(root==NULL)
        return;

    ksmall(root->left,k,count);
    count++;
    if(count==k)
    {
        cout<<root->key;
        return;
    }
    ksmall(root->right,k,count);
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

    int count=0;
    ksmall(root,0,count);

    return 0;
}