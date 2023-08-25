#include<bits/stdc++.h>
using namespace std;

class minheap
{
    int *arr;
    int size,cap;

    public:

    minheap(int c)
    {
        size=0;
        cap=c;
        arr=new int[c];
    }

    int left(int i)  {return (2*i + 1);}
    int right(int i)  {return (2*i + 2);}
    int parent(int i)  {return (i-1)/2;}

    void insert(int x)
    {
        size++;
        arr[size-1]=x;
        for(int i=size-1; i!=0 && arr[parent(i)]>arr[i];)
        {
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    // O(log n) time and O(log n) Aux Space
    void minheapify(int i)
    {
        int lt=left(i);
        int rt=right(i);
        int smallest=i;

        if(lt<size && arr[lt]<arr[smallest])
            smallest=lt;
        if(rt<size && arr[rt]<arr[smallest])
            smallest=rt;
        
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            minheapify(smallest);
        }
    }

    //O(log n) Time and Aux Space depends on minheapify is recursive or iterative 
    int extractmin()
    {
        if(size==0)
            return INT_MAX;
        if(size==0)
        {
            size--;
            return arr[0];
        }
        int res=arr[0];
        swap(arr[0],arr[size-1]);
        size--;
        minheapify(0);
        return res;
    }

    // O(log n) time
    void decrease_key(int i,int x)
    {
        arr[i]=x;
        while(i!=0 && arr[parent(i)]<arr[i])
        {
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    // O(log n) time
    void delete_key(int i)
    {
        decrease_key(i,INT_MIN);
        extractmin();
    }

    // O(n) time 
    void build_heap()
    {
        for(int i=(size-2)/2;i>=0;i--)
            minheapify(i);
    }
};

int main()
{
    minheap h(10);
    h.insert(20);
    h.insert(5);
    h.insert(13);
    h.insert(34);
    h.insert(9);
    cout<<h.extractmin()<<endl;
    h.decrease_key(3,8);
    //cout<<h.extractmin()<<endl;
    h.delete_key(2);
    cout<<h.extractmin()<<endl;
    cout<<h.extractmin()<<endl;
    
    return 0;
}