#include<bits/stdc++.h>
using namespace std;

bool is_safe(string str,int start,int end,int i)
{
    if(start!=0 && str[start-1]=='A' && str[i]=='B')
        return false;
    if(end==start+1 && str[i]=='A' && str[start]=='B')
        return false;
    return true;
}

void permute(string str,int start,int end)
{
    if(start==end)
    {
        cout<<str<<endl;
        return;
    }
    else
    {
        for(int i=start;i<=end;i++)
        {
            if(is_safe(str,start,end,i))
            {
                swap(str[i],str[start]);
                permute(str,start+1,end);
                swap(str[i],str[start]);
            }
        }
    }
}

int main()
{
    string str="ABC";

    permute(str,0,str.length()-1);

    return 0;
}