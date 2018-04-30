#ifndef _NODE_H_
#define _NODE_H_

template<typename T>
class node{
public:
    node();
    node(T);

    node *left;
    node *right;
    T data;
};

#endif // _NODE_H_
