#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
const int NIL=1234567890;

struct heap
{
    struct node
    {
        int key;
        node *l=NULL, *r=NULL;
        node(int _key=0) : key(_key){}
    } *root=NULL;

    static node* merge(node* l, node* r)
    {
        if( l==NULL )
            return r;
        else if( r==NULL )
            return l;
        else if( l->key>r->key )
            swap(l, r);

        if( rnd() )
            l->r=merge(l->r, r);
        else
            l->l=merge(l->l, r);

        return l;
    }

    void insert(int x)
    {
        root=merge(root, new node(x));
    }

    int query() const
    {
        return root==NULL ? NIL : root->key;
    }

    int erase()
    {
        if( root==NULL )
            return NIL;

        int ans=root->key;
        root=merge(root->l, root->r);
        return ans;
    }

    static bool rnd()
    {
        static int p, i=0;

        if( i<=0 )
            p=rand()&0xFFFF, i=16;

        return (p>>--i)&1;
    }
} h;

bool comp(int a, int b){
    return (a<b)?true:false;
}
