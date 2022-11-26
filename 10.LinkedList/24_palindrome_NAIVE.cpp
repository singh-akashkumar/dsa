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

// O(n) time and O(n) Aux Space
bool palindrome(node *head)
{
    stack<char> s;
    for(node *curr=head;curr!=NULL;curr=curr->next)
        s.push(curr->data);
    
    for(node *curr=head;curr!=NULL;curr=curr->next)
    {
        if(s.top()!=curr->data)
            return false;
        s.pop();
    }
    return true;
}

int main()
{
    node *h1=new node('m');
    h1->next=new node('a');
    h1->next->next=new node('m');

    print(h1);
    cout<<endl;
    cout<<palindrome(h1);

    return 0;
}