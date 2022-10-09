#include<iostream>
#include<vector>
using namespace std;

// Advantages - Number of rows can also be Dynamic
//Other points same as Array of Vectors
int main()
{
    int m=3,n=2;
    vector<vector<int>> arr;

    for(int i=0;i<m;i++)
    {
        vector<int> v;
        for(int j=0;j<n;j++)
            v.push_back(40);
        arr.push_back(v);
    }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<"  ";

    return 0;
}