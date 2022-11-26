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

// O(m+n) time and O(m) Aux Space
void int_pnt(node *h1,node *h2)
{
    unordered_set<node *> s;
    for(node *curr=h1;curr!=NULL;curr=curr->next)
        s.insert(curr);
    
    for(node *curr=h2;curr!=NULL;curr=curr->next)
        if(s.find(curr)!=s.end())
        {
            cout<<curr->data;
            break;
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
    h2->next->next=head->next->next->next;

    print(head);
    cout<<endl;
    print(h2);
    cout<<endl;
    int_pnt(head,h2);

    return 0;
}