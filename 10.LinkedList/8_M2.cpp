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

void nend(node *head,int n)
{
    if(head==NULL)
        return;
    
    node *first=head,*second=head;
    for(int i=0;i<n;i++)
    {
        if(first==NULL)
            return;
        first=first->next;
    }
    while(first!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    cout<<second->data<<endl;
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
    nend(head,5);

    return 0;
}