#include<iostream>
using namespace std;

//Time is theta(n).
//DISCLAIMER - LEADERS ARE PRINTED IN REVERSE ORDER.
//TO PRINT IN SAME ORDER, STORE THEM IN AN ARRAY, REVERSE AND PRINT THE ARRAY. IN THAT CASE, AUX SPACE=THETA(n)
void leader(int arr[],int n)
{
    int curr_lead=arr[n-1];
    cout<<curr_lead<<"  ";

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>curr_lead)
        {
            curr_lead=arr[i];
            cout<<curr_lead<<"  ";
        }
    }
}

int main()
{
    int arr[]={7,10,4,3,10,6,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    leader(arr,n);

    return 0;
}