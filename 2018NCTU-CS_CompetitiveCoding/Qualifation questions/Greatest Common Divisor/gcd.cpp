#include<iostream>
#include<stdlib.h>
using namespace std;
int main(void)
{
    int a,b,c;
    while(cin>>a>>b)
    {
        if(a==0)
        {
            cout<<abs(b)<<endl;
            break;
        }
        if(b==0)
        {
            cout<<abs(a)<<endl;
            break;
        }
        if(a<b)
        {
            c=a;
            a=b;
            b=c;
        }
        while(a%b!=0)
        {
            c=a;
            a=b;
            b=c%b;
        }
        cout<<abs(b)<<endl;
    }
    return 0;
}
