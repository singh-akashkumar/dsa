#include<bits/stdc++.h>
using namespace std;

// first generate all permutations and then check for condition that they shouldn't contain substring AB
// O(n! * n) time
void permute(string str,int start,int end)
{
    if(start==end)
    {
        if(str.find("AB")==string::npos)
            cout<<str<<endl;
        return;
    }
    else
    {
        for(int i=start;i<=end;i++)
        {
            swap(str[i],str[start]);
            permute(str,start+1,end);
            swap(str[i],str[start]);
        }
    }
}

int main()
{
    string str="ABC";

    permute(str,0,str.length()-1);

    return 0;
}