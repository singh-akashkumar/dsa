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

// INPLACE merge
// O(m+n) time and O(1) Aux Space
node *merge(node *h1,node *h2)
{
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;

    node *head,*tail;
    if(h1->data<=h2->data)
    {
        head=h1;
        tail=h1;
        h1=h1->next;
    }
    else
    {
        head=h2;
        tail=h2;
        h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data<=h2->data)
        {
            tail->next=h1;
            tail=h1;
            h1=h1->next;
        }
        else
        {
            tail->next=h2;
            tail=h2;
            h2=h2->next;
        }
    }
    if(h1==NULL)
        tail->next=h2;
    if(h2==NULL)
        tail->next=h1;
    return head;
}

int main()
{
    node *h1=new node(5);
    h1->next=new node(12);
    h1->next->next=new node(17);

    node *h2=new node(7);
    h2->next=new node(10);
    h2->next->next=new node(14);
    h2->next->next->next=new node(15);

    print(h1);
    cout<<endl;
    print(h2);
    cout<<endl;
    node *temp=merge(h1,h2);
    print(temp);

    return 0;
}