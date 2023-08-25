#include<bits/stdc++.h>
using namespace std;

void max_heapify(int arr[],int n,int i)
{
    int largest=i;
    int lt=2*i+1;
    int rt=2*i+2;

    if(lt<n && arr[lt]>arr[largest])
        largest=lt;
    if(rt<n && arr[rt]>arr[largest])
        largest=rt;
    
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        max_heapify(arr,n,largest);
    }
}

void build_heap(int arr[],int n)
{
    for(int i=(n-2)/2;i>=0;i--)
        max_heapify(arr,n,i);
}

void heap_sort(int arr[],int n)
{
    build_heap(arr,n);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[i],arr[0]);
        max_heapify(arr,i,0);
    }
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
}

int main()
{
    int arr[]={3,10,7,6,23,19,14};
    int n=sizeof(arr)/sizeof(arr[0]);

    heap_sort(arr,n);

    cout<<"The sorted array is: ";
    print(arr,n);

    return 0;
}