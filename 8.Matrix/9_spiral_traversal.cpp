#include<iostream>
using namespace std;
const int r=4,c=5;

void spiral(int mat[r][c])
{
    int top=0,bottom=r-1,left=0,right=c-1;

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
            cout<<mat[top][i]<<"  ";
        top++;
        for(int i=top;i<=bottom;i++)
            cout<<mat[i][right]<<"  ";
        right--;

        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
                cout<<mat[bottom][i]<<"  ";
            bottom--;
        }

        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
                cout<<mat[i][left]<<"  ";
            left++;
        }
    }
}

int main()
{
    int mat[r][c]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    spiral(mat);

    return 0;
}