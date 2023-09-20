#include<bits/stdc++.h>
using namespace std;
#define n 4

void print(int soln[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<soln[i][j]<<" ";
        cout<<endl;
    }
}

bool isSafe(int maze[n][n],int i,int j)
{
    return (i<n && j<n && maze[i][j]==1);
}

bool mazeRec(int maze[n][n],int i,int j,int soln[n][n])
{
    if(i==n-1 && j==n-1)
    {
        soln[i][j]=1;
        return true;
    }
    if(isSafe(maze,i,j))
    {
        soln[i][j]=1;
        if(mazeRec(maze,i+1,j,soln))
            return true;
        else if(mazeRec(maze,i,j+1,soln))
            return true;
        
        soln[i][j]=0;     //if bottom and right cells are not safe, then present cell is also not safe.
                            // hence, backtrack. 
    }
    return false;
}

bool rat_in_maze(int maze[n][n])
{
    int soln[n][n]={0};
    if(mazeRec(maze,0,0,soln)==true)
    {
        print(soln);
        return true;
    }
    else
        return false;
}

int main()
{
    int maze[n][n]={{1,0,0,0},
                    {1,1,0,1},
                    {0,1,0,0},
                    {1,1,1,1}};
    
    cout<<rat_in_maze(maze);
}