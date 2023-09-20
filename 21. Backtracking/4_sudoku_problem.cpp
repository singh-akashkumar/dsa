#include<bits/stdc++.h>
using namespace std;

// given partially filled grid. we need to fill empty cells. empty cells are represented by 0
// grid is always square
// there can be multiple possible ans - we need to print only one
// Rules -
// 1. Every no. in every row must be diff
// 2. Every no. in every col must be diff
// 3. In every sub-grid of 2x2 (if grid is 4x4), each no. should be diff
                            // 3x3 if grid is 9x9
// 4. nos. to be filled are 1 to n only in nxn matrix

# define n 4

void print(int grid[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}

bool isSafe(int grid[n][n],int i,int j,int k)
{
    for(int x=0;x<n;x++)
        if(grid[x][j]==k || grid[i][x]==k)
            return false;
    
    int s=sqrt(n);
    int rs=i-i%s;
    int cs=j-j%s;
    for(int i=0;i<s;i++)
        for(int j=0;j<s;j++)
            if(grid[i+rs][j+cs]==k)
                return false;
    
    return true;
}

bool gridRec(int grid[n][n])
{
    int i,j;
    bool isempty=true;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(grid[i][j]==0)
            {
                isempty=false;
                break;
            }
        }
        if(isempty==false)
            break;
    }
    
    if(i==n && j==n)
        return true;

    for(int k=1;k<=n;k++)
    {
        if(isSafe(grid,i,j,k))
        {
            grid[i][j]=k;
            if(gridRec(grid))
                return true;
            grid[i][j]=0;
        }
    }
    return false;
}

int main()
{
    int grid[n][n]={{1,0,3,0},
                {0,0,2,1},
                {0,1,0,2},
                {2,4,0,0}};
    if(gridRec(grid))
        print(grid);
    else
        cout<<"No solution exists."<<endl;
    return 0;
}