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

int no_of_elements(node *head)
{
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    if(slow!=fast)      // i.e. loop terminated bcz of while condition
        return 0;
    
    int count=1;
    node *temp=fast->next;
    while(temp!=fast)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

int main()
{
    //node *head=NULL;
    node *head=new node(20);
    //head->next=head;
    head->next=new node(10);
    head->next->next=new node(15);
    head->next->next->next=new node(35);
    head->next->next->next->next=new node(65);
    head->next->next->next->next->next=head;

    //print(head);      not possible to print bcz of loop - infinite condition
    //cout<<endl;
    cout<<no_of_elements(head);
    //print(head);

    return 0;
}