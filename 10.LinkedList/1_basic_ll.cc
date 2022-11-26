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

// O(n) time and O(1) Aux Space
void print(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"  ";
        curr=curr->next;
    }
}

// O(n) time and O(n) Aux Space
void recprint(node *head)
{
    if(head==NULL)
        return;
    cout<<head->data<<"  ";
    recprint(head->next);
}

int main()
{
    node *head=new node(10);
    // head->next=new node(20);
    // head->next->next=new node(30);
    node *temp1=new node(20);
    node *temp2=new node(30);

    head->next=temp1;
    temp1->next=temp2;

    print(head);
    cout<<endl;
    recprint(head);

    return 0;
}