#include<iostream>
#include<string>
using namespace std;
int main(void){
    string s;
    while(getline(cin,s)){
        int i;
        int One=0,Zero=0;
        for(i=0;i<s.length();i++){
            if(s[i]=='0')
                Zero+=1;
            if(s[i]=='1')
                One+=1;
        }
        cout<<Zero<<" "<<One<<endl;
    }
    return 0;
}

