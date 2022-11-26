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
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"  ";
        curr=curr->next;
    }
}

// O(1) time
node *insert_begin(node *head,int x)
{
    node *temp=new node(x);
    temp->next=head;
    return temp;
}

// O(n) time
node *insert_end(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
        return temp;

    node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    
    curr->next=temp;
    return head;
}

//O(1) time
node *delete_begin(node *head)
{
    if(head==NULL)
        return NULL;
    node *temp=head->next;
    delete(head);
    return temp;
}

// theta(n) time
node *delete_end(node *head)
{
    if(head==NULL)
        return NULL;
    
    if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }

    node *curr=head;
    while(curr->next->next!=NULL)
        curr=curr->next;
    
    delete(curr->next);
    curr->next=NULL;

    return head;
}

node *insert_pos(node *head,int x,int pos)
{
    node *temp=new node(x);
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    node *curr=head;
    for(int i=0;i<pos-1;i++)
        curr=curr->next;
    
    temp->next=curr->next;
    curr->next=temp;

    return head;
}

// theta(n) time and O(1) aux space
// In arrays, time is theta(log n) using binary search
// but binary search cannot be used in Linked Lists
// Time of linked lists can be reduced by using Skip List
int search_it(node *head,int x)
{
    int i=1;
    node *curr=head;
    while(curr!=NULL)
    {
        if(curr->data==x)
            return i;
        curr=curr->next;
        i++;
    }
    return -1;
}

int search_rec(node *head,int x)
{
    if(head==NULL)
        return -1;
    if(head->data==x)
        return 1;
    else
    {
        int res=search_rec(head->next,x);
        if(res==-1)
            return -1;
        else 
            return res+1;
    }
}

int main()
{
    node *head=NULL;
    head=insert_end(head,70);
    head=insert_begin(head,10);
    head=insert_begin(head,20);
    head=insert_begin(head,30);
    head=insert_begin(head,40);

    head=insert_end(head,50);
    head=insert_end(head,60);

    head=delete_begin(head);
    head=delete_begin(head);

    head=delete_end(head);

    head=insert_pos(head,100,4);

    print(head);

    cout<<endl;
    cout<<search_it(head,50);

    cout<<endl;
    cout<<search_rec(head,60);

    return 0;
}