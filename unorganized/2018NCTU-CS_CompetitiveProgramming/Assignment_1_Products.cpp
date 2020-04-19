#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{
    const int buf_size = 1024; // depends on problem spec
    static char buf[buf_size]; // use static var to avoid stack overflow
    int m,x,y,row[50],column[50],brow=0,bcolumn=0;

    int line_cnt = 0; // counter: line read
    vector<string> myVec;

    char * pch;


    while ( scanf("%s", buf) == 1 )
    {
        pch = strtok (buf," +|");
        if(strlen(buf)>9)
        {

            while (pch != NULL)
            {
                if(strlen(pch)==(strlen(buf)-2)){
                    myVec.clear();
                    for(int i=0;i<50;i++)row[i]=0;
                    for(int i=0;i<50;i++)column[i]=0;
                    brow=0;
                    bcolumn=0;
                }
                if(strlen(pch)==9 && strcmp(pch,"---------")!=0){
                    myVec.push_back(pch);
                    //printf("%s is pushed\n",pch);
                }
                pch = strtok (NULL," +|");
            }
        }
        else
        {
            m=sqrt(myVec.size());
            for(int i=0;i<myVec.size();i++){
                if(buf==myVec[i]){
                    y=(i+1)/m;
                    x=(i+1)%m;
                    if(x==0)x=m;

                    row[y-1]+=1;
                    column[x-1]+=1;

                    if(row[y-1]==m)brow+=1;
                    if(column[x-1]==m)bcolumn+=1;
                    printf("%d %d\n",brow,bcolumn);
                    break;
                }
            }
        }
    }
    return 0;
}
