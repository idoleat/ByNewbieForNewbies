#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;


int main(void)
{
    int P,W,posi=1,width,height,pushes,countt;
    int content[6]={};
    char ch;
    char op[30];
    scanf("%d %d", &P, &W);
    cout<<P<<" "<<W<<endl;
    vector<int> *w = new vector<int>[W];
    for(int i=0;i<P;i++){
        scanf("%c", &ch);
        scanf("%c", &ch);
        if(ch=='L'){
            width=2;
            height=3;
            content[1]=1;content[4]=1;content[5]=1;content[6]=1;
        }
        if(ch=='J'){
            width=2;
            height=3;
            content[1]=1;content[2]=1;content[3]=1;content[4]=1;
        }
        if(ch=='O'){
            width=2;
            height=2;
            content[1]=1;content[2]=1;content[3]=1;content[4]=1;
        }
        if(ch=='I'){
            width=1;
            height=4;
            content[1]=1;content[2]=1;content[3]=1;content[4]=1;
        }
        if(ch=='Z'){
            width=3;
            height=2;
            content[1]=1;content[3]=1;content[4]=1;content[6]=1;
        }
        if(ch=='S'){
            width=3;
            height=2;
            content[2]=1;content[3]=1;content[4]=1;content[5]=1;
        }
        if(ch=='T'){
            width=3;
            height=2;
            content[2]=1;content[3]=1;content[4]=1;content[6]=1;
        }
        cout<<"hey "<<ch<<endl;
        scanf("%s", &op);
        for(int j=0;i<strlen(op);i++){
            if(op[j]=='<'){
                posi+=1;
                if((posi-1)>W)posi-=1;
            }
            if(op[j]=='>'){
                posi-=1;
                if(posi<1)posi+=1;
            }
        }
        for(int m=0;m<width;m++){
            for(n=0;n<height;n++){
                w[posi+m].push_back(content[pushes]);
                pushes+=1;
            }
        }
        pushes=0;

        for(int m=0;m<width;m++){
            for(n=0;n<height;n++){
                w[posi+m].at(w[posi+m].size()-2-n)+=w[posi+m].at(w[posi+m].size()-1-n);
            }
            w[posi+m].at(w[posi+m].size()-1-n)=0;
        }
    }

    return 0;
}

