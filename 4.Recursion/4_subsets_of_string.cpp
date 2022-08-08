#include<iostream>
using namespace std;

void subsets_string(string &str,string curr="",int i=0)
{
    if(i==str.size())
    {
        cout<<curr<<endl;
        return;
    }
    subsets_string(str,curr,i+1);
    subsets_string(str,curr+str[i],i+1);
}

int main()
{
    string str="abc";
    subsets_string(str);

    return 0;
}