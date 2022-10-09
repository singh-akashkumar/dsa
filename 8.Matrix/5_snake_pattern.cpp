#include<iostream>
using namespace std;
const int r=4,c=3;

void snake(int mat[r][c])
{
    for(int i=0;i<r;i++)
    {
        if(i%2==0)
            for(int j=0;j<c;j++)
                cout<<mat[i][j]<<"  ";
        else
            for(int j=c-1;j>=0;j--)
                cout<<mat[i][j]<<"  ";
    }
}

int main()
{
    int mat[r][c]={{1,2,3},
                    {5,6,7},
                    {9,10,11},
                    {13,14,15}};
    
    snake(mat);

    return 0;
}