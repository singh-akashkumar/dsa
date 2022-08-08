#include<iostream>
using namespace std;

bool palindrome(string &str,int start,int end)
{
    if(start>=end)
        return true;
    return (str[start]==str[end] && palindrome(str,start+1,end-1));
}

int main()
{
    string str="malayalam";
    cout<<palindrome(str,0,str.size()-1);
    return 0;
}