#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string,int> m;
    m["akash"]=27;
    m["aditya"]=11;
    m.insert({"juit",100});
    m.insert({"akash",200});    //ignored
    m["akash"]=200;             //overrides

    if(m.find("jaypee")!=m.end())
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    // for(auto x:m)
    //     cout<<x.first<<"  "<<x.second<<endl;
    
    for(auto i=m.begin();i!=m.end();i++)
        cout<<(i->first)<<" "<<(i->second)<<endl;

    if(m.count("akash"))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    
    cout<<m.size()<<endl;
    m.erase("akash");
    m.erase(m.begin());
    cout<<m.size();

    return 0;
}