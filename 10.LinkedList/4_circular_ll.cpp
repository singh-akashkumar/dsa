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

    cout<<head->data<<"  ";
    node *curr=head->next;
    while(curr!=head)
    {
        cout<<curr->data<<"  ";
        curr=curr->next;
    }
}

node *insert_begin_naive(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
        temp->next=temp;
    else
    {
        temp->next=head;
        node *curr=head;
        while(curr->next!=head)
            curr=curr->next;
        
        curr->next=temp;
    }
    return temp;
}

node *insert_end_naive(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        node *curr=head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=temp;
        temp->next=head;
        return head;
    }
}

node *insert_begin_eff(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;

        int t=temp->data;
        temp->data=head->data;
        head->data=t;

        return head;
    }
}

node *insert_end_eff(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;

        int t=temp->data;
        temp->data=head->data;
        head->data=t;

        return temp;
    }
}

node *delete_head_naive(node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    
    curr->next=head->next;
    delete(head);
    return curr->next;
}

node *delete_head_eff(node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    head->data=head->next->data;
    node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}

node *delete_kth(node *head,int k)
{
    if(head==NULL)
        return NULL;
    if(k==1)
        return delete_head_eff(head);
    
    node *curr=head;
    for(int i=0;i<k-2;i++)
        curr=curr->next;
    
    node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}

int main()
{
    //node *head=NULL;
    node *head=new node(10);
    //head->next=head;
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=head;

    print(head);
    cout<<endl;

    head=insert_begin_naive(head,50);
    print(head);
    cout<<endl;

    head=insert_end_naive(head,60);
    print(head);
    cout<<endl;

    head=insert_begin_eff(head,70);
    print(head);
    cout<<endl;

    head=insert_end_eff(head,80);
    print(head);
    cout<<endl;

    head=delete_head_naive(head);
    print(head);
    cout<<endl;

    head=delete_head_eff(head);
    print(head);
    cout<<endl;

    head=delete_kth(head,4);
    print(head);
    cout<<endl;

    return 0;
}