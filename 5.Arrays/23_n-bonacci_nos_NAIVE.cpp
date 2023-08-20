#include<iostream>
using namespace std;

void nbonacci(int m,int n)
{
    int nbon[m]={0};
    nbon[n-1]=1;
    
    for(int i=n;i<m;i++)
    {
        for(int j=i-n;j<i;j++)
            nbon[i]=nbon[i]+nbon[j];
    }

    for(int i=0;i<m;i++)
        cout<<nbon[i]<<"  ";
}

int main()
{
    int m=9;
    int n=4;

    nbonacci(m,n);

    return 0;
}