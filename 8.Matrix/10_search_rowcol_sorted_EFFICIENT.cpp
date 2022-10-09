#include<iostream>
using namespace std;
const int r=4,c=5;

//O(r+c) time
void search(int mat[r][c],int x)
{
    int i=0,j=c-1;
    while(i<=r-1 && j>=0)
    {
        if(mat[i][j]==x)
        {
            cout<<"Found at ("<<i<<","<<j<<")";
            return;
        }
        else if(mat[i][j]>x)
            j--;
        else 
            i++;
    }
    cout<<"Not Found!!!";
}

int main()
{
    int mat[r][c]={10,15,20,25,30,13,17,23,28,31,15,18,24,29,32,40,44,48,50,52};
    int x=26;

    search(mat,x);

    return 0;
}