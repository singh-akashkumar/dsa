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
    while(curr!=NULL && curr->next!=NULL)
    {
        int temp;
        temp=curr->data;
        curr->data=curr->next->data;
        curr->next->data=temp;

        curr=curr->next->next;
    }
    return head;
}

int main()
{
    //node *head=NULL;
    node *head=new node(17);
    head->next=new node(11);
    head->next->next=new node(35);
    head->next->next->next=new node(21);
    head->next->next->next->next=new node(67);

    print(head);
    cout<<endl;
    head=pairwise_swap(head);
    print(head);

    return 0;
}