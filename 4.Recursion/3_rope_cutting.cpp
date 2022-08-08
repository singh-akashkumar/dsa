#include<iostream>
using namespace std;

int rope(int n,int a,int b,int c)
{
    if(n==0)
        return 0;
    if(n<0)
        return -1;
    
    int res=max(rope(n-a,a,b,c),
                max(rope(n-b,a,b,c),
                    rope(n-c,a,b,c)));
    
    if(res==-1)
        return -1;
    
    return res+1;
}

int main()
{
    int n=5,a=5,b=2,c=1;
    cout<<rope(n,a,b,c);

    return  0;
}