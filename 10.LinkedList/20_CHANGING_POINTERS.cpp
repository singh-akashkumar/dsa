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

node *pairwise_swap(node *head)
{
    node *curr=head;
    node *prev=NULL;
    node *next;
    int count=0;
    while(curr!=NULL && count<2)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    {
        node *rest_head=pairwise_swap(next);
        head->next=rest_head;
    }
    return prev;
}

int main()
{
    //node *head=NULL;
    node *head=new node(17);
    // head->next=new node(11);
    // head->next->next=new node(35);
    // head->next->next->next=new node(21);
    // head->next->next->next->next=new node(67);
    // head->next->next->next->next->next=new node(100);

    print(head);
    cout<<endl;
    head=pairwise_swap(head);
    print(head);

    return 0;
}