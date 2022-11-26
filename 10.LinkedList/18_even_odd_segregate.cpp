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

// es=even start, ee=even end, os=odd start, oe=odd end;
// 4 pointers are maintained
// two sublists inside one list are maintained and then connected at last
node *segregate(node *head)
{
    node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
    for(node *curr=head;curr!=NULL;curr=curr->next)
    {
        if(curr->data%2==0)
        {
            if(es==NULL)
                es=ee=curr;
            else
            {
                ee->next=curr;
                ee=curr;
            }
        }
        else
        {
            if(os==NULL)
                os=oe=curr;
            else
            {
                oe->next=curr;
                oe=curr;
            }
        }
    }
    if(os==NULL || es==NULL)
        return head;
    else
    {
        ee->next=os;
        oe->next=NULL;
        return es;
    }
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
    head=segregate(head);
    print(head);

    return 0;
}