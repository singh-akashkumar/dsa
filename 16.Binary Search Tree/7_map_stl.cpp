#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int,int> m;
    m.insert({19,345});
    m.insert({13,600});
    m.insert({10,200});
    m.insert({23,1000});
    m.insert({10,100});     //ignored
    m[10]=100;           //updated
    m.at(10)=678;       //updated
    cout<<m.size()<<endl;
    cout<<m[31]<<endl;     // pair with key 31 and default value created
    cout<<m.size()<<endl;
    //cout<<m.at(33);         //throuws out of range exception
    //cout<<m.size()<<endl;

    // find func accepts key as the argument
    for(auto it=m.find(13);it!=m.end();it++)
        cout<<(*it).first<<"  "<<(*it).second<<endl;

    return 0;
}