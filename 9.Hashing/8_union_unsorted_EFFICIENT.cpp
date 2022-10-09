#include<iostream>
#include<unordered_set>
using namespace std;

int uni(int a[],int b[],int m,int n)
{
    unordered_set<int> s;
    for(int i=0;i<m;i++)
        s.insert(a[i]);
    for(int j=0;j<n;j++)
        s.insert(b[j]);
    
    return s.size();
}

int main()
{
    int a[]={15,20,5,15};
    int b[]={15,15,15,20,10};
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);

    cout<<uni(a,b,m,n);

    return 0;
}