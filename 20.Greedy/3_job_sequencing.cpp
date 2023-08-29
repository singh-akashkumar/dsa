#include<bits/stdc++.h>
using namespace std;

struct job
{
    char job_id;
    int dead;
    int profit;
};

bool mycomp(job a,job b)
{
    return (a.profit>b.profit);
}

int job_sequencing(job arr[],int n)
{
    sort(arr,arr+n,mycomp);

    int result[n];
    bool slot[n];
    for (int i=0; i<n; i++)
        slot[i] = false;
 
    for (int i=0; i<n; i++)
    {
        for (int j=min(n, arr[i].dead)-1; j>=0; j--)
        {
            if (slot[j]==false)
            {
                result[j] = i;  
                slot[j] = true;
                break;
            }
        }
    }

    int max_profit=0;
    cout<<"Job Sequence is:";
    for (int i=0; i<n; i++)
    {
        if (slot[i])
        {
            cout << arr[result[i]].job_id << " ";
            max_profit+=arr[result[i]].profit;
        }
        else
            cout<<"_"<<" ";
    }
    return max_profit;
}

int main()
{
    job arr[]={{'a',4,50},
                {'b',1,5},
                {'c',1,20},
                {'d',5,10},
                {'e',5,80}};
    
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"\nMax profit is: "<<job_sequencing(arr,n);

    return 0;
}