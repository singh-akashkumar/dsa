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

int getcount(node *head)
{
    node *curr=head;
    int count=0;
    while(curr!=NULL)
    {
        curr=curr->next;
        count++;
    }
    return count;
}

int intersection(int d,node *h1,node *h2)
{
    node *curr1=h1,*curr2=h2;
    for(int i=0;i<d;i++)
    {
        if(curr1==NULL)
            return -1;
        curr1=curr1->next;
    }
    
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1==curr2)
            return curr1->data;
        
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}

// O(m+n) time and O(1) Aux Space
int int_pnt(node *h1,node *h2)
{
    int c1=getcount(h1);
    int c2=getcount(h2);
    if(c1>c2)
    {
        int d=c1-c2;
        return intersection(d,h1,h2);
    }
    else
    {
        int d=c2-c1;
        return intersection(d,h2,h1);
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

    node *h2=new node(100);
    h2->next=new node(120);
    h2->next->next=head->next;

    print(head);
    cout<<endl;
    print(h2);
    cout<<endl;
    cout<<int_pnt(head,h2);

    return 0;
}