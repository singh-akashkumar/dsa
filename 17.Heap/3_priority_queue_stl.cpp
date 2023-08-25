#include<iostream>
#include<queue>
using namespace std;

// pq ia always implemented using the heap data structure
// pq in c++ stl doesn't support decrease_key
int main()
{
    priority_queue<int> pq;     // by default it is Max Heap
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;
    while(!pq.empty())
    {
        cout<<pq.top()<<"  ";
        pq.pop();
    }
    cout<<endl;

    priority_queue<int,vector<int>,greater<int>> pq2;
    pq2.push(10);
    pq2.push(15);
    pq2.push(5);
    cout<<pq2.size()<<endl;
    cout<<pq2.top()<<endl;
    while(!pq2.empty())
    {
        cout<<pq2.top()<<"  ";
        pq2.pop();
    }
    cout<<endl;

    int arr[]={10,5,15};
    priority_queue<int> pq3(arr,arr+3); // better - O(n) time
    while(!pq3.empty())
    {
        cout<<pq3.top()<<"  ";
        pq3.pop();
    }
    cout<<endl;

    return 0;
}