#include<iostream>
#include<vector>
using namespace std;

//Advantages - Individual rows can be of Dynamic Size
//             Easy to pass to a function
//Disadvantages - not cache friendly 
int main()
{
    int m=3,n=2;
    vector<int> arr[m];

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            arr[i].push_back(30);
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<"  ";

    return 0;
}