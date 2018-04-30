#ifndef _BINARYTREE_H_
#define _BUNARYTREE_H_

#include "node.h"

template<typename T>
class binaryTree{
public:
    binaryTree();
    bool IsEmpty();
    binaryTree(binaryTree<T> &bt1, T &item, binaryTree<T> &bt2);
    //   item
    //   /  \
    // bt1  bt2
    binaryTree<T> leftSubtree();
    binaryTree<T> rightSubtree();
    void insert();
    T rootData();
    void travers_pre(const binaryTree<T> *node);
    void travers_in(const binaryTree<T> *node);
    void travers_post(const binaryTree<T> *node);

private:
    node<T> *root;
    binaryTree *left;
    binaryTree *right;
};

#endif // _BINARYTREE_H_
//full binary tree : can fully be put in a tree and access any node very fast by indicating the index.
//complete binary tree : fill the level to full first.
//so complete can easily be put in the array by accessing by index in order.
