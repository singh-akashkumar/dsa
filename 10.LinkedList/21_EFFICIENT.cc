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

node *clone(node *h1)
{
    node *curr=h1;
    node *h2;
    while(curr!=NULL)
    {
        node *next=curr->next;
        curr->next=new node(curr->data);
        curr->next->next=next;
        curr=next;
    }
    for(node *curr=h1;curr!=NULL;curr=curr->next->next)
        curr->next->random=(curr->random==NULL)?NULL:curr->random->next;
    
    node *copy=h1->next;
    node *original=h1;
    h2=copy;
    while(original && copy)
    {
        original->next=original->next?original->next->next:NULL;
        copy->next=copy->next?copy->next->next:NULL;
        
        original=original->next;
        copy=copy->next;
    }
    return h2;
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