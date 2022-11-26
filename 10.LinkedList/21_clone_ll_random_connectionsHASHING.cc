#include<bits/stdc++.h>
using namespace std;

struct node
{   
    int data;
    node *next;
    node *random;
    node(int x)
    {
        data=x;
        next=NULL;
        random=NULL;
    }
};

void print(node *head)
{
    if(head==NULL)
        return;
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"  ";
        curr=curr->next;
    }
}

//theta(n) time and theta(n) Aux Space
node *clone(node *h1)
{
    unordered_map<node *,node *> m;
    for(node *curr=h1;curr!=NULL;curr=curr->next)
        m[curr]=new node(curr->data);
    
    for(node *curr=h1;curr!=NULL;curr=curr->next)
    {
        m[curr]->next=m[curr->next];
        m[curr]->random=m[curr->random];
    }
    return m[h1];
}

int main()
{
    //node *head=NULL;
    node *head=new node(17);
    head->next=new node(11);
    head->next->next=new node(35);
    head->next->random=head->next->next;
    head->next->next->next=new node(21);
    head->next->next->next->next=new node(67);
    head->next->next->next->next->random=head->next->next->next;
    head->next->next->next->random=head;

    print(head);
    cout<<endl;
    node *h2=clone(head);
    print(h2);

    return 0;
}