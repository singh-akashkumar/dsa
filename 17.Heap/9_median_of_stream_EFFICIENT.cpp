#include<bits/stdc++.h>
using namespace std;

void median_stream(int arr[],int n)
{
    priority_queue<int> s;      // max heap for smaller half elements
    priority_queue<int,vector<int>,greater<int>> g;  // min heap for greater half elements;

    s.push(arr[0]);
    cout<<arr[0]<<"  ";

    for(int i=1;i<n;i++)
    {
        int x=arr[i];
        if(s.size()>g.size())
        {
            if(x<s.top())
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
            
            cout<<(s.top()+g.top())/2.0<<"  ";
        }
        else
        {
            if(x<=s.top())
                s.push(x);
            else
            {
                g.push(x);
                s.push(g.top());
                g.pop();
            }

            cout<<s.top()<<"  ";
        }
    }
}

int main()
{
    int arr[]={25,7,10,15,20};
    int n=sizeof(arr)/sizeof(arr[0]);

    median_stream(arr,n);
    
    return 0;
}