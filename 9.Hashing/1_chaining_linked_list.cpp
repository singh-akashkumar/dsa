#include<bits/stdc++.h>
using namespace std;

struct myhash
{
    int bucket;
    list<int> *table;// pointer of list datatype. list is class in C++ used to implement Doubly Linked List

    myhash(int b)
    {
        bucket=b;
        table=new list<int>[b];
    }

    void insert(int key)
    {
        int i=key%bucket;
        table[i].push_back(key);
    }
    void del(int key)
    {
        int i=key%bucket;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i=key%bucket;
        for(auto x:table[i])
            if(x==key)
                return true;
        
        return false;
    }
};

int main()
{
    myhash h(7);

    h.insert(10);
    h.insert(15);
    h.insert(20);
    h.insert(14);
    h.insert(70);

    cout<<h.search(70)<<endl;

    h.del(70);

    cout<<h.search(70)<<endl;

    return 0;
}