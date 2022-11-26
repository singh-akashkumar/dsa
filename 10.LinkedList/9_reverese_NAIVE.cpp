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

node *reverse(node *head)
{
    vector<int> v;
    for(node *curr=head;curr!=NULL;curr=curr->next)
        v.push_back(curr->data);
    
    for(node *curr=head;curr!=NULL;curr=curr->next)
    {
        curr->data=v.back();
        v.pop_back();
    }
    return head;
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
    head=reverse(head);
    print(head);

    return 0;
}