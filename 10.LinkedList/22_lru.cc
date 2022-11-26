#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    int value;
    node *prev;
    node *next;

    node(int k,int v)
    {
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};

// O(1) time and O(1) Aux Space
class LRU
{
    public:
    unordered_map<int,node *> m;
    node *head,*tail;
    int capacity,count;

    LRU(int c)
    {
        capacity=c;
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
        count=0;
    }

    void delete_node(node *given)
    {
        given->prev->next=given->next;
        given->next->prev=given->prev;
    }

    void add_to_head(node *given)
    {
        given->next=head->next;
        given->next->prev=given;
        given->prev=head;
        head->next=given;
    }

    void get(int key)
    {
        if(m[key]!=NULL)
        {
            node *temp=m[key];
            int result=temp->value;
            delete_node(temp);
            add_to_head(temp);
            cout<<"Got the value "<<result<<" for the key "<<key<<endl;
            //return result;
        }
        else
        {
            cout<<"did not get any value for the key "<<key<<endl;
            //return -1;
        }
    }

    void set(int key,int value)
    {
        cout<<"Going to set the key and value as ("<<key<<","<<value<<")"<<endl;
        if(m[key]!=NULL)
        {
            node *temp=m[key];
            cout<<"Present value is "<<temp->value<<endl;
            temp->value=value;
            delete_node(temp);
            add_to_head(temp);
        }
        else
        {
            node *temp=new node(key,value);
            m[key]=temp;
            if(count<capacity)
            {
                count++;
                add_to_head(temp);
            }
            else
            {
                m.erase(tail->prev->key);
                delete_node(tail->prev);
                add_to_head(temp);
            }
        }
    }
};

int main()
{
    LRU cache(2);

    cache.set(1,10);
    cache.set(2,20);
    cache.get(1);
    cache.set(3,30);
    cache.get(2);
    cache.set(4,40);
    cache.set(3,100);
    cache.get(1);
    cache.get(3);
    cache.get(4);

    return 0;
}