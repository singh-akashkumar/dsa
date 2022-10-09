#include<iostream>
using namespace std;

void freq(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=0;j<i;j++)
        {
            if(arr[j]==arr[i])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
            continue;
        
        int fre=1;
        for(int j=i+1;j<n;j++)
            if(arr[j]==arr[i])
                fre++;
        cout<<arr[i]<<"  "<<fre<<endl;
    }
}

int main()
{
    int arr[]={10,13,10,17,12,13,14,20,12,18,17};
    int n=sizeof(arr)/sizeof(arr[0]);

    freq(arr,n);

    return 0;
}