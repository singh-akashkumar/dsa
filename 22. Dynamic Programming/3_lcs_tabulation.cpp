#include<bits/stdc++.h>
using namespace std;

// theta(mn) time
int lcs(string &s1,string &s2)
{
    int m=s1.length();
    int n=s2.length();

    int tab[m+1][n+1];
    for(int i=0;i<=m;i++)
        tab[i][0]=0;
    
    for(int j=0;j<=n;j++)
        tab[0][j]=0;
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                tab[i][j]=1+tab[i-1][j-1];
            else
                tab[i][j]=max(tab[i][j-1],tab[i-1][j]);
        }
    }

    return tab[m][n];
}

int main()
{
    string s1="AXYZ";
    string s2="BAZ";

    cout<<lcs(s1,s2);

    return 0;
}