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

void middle(node *head)
{
    if(head==NULL)
        return;
    
    node *fast=head;
    node *slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}

int main()
{
    //node *head=NULL;
    node *head=new node(20);
    head->next=new node(10);
    head->next->next=new node(15);
    head->next->next->next=new node(35);
    head->next->next->next->next=new node(35);
    head->next->next->next->next->next=new node(65);

    print(head);
    cout<<endl;
    middle(head);

    return 0;
}