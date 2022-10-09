#include<iostream>
using namespace std;

int intersection(int a[],int b[],int m,int n)
{
    int res=0;
    for(int i=0;i<m;i++)
    {
        bool flag=false;
        for(int k=0;k<i;k++)
        {
            if(a[k]==a[i])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
            continue;
        
        for(int j=0;j<n;j++)
        {
            if(b[j]==a[i])
            {
                res++;
                break;
            }
        }
    }
    return res;
}

int main()
{
    int a[]={10,10,10};
    int b[]={10,10,10};
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);

    cout<<intersection(a,b,m,n);

    return 0;
}