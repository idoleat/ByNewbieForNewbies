#include<iostream>
#include<cmath>
#include<stdio.h>
#include<list>
using namespace std;

int gcd (int a, int b)
{
    while(b)
        b ^= a ^= b ^= a %= b;
    return a;
}

int main(void)
{
    //LCM(a,b)=c
    //given a and c, find the largest b
    //b=c的因數裡GCD(a/c,c)=1的最大者
    int n;
    int a,c;
    int ans;
    list<int> vec;
    list<int>::iterator it;

    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d %d", &a,&c);
        for (int j = 1; j < sqrt(c); j++)
        {
            if (c % j == 0){
                vec.push_back(j);
                //cout<<vec.back()<<endl;
                vec.push_back(c/j);
                //cout<<vec.back()<<endl;
            }
        }
        vec.sort();
        for(it = vec.begin();it!=vec.end();it++){
            //cout <<"fac : " <<*it <<endl;
            if(gcd(*it,c/a) == 1)ans = *it;
        }
        if(c<a){
            printf("-1");
            vec.clear();
            continue;
        }
        else if(c%a != 0){
            printf("-1");
            vec.clear();
            continue;
        }
        else if(c == a){
            printf("1");
            vec.clear();
            continue;
        }
        else{
            printf("%d\n",c/ans);
            vec.clear();
            continue;
        }


    }

    return 0;
}
