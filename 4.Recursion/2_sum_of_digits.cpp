#include<iostream>
using namespace std;

int sum(int n)
{
    if(n<=9)
        return n;
    return (n%10)+sum(n/10);
}

int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;
    cout<<"The sum of digits of "<<n<<" is: "<<sum(n);
    return 0;
}