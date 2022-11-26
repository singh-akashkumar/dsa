#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;

    node(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};

node *insert_head(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    temp->prev=head->prev;
    temp->next=head;
    head->prev->next=temp;
    head->prev=temp;
    return temp;
}

void print(node *head)
{
    if(head==NULL)
        return;
    
    cout<<head->data<<"  ";
    node *curr=head->next;
    while(curr!=head)
    {
        cout<<curr->data<<"  ";
        curr=curr->next;
    }
}

node *insert_end(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    temp->next=head;
    temp->prev=head->prev;
    head->prev->next=temp;
    head->prev=temp;
    return head;
}

int main()
{
    node *head=NULL;
    head=insert_head(head,10);
    head=insert_head(head,20);
    head=insert_head(head,30);

    head=insert_end(head,40);
    print(head);

    return 0;
}