#include<iostream>
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

void print(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"  ";
        curr=curr->next;
    }
}

node *insert_begin(node *head,int x)
{
    node *temp=new node(x);
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
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
    temp->prev=curr;

    return head;
}

node *reverse(node *head)
{
    if(head==NULL || head->next==NULL)  // if no node or only one node
        return head;
    
    node *temp=NULL,*curr=head;
    while(curr!=NULL)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    return temp->prev;
}

// theta(1) time
node *delete_begin(node *head)
{
    if(head==NULL)
        return head;
    if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
    return head;
}

// theta(n) time - can be reduced to theta(1) using tail pointer
//but there are also disadvantages of the tail pointers
// all the insertion operations have to maintain tail pointers
node *delete_end(node *head)
{
    if(head==NULL)
        return head;
    if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    node *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
   
    delete(temp->next);
    temp->next=NULL;
    return head;
}

int main()
{
    node *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);

    head->next=temp1;
    temp1->next=temp2;
    temp1->prev=head;
    temp2->prev=temp1;

    print(head);
    cout<<endl;

    head=insert_begin(head,100);
    print(head);
    cout<<endl;

    head=reverse(head);
    print(head);
    cout<<endl;

    head=delete_begin(head);
    print(head);
    cout<<endl;

    head=delete_end(head);
    print(head);
    cout<<endl;

    head=insert_end(head,200);
    print(head);

    return 0;
}