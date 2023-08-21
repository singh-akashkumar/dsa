#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s1;
    set<int,greater<int>> s2;
    s1.insert(10);
    s1.insert(3);
    s1.insert(16);
    s1.insert(10);  //duplicates ignored
    s1.insert(3);   //duplicates ignored
    s1.insert(12);

    for(int x:s1)
        cout<<x<<"  ";
    cout<<endl;

    s2.insert(10);
    s2.insert(3);
    s2.insert(16);
    s2.insert(12);

    for(int x:s2)
        cout<<x<<"  ";
    cout<<endl;

    for(auto it=s1.begin();it!=s1.end();it++)
        cout<<*it<<"  ";
    cout<<endl;

    for(auto it=s2.rbegin();it!=s2.rend();it++)
        cout<<*it<<"  ";
    cout<<endl;

    auto it=s1.find(16);
    cout<<*it<<endl;

    cout<<s1.count(6)<<endl;

    // s1.clear();
    // cout<<s1.size()<<endl;

    it=s2.find(10);
    s2.erase(it,s2.end());
    for(int x:s2)
        cout<<x<<"  ";
    cout<<endl;

    it=s1.lower_bound(12);
    if(it!=s1.end())
        cout<<*it<<endl;
    else
        cout<<"No equal or greater value"<<endl;
    
    it=s1.upper_bound(10);
    if(it!=s1.end())
        cout<<*it<<endl;
    else
        cout<<"No greater value"<<endl;

    return 0;
}