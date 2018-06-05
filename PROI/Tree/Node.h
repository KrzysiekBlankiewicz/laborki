#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class Type>
class Node{
	Type* item;
	Node<Type>* up;
    Node<Type>* right;
    Node<Type>* left;
public:
    Node();
	Node(const Type& newItem);
    ~Node();
    Type getItem();
    Node* getUp();
    Node<Type>* getRight();
    Node<Type>* getLeft();
    void setRight(Node<Type>* newRight);
    void setLeft(Node<Type>* newLeft);
    void setUp(Node<Type>* newUp);
    void operator=(Node other);
    bool operator==(Node<Type> other);
    bool operator!=(Node other);
    bool operator>(Node other);
    bool operator<(Node other);
    bool operator>=(Node other);
    bool operator<=(Node other);
    int f();
};



template<class Type>Node<Type>::Node(){
    item = NULL;
    up = NULL; 
    right = NULL;
    left = NULL;
}
template<class Type>Node<Type>::Node(const Type& newItem){
    item = new Type;
    *item = newItem;
    up = NULL; 
    right = NULL;
    left = NULL;
}
template<class Type>Node<Type>::~Node(){
    /*Node<Type>* tempNode1;
    Node<Type>* tempNode2;
    tempNode1 = getLeft();
    tempNode2 = getRight();
    if(tempNode1 != NULL) delete tempNode1;
    if(tempNode1 != NULL) delete tempNode2;*/
    if(up != NULL){
        if(up->right == this) up->setRight(NULL);
        if(up->left == this) up->setLeft(NULL);
    }
    delete item;
}


template<class Type> Type Node<Type>::getItem(){
    return *item;
}
template<class Type> Node<Type>* Node<Type>::getLeft(){
    return left;
}
template<class Type> Node<Type>* Node<Type>::getUp(){
    return up;
}
template<class Type> Node<Type>* Node<Type>::getRight(){
    return right;
}
template<class Type> void Node<Type>::setRight(Node<Type>* newRight){
    right = newRight;
}
template<class Type> void Node<Type>::setLeft(Node<Type>* newLeft){
    left = newLeft;
}
template<class Type> void Node<Type>::setUp(Node<Type>* newUp){
    up = newUp;
}

template<class Type> void Node<Type>::operator=(Node other){
    item = other.item;
    up = other.up;
    right = other.right;
    left = other.left;
}
template<class Type> bool Node<Type>::operator!=(Node other){
    if(other.item != item) return true;
    else return false;
}
template<class Type> bool Node<Type>::operator==(Node<Type> other){
    if(other.item == item) return true;
    else return false;
}
template<class Type> bool Node<Type>::operator>(Node other){
    if(item > other.item) return true;
    else return false;
}
template<class Type> bool Node<Type>::operator<(Node other){
    if(item < other.item) return true;
    else return false;
}
template<class Type> bool Node<Type>::operator<=(Node other){
    if(item <= other.item) return true;
    else return false;
}
template<class Type> bool Node<Type>::operator>=(Node other){
    if(item >= other.item) return true;
    else return false;
}

#endif
