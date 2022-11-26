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
    
    int count=0;
    for(node *curr=head;curr!=NULL;curr=curr->next)
        count++;
    
    if(n<=count)
    {
        int n1=count-n+1;
        node *curr=head;
        for(int i=0;i<n1-1;i++)
            curr=curr->next;
        cout<<curr->data<<endl;
    }
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