#ifndef INTUI_H
#define INTUI_H
#include "Tree.h"

class IntUI
{
    Tree<int>* drzewo;
public:
    IntUI(){
        drzewo = new Tree<int>;
    }
    ~IntUI(){
        delete drzewo;
    }
    void startProgram();
    void help();
    void dodaj();
    void usun();
    void pokaz();
    void czysc();
    void znajdz();
    int askForInt(){
};

#endif

