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

void inorder(node *root,vector<int> &v)
{
    if(root==NULL)
        return;
    inorder(root->left,v);
    v.push_back(root->key);
    inorder(root->right,v);
}

bool pair_sum(node *root,int sum)
{
    vector<int> v;
    inorder(root,v);
    int i=0,j=v.size()-1;
    //cout<<i<<"  "<<j;
    // for(auto x:v)
    //     cout<<x<<"  ";
    // cout<<endl;
    while(i<j)
    {
        if(v[i]+v[j]==sum)
            return true;
        else if(v[i]+v[j]>sum)
            j--;
        else if(v[i]+v[j]<sum)
            i++;
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

    cout<<pair_sum(root,86);

    return 0;
}