#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *next;
    node(char x)
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

node *reverse_list(node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
    node *curr=head;
    node *next;
    node *prev=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

// O(n) time and O(1) Aux Space
bool palindrome(node *head)
{
    if(head==NULL)
        return true;
    node *slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    node *rev=reverse_list(slow->next);

    node *curr=head;
    while(rev!=NULL)
    {
        if(rev->data!=curr->data)
        {
            //rev=reverse_list(slow->next);
            return false;
        }

        rev=rev->next;
        curr=curr->next;
    }
    //rev=reverse_list(slow->next);
    return true;
}

int main()
{
    node *h1=new node('a');
    h1->next=new node('b');
    h1->next->next=new node('a');
    h1->next->next->next=new node('a');

    print(h1);
    cout<<endl;
    cout<<palindrome(h1);

    return 0;
}