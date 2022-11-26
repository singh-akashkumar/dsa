#include<bits/stdc++.h>
using namespace std;

struct node
{   
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
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

node *k_rev(node *head,int k)
{
    int count=0;
    node *curr=head;
    node *prev=NULL;
    node *next=NULL;
    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    {
        node *rest_head=k_rev(next,k);
        head->next=rest_head;
    }
    return prev;
}

int main()
{
    //node *head=NULL;
    node *head=new node(20);
    head->next=new node(10);
    head->next->next=new node(15);
    head->next->next->next=new node(35);
    head->next->next->next->next=new node(65);
    //head->next->next->next->next->next=new node(65);

    print(head);
    cout<<endl;
    head=k_rev(head,2);
    //cout<<"test";
    print(head);
    //cout<<"test2";

    return 0;
}