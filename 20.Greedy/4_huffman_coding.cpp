#include<bits/stdc++.h>
using namespace std;

struct node
{
    char ch;
    int freq;
    node *left,*right;

    node(char c,int f,node* l=NULL,node* r=NULL)
    {
        ch=c;
        freq=f;
        left=l;
        right=r;
    }
};

struct mycomp
{
    bool operator()(node* l,node* r)
    {
        return l->freq>r->freq;
    }
};

void print_codes(node *root,string code)
{
    if(root->ch!='$')
    {
        cout<<root->ch<<"  "<<code<<endl;
        return;
    }
    print_codes(root->left,code+"0");
    print_codes(root->right,code+"1");
}

// O(n log n) time and theta(n) Aux Space
void huffman_coding(char arr[],int freq[],int n)
{
    priority_queue<node*,vector<node*>,mycomp> h;

    for(int i=0;i<n;i++)
        h.push(new node(arr[i],freq[i]));

    while(h.size()>1)
    {
        node *l=h.top();    h.pop();
        node *r=h.top();    h.pop();
        
        node *n=new node('$',l->freq+r->freq,l,r);
        h.push(n);
    }

    print_codes(h.top(),"");        // theta(n) time
}

int main()
{
    char arr[]={'a','d','e','f'};
    int freq[]={30,40,80,60};
    int n=sizeof(freq)/sizeof(freq[0]);

    huffman_coding(arr,freq,n);

    return 0;
}