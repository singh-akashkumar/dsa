#include<iostream>
using namespace std;

void nbonacci(int m,int n)
{
    int nbon[m]={0};
    nbon[n-1]=1;
    nbon[n]=1;

    for(int i=n+1;i<m;i++)
        nbon[i]=2*nbon[i-1]-nbon[i-n-1];
    
    for(int i=0;i<m;i++)
        cout<<nbon[i]<<"  ";
}

int main()
{
    int m=8;
    int n=3;

    nbonacci(m,n);

    return 0;
}