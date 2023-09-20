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

int min_parts(string str)
{
    int n=str.length();
    int dp[n][n];

    for(int i=0;i<n;i++)
        dp[i][i]=0;
    
    for(int gap=1;gap<n;gap++)
    {
        for(int i=0;i+gap<n;i++)
        {
            int j=i+gap;
            if(isPalindrome(str,i,j))
                dp[i][j]=0;
            else
            {
                for(int k=i;k<j;k++)
                    dp[i][j]=min(dp[i][j], 1 + dp[i][k] + dp[k+1][j]);
            }
        }
    }
    return dp[0][n-1];
}

int main()
{
    string str="geek";
    cout<<min_parts(str);

    return 0;
}