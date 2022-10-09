#include<iostream>
#include<algorithm>
using namespace std;
const int r=3,c=5;

//O(r * log(mx-mn) * log c) time
int median(int mat[r][c])
{
    int mn=mat[0][0],mx=mat[0][c-1];
    for(int i=0;i<r;i++)
    {
        mn=min(mn,mat[i][0]);
        mx=max(mx,mat[i][c-1]);
    }
    
    int medpos=((r*c)+1)/2;

    while(mn<mx)
    {
        int mid=(mn+mx)/2;
        int midpos=0;
        for(int i=0;i<r;i++)
            midpos+=upper_bound(mat[i],mat[i]+c,mid)-mat[i];
        
        if(midpos<medpos)
            mn=mid+1;
        else
            mx=mid;     // NOT mid-1;
    }
    return mn;          // or mx, since both will be equal
}

int main()
{
    int mat[r][c]={5,10,20,30,40,1,2,3,4,6,11,13,15,17,19};
    cout<<median(mat);

    return 0;
}