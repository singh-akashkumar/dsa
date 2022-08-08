#include<iostream>
using namespace std;

int jos(int n,int k)
{
    if(n==1)
        return 0;
    return (jos(n-1,k)+k)%n;
}

// int jos_ind(int n,int k)
// {
//     return jos(n,k)+1;
// }

int main()
{
    cout<<jos(4,2);

    //cout<<jos_ind(n,k);       //if index start from 1

    return 0;
}