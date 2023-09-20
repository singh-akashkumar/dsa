#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str,int i,int j)
{
    while(i<j)
    {
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int min_parts(string str,int i,int j)
{
    if(isPalindrome(str,i,j))
        return 0;
    
    int res=INT_MAX;
    for(int k=i;k<j;k++)
        res=min(res, 1 + min_parts(str,i,k) + min_parts(str,k+1,j));
    
    return res;
}

int main()
{
    string str="aaaaaa";
    cout<<min_parts(str,0,str.length()-1);

    return 0;
}