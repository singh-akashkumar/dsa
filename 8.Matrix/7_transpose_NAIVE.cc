#include<iostream>
using namespace std;
const int r=2,c=2; 

void transpose(int mat[r][c])
{
    int temp[r][c];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            temp[i][j]=mat[i][j];
    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            mat[i][j]=temp[j][i];
}

int main()
{
    int mat[r][c]={1,1,2,2};

    transpose(mat);

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<mat[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}