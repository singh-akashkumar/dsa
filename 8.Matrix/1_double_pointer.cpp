#include<iostream>
using namespace std;

//Advantages - We can create rows of different sizes (Jagged Arrays)
//Disadvantages - NOT cache friendly bcz rows may not be at contiguous locations
int main()
{
    int m=3,n=2;

    int **arr;      // arr is a double pointer - it points to an array of pointers
    arr=new int *[m];       // array of pointers

    for(int i=0;i<m;i++)
        arr[i]=new int[n];  //dynamic memory allocation - heap
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            arr[i][j]=10;
            cout<<arr[i][j]<<"  ";
        }

    return 0;
}