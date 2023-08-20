#include<iostream>
using namespace std;

// Time is O(n^2)
void leader(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag=true;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>=arr[i])
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
            cout<<arr[i]<<"  ";
    }
}

int main()
{
    int arr[]={7,10,4,3,10,6,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    leader(arr,n);

    return 0;
}