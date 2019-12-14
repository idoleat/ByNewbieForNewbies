//yeah, I am lazy so I write these two lines.
#include<bits/stdc++.h>
using namespace std;

//I think my code is very easy to read, so I am lazy to write comments.
//Open issue if you are still confusing.
class DisjointSet{
public:
    vector<int> forest;
    vector<int> rankk;

    DisjointSet(int n){
        forest.resize(n+1,0);
        rankk.resize(n+1,0);
    }

    void MakeSet(int x){
        if(forest[x] == 0){
            forest[x] = x;
            rankk[x] = 0;
        }

    }

    int FindSet(int x){
        if(x != forest[x]) forest[x] = FindSet(forest[x]);
        return forest[x];
    }

    void Link(int x, int y){
        if(rankk[x] > rankk[y]) forest[y] = x;
        else{
            forest[x] = y;
            if(rankk[x] == rankk[y]) rankk[y] += 1;
        }
    }
    void Unionn(int x, int y){
        Link(FindSet(x), FindSet(y));
    }
};
