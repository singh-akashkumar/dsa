#include<bits/stdc++.h>
using namespace std;

#define n 4
int board[n][n];

void print(int board[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

bool isSafe(int row,int col)
{
    for(int i=0;i<col;i++)    
        if(board[row][i])      // check if there is any 1 in the whole row
            return false;
    
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)   // check left upper diagonal
        if(board[i][j])
            return false;
    
    for(int i=row,j=col;i<n && j>=0;i++,j--)    // chek left lower diagonal
        if(board[i][j])
            return false;

    // no need to check right diagonals bcz we are going from left to right columns and cols of right side
    // of j have not been finalized

    return true;
}

// O(n!) time and O(n^2) aux space
bool solveRec(int col)
{
    if(col==n)
        return true;
    
    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col))
        {
            board[i][col]=1;
            if(solveRec(col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;
}

void solve()
{
    if(solveRec(0)==false)
    {
        cout<<"Solution does not exist.";
        return;
    }
    print(board);
    return;
}

int main()
{
    solve();
    return 0;
}