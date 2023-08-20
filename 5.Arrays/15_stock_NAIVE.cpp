#include<iostream>
using namespace std;

int profit(int arr[],int start,int end)
{
    if(start>=end)
        return 0;

    int maxprofit=0;
    for(int i=start;i<end;i++)
        for(int j=i+1;j<=end;j++)
            if(arr[j]>arr[i])
            {
                int curr_profit=arr[j]-arr[i]+profit(arr,start,i-1)+profit(arr,j+1,end);
                maxprofit=max(maxprofit,curr_profit);
            }
    
    return maxprofit;
}

int main()
{
    int arr[]={1,5,3,1,2,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<profit(arr,0,n-1);

    return 0;
}