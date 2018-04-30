#include<iostream>
#include "node.h"

using namespace std;

template<typename T>
node<T>::node(){
    left=nullptr;
    right=nullptr;
}

template<typename T>
node<T>::node(T t):data(t){}

