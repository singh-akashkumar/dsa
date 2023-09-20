#include<bits/stdc++.h>
using namespace std;

int soln(int arr[],int i,int j,int sum)
{
    if(j==i+1)
        return max(arr[i],arr[j]);
    
    return max(sum-soln(arr,i+1,j,sum-arr[i]),sum-soln(arr,i,j-1,sum-arr[j]));
    // sum-soln(...) bcz at the end soln returns max value of opponent
}

int mainsoln(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    
    return soln(arr,0,n-1,sum);
}

// even no of coins aranged in a row and 2 players are playing a game
// both players pick the coin on their turn, i am the first player
// player can pick only one of 2 corner coins
// i have to pick coins to get maximum possible value
// opponent is as smart as i am
// solving this prob becomes easier when we change the approach
// instead of getting max value, we should aim that we have to NOT lose the game
// but this does not always give max value, though it ensures that we never lose

int main()
{
    int arr[]={2,3,15,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<mainsoln(arr,n);

    return 0;
}