#include<bits/stdc++.h>
using namespace std;

int common_span(int a[],int b[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int sum1=0,sum2=0;
        for(int j=i;j<n;j++)
        {
            sum1+=a[j];
            sum2+=b[j];
            if(sum1==sum2)
                res=max(res,j-i+1);
        }
    }
    return res;
}

int main()
{
    int a[]={0,1,0,1,1,1,1};
    int b[]={1,1,1,1,1,0,1};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<common_span(a,b,n);

    return 0;
}