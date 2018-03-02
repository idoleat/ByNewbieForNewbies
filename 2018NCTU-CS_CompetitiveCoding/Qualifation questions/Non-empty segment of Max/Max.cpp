#include<iostream>
using namespace std;
int main(void)
{
    int n,sum=0,maxx=0,countt=0;
    cin>>n;
    int *num=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }

    maxx=num[0];
    for(int j=0; j<n; j++)
    {
        for(int i=j;i<n;i++){
            sum+=num[i];
            if(sum>maxx)maxx=sum;
        }
        sum=0;
    }
    cout<<maxx<<endl;
    return 0;
}
