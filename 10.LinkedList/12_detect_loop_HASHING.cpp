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

// O(n) time and O(n) Aux Space
bool loop(node *head)
{
    unordered_set<node *> s;
    for(node *curr=head;curr!=NULL;curr=curr->next)
    {
        if(s.find(curr)!=s.end())
            return true;
        s.insert(curr);
    }
    return false;
}

int main()
{
    //node *head=NULL;
    node *head=new node(20);
    head->next=new node(10);
    head->next->next=new node(15);
    head->next->next->next=new node(35);
    head->next->next->next->next=new node(65);
    head->next->next->next->next->next=head->next;

    cout<<loop(head);

    return 0;
}