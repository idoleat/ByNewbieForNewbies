#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main ()
{
    int n,q,tempt,L,R,K;
    cin>>n>>q;
    int *values=new int[n];
    int *copyy=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>tempt;
        values[i]=tempt;
    }

    for (int i=0; i<q; i++)
    {
        cin>>L>>R>>K;
        for(int i=(L-1);i<=(R-1);i++){
            copyy[i-L+1]=values[i];
        }

        qsort (copyy, (R-L+1), sizeof(int), compare);
        cout<<copyy[K-1]<<endl;
    }
    return 0;
}
