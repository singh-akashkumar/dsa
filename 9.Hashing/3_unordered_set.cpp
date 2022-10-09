#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(15);
    s.insert(20);
    s.insert(5);           // duplicate element will be ignored

    for(auto i=s.begin();i!=s.end();i++)
        cout<<(*i)<<"  ";
    
    cout<<endl;

    if(s.find(25)==s.end())
        cout<<"Not Found"<<endl;
    else
        cout<<"Found "<<*(s.find(25))<<endl;

    if(s.count(15))     // count() is a substitute of find(). Returns 1 if element present, else 0.
        cout<<"Found"<<endl;            // only 1 and 0 bcz duplicate elements are not allowed
    else
        cout<<"Not Found"<<endl;

    cout<<s.size()<<endl;;
    s.erase(15);
    cout<<s.size()<<endl;
    s.erase(s.find(10));
    cout<<s.size()<<endl;
    s.clear();          // or s.erase(s.begin(),s.end())
    cout<<s.size()<<endl;
    cout<<s.empty();
    
    return 0;
}