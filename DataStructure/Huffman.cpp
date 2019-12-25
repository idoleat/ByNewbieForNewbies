#include<bits/stdc++.h>
using namespace std;

struct node{
    node *left;
    node *right;
    long long int frequency;
};

struct Compare
{
    bool operator<()(const node &l, const node &r) {return l.frequency > r.frequency;}
};

bool operator<(const node &l, const node &r) {return l.frequency > r.frequency;}

int main(){
    int n;
    //How many characters(actually numbers here) to encode?
    scanf("%d", &n);
    node *p = new node[n];
    //input character(number) and frequency.
    for(int i=0; i<n;i++){
        int freq;
        scanf("%d", &freq);
        p[i] = { NULL, NULL, freq};
    }
    priority_queue<node, vector<node>, Compare> data(p,p+n);
    //main part of huffman code tree. It's just a simple miplementation.
    //You can extend this to a real huffman tree we use in real life.
    for(int i=1; i<n; i++){
        node x,y,z;
        x = data.top();
        data.pop();
        y = data.top();
        data.pop();
        z.left = &x;
        z.right = &y;
        z.frequency = z.left->frequency + z.right->frequency;
        data.push(z);
    }

    //Use this root node to access the whole tree.
    node root = data.top();
    node *current = &root;
    //Totally frequency.
    printf("%ld", root.frequency);



    return 0;
}
