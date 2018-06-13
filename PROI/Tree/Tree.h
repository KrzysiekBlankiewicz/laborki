
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include "Node.h"
#include "exeptions.h"


template<class Type>
class Tree{
	Node<Type>* root;
    int mySize;
public:
	Tree();
    ~Tree();
    
    class Iterator{
        Node<Type>* pointed;
        int nested;
    public:
        Iterator();
        Iterator(Node<Type>* x);
        Iterator operator++();
        Iterator operator++(int x);
        Iterator operator--();
        bool operator==(Iterator other);
        bool operator!=(Iterator other);
        Type operator*();
    };
    
    Iterator begin();
    
    bool empty() const;
    int size() const;
    
    void insert(const Type& addedItem);
    void erase(const Type& removedItem);
    void clear();
    // swap
    
    int count();
    int nesting(Node<Type>* triedNode) const;
    int nesting() const;
    
    void show(Node<Type>* nodeToShow) const;
    void show() const;
    void copyPart(Tree<Type>& tree, Node<Type>* source) const;
    void copyInternallyWithErasing(Node<Type>* erased);
    template<class T> friend std::ostream& operator<<(std::ostream&, Tree<T>&);

};


//////////////////////////////// Definicje Tree  ////////////////////////////////////

template <class Type> Tree<Type>::Tree(){
    root = NULL;
    mySize = 0;
}
template <class Type>Tree<Type>::~Tree(){
    delete root;
}

template<class Type> bool Tree<Type>::empty() const{
    if(root == NULL) return true;
}

template<class Type> int Tree<Type>::size() const{
    return mySize;
}

template<class Type> int Tree<Type>::nesting() const
{
    return nesting(root);
}

template<class Type> int Tree<Type>::nesting(Node<Type>* triedNode) const
{
    if(triedNode == NULL) return 0;
    return std::max(nesting(triedNode->getLeft()), nesting(triedNode->getRight())) + 1;
}

template<class Type> void Tree<Type>::insert(const Type& addedItem)
{
    ++mySize;
    Node<Type>* tempNode=root;
    Node<Type>* previousTempNode;
    if(tempNode==NULL){
        root = new Node<Type>(addedItem); 
        return;
    }
    while(1){
        previousTempNode = tempNode;
        if(addedItem > tempNode->getItem()){
            tempNode = tempNode->getRight();
            if(tempNode == NULL){
                Node<Type>* x = new Node<Type>(addedItem);
                previousTempNode->setRight(x);
                x->setUp(previousTempNode);
                return;
            }
        }
        else if(addedItem < tempNode->getItem()){
            tempNode = tempNode->getLeft();
            if(tempNode == NULL){ 
                Node<Type>* x = new Node<Type>(addedItem);
                previousTempNode->setLeft(x);
                x->setUp(previousTempNode);                
                return;
            }
        }
        else if(addedItem == tempNode->getItem()){
            return;
            --mySize;
        }
    }
    
}
template<class Type> void Tree<Type>::erase(const Type& removedItem)
{
    int ISLEFT = 2;
    Node<Type>* tempNode=root;
    while(1){
        if(tempNode == NULL) throw Exept("nima");
        if(removedItem > tempNode->getItem()){
            ISLEFT = 0; //!!!!!!!!!!!!!!!!!!!!!
            tempNode = tempNode->getRight();
        }
        else if(removedItem < tempNode->getItem()){
            ISLEFT = 1;  //!!!!!!!!!!!!!!!!!!!!
            tempNode = tempNode->getLeft();
        }
        else if(removedItem == tempNode->getItem()){
            if(tempNode != root){
                if(ISLEFT == 0) tempNode->getUp()->setRight(NULL);
                else if(ISLEFT == 1) tempNode->getUp()->setLeft(NULL);
                copyInternallyWithErasing(tempNode);
                return;
            }
            else{
                Tree<Type> tempTree1, tempTree2;
                copyPart(tempTree1, tempNode->getLeft());
                copyPart(tempTree2, tempNode->getRight());
                delete tempNode;
                root = NULL;
                copyPart(*this, tempTree1.root);
                copyPart(*this, tempTree2.root);
                return;
            }
        }
    }
}
template<class Type> void Tree<Type>::clear()
{
    delete root;
}


template<class Type> void Tree<Type>::show(Node<Type>* NodeToShow) const
{
    int tempWidth = 0;
    int nest = nesting(root);
    std::vector<Node<Type>*> gggg, hhhh;
    gggg.push_back(root);
    for(int i = 0; i < nest; i++){
        tempWidth = pow(2, nest - i) / 2;
        for(unsigned i = 0; i < gggg.size(); i++){
            if(gggg[i] == NULL){
                std::cout << std::setw(tempWidth) << "-" ; 
                hhhh.push_back(NULL);
                hhhh.push_back(NULL);
            }
            else{
                std::cout << std::setw(tempWidth) << gggg[i]->getItem(); 
                hhhh.push_back(gggg[i]->getRight());
                hhhh.push_back(gggg[i]->getLeft());
            }
        }
        std::cout << std::endl;
        gggg.clear();
        gggg = hhhh;
        hhhh.clear();
    }
}
template<class Type> void Tree<Type>::show() const
{
    show(root);
}

template<class Type> void Tree<Type>::copyPart(Tree<Type>& tree, Node<Type>* source) const
{
    if(source == NULL) return;
    tree.insert(source->getItem());
    copyPart(tree, source->getLeft());
    copyPart(tree, source->getRight());
}
template<class Type> void Tree<Type>::copyInternallyWithErasing(Node<Type>* erased)
{
    Tree<Type> littleTree;
    copyPart(littleTree, erased);
    delete erased;
    copyPart(*this, littleTree.root->getLeft());
    copyPart(*this, littleTree.root->getRight());
}

template<class Type> typename Tree<Type>::Iterator Tree<Type>::begin()
{
    Node<Type>* tempNode = root;
    if(tempNode == NULL)
        throw Exept("Iterator wskazuje na NULL");
    while(tempNode->getLeft() != NULL)
        tempNode = tempNode->getLeft();
    Iterator x(tempNode);
    return x;
}
///////////////////////////////// Definicje iteratora ////////////////////////////


template<class Type> Tree<Type>::Iterator::Iterator()
{
    
}
template<class Type> Tree<Type>::Iterator::Iterator(Node<Type>* x): pointed(x) {}
template<class Type> Type Tree<Type>::Iterator::operator*()
{
    if(pointed == NULL) throw Exept("operator wskazuje na NULL");
    return pointed->getItem();
}
template<class Type> typename Tree<Type>::Iterator Tree<Type>::Iterator::Iterator::operator++()
{
    if(pointed == NULL) throw Exept("operator wskazuje na NULL");
    pointed = pointed->find();
    return *this;
}
template<class Type> typename Tree<Type>::Iterator Tree<Type>::Iterator::Iterator::operator++(int x)
{
    if(pointed == NULL) throw Exept("operator wskazuje na NULL");
    Iterator newIterator;
    newIterator.pointed = pointed->find();
    *this = newIterator;
    return *this;
}
template<class Type> typename Tree<Type>::Iterator Tree<Type>::Iterator::Iterator::operator--()
{
    if(pointed == NULL) throw Exept("operator wskazuje na NULL");
    pointed = pointed->findRev();
    return *this;
}
template<class Type> bool Tree<Type>::Iterator::Iterator::operator==(Tree<Type>::Iterator other)
{
    if(pointed == NULL || other->pointed == NULL) throw Exept("operator wskazuje na NULL");
    if(pointed->getItem() == *other) return true;
    else return false;
}
template<class Type> bool Tree<Type>::Iterator::Iterator::operator!=(Tree<Type>::Iterator other)
{
    if(pointed == NULL || other->pointed == NULL) throw Exept("operator wskazuje na NULL");
    if(pointed->getItem() != *other) return true;
    else return false;
}


#endif
