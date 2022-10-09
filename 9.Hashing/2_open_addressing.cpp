#include<iostream>
using namespace std;

// using Linear Probing
// arr[i]==-1 means Empty Slot
// arr[i]==-2 means Deleted Slot
struct myhash
{
    int *arr;       //pointer that contains address of contiguous locations
    int cap,size;

    myhash(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
        for(int i=0;i<cap;i++)
            arr[i]=-1;
    }

    int hash(int key)
    {
        return key%cap;
    }

    bool insert(int key)
    {
        if(size==cap)
            return false;

        int i=hash(key);
        
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
            i=(i+1)%cap;
        
        if(arr[i]==key)     //key already present
            return false;
        else
        {
            arr[i]=key;
            size++;
            return true;
        }
    }
    bool remove(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
            {
                arr[i]=-2;
                //size--;
                return true;
            }
            i=(i+1)%cap;

            if(i==h)
                return false;
        }
        return false;
    }
    bool search(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
                return true;
            
            i=(i+1)%cap;

            if(i==h)
                return false;
        }
        return false;
    }
};

int main()
{
    myhash h(7);

    h.insert(49);
    h.insert(56);
    h.insert(72);

    cout<<h.search(56)<<endl;

    h.remove(56);

    cout<<h.search(56)<<endl;

    return 0;
}