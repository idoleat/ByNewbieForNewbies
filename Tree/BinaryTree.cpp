#include <iostream>
#include "BinaryTree.h"

using namespace std;

template<typename T>//remember to put this line in front of every definition.
binaryTree<T>::binaryTree(){}

template<typename T>
binaryTree<T>::binaryTree(binaryTree<T> &bt1, T &item, binaryTree<T> &bt2){
}

template<typename T>
bool binaryTree<T>::IsEmpty(){
}

template<typename T>
binaryTree<T> binaryTree<T>::leftSubtree(){
    return *left;
}

template<typename T>
binaryTree<T> binaryTree<T>::rightSubtree(){
    return *right;
}

template<typename T>
T binaryTree<T>::rootData(){
    return *root->data;
}

template<typename T>
void binaryTree<T>::travers_pre(const binaryTree<T> *node){
    if(node == 0)return;

    cout << node->data <<endl;
    travers(node->left);
    travers(node->right);
}

template<typename T>
void binaryTree<T>::travers_in(const binaryTree<T> *node){
    if(node == 0)return;

    travers(node->left);
    cout << node->data <<endl;
    travers(node->right);
}

template<typename T>
void binaryTree<T>::travers_post(const binaryTree<T> *node){
    if(node == 0)return;

    travers(node->left);
    travers(node->right);
    cout << node->data <<endl;
}

