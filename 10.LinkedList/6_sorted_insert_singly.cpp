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

// theta(pos) time where pos is the position of insertion
node *sorted_insert(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
        return temp;
    
    if(x<head->data)
    {
        temp->next=head;
        return temp;
    }
    node *curr=head;
    while(curr->next!=NULL && curr->next->data<=x)
        curr=curr->next;
    
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);

    print(head);
    cout<<endl;
    head=sorted_insert(head,25);
    print(head);

    return 0;
}