#include<iostream>
using namespace std;

void freq(int arr[],int n)
{
    int i=1,fre=1;
    while(i<n)
    {
        while(i<n && arr[i-1]==arr[i])
        {
            fre++;
            i++;
        }
        cout<<arr[i-1]<<"   "<<fre<<endl;
        i++;
        fre=1;
    }
    if(n==1 || arr[n-1]!=arr[n-2])              //if last element is of frequency 1
    {
        cout<<arr[n-1]<<"   "<<"1"<<endl;
    }
}

int main()
{
    int arr[]={10,10,12,34,34,34,65,65,65,65,72};
    int n=sizeof(arr)/sizeof(arr[0]);

    freq(arr,n);

    return 0;
}