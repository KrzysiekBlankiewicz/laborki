#include <iostream>
#include <iomanip>
#include "Tree.h"
#include "Node.h"

using namespace std;

template<class T> ostream& operator<<(std::ostream& os, const Tree<T>& printedTree)
{
    cout << "s";
    int tempWidth = 0;
    int nesting = printedTree.nesting();
    vector<Node<T>*> gggg, hhhh;
    gggg.push_back(printedTree.root);
    for(int i = 0; i < nesting; i++){
        tempWidth = pow(2, nesting - i) / 2;
        for(unsigned i = 0; i < gggg.size(); i++){
            if(gggg[i] == NULL){
                os << setw(tempWidth) << "-" ; 
                hhhh.push_back(NULL);
                hhhh.push_back(NULL);
            }
            else{
                os << setw(tempWidth) << gggg[i]->getItem(); 
                hhhh.push_back(gggg[i]->getRight());
                hhhh.push_back(gggg[i]->getLeft());
            }
        }
        os << endl;
        gggg.clear();
        gggg = hhhh;
        hhhh.clear();
    }
    return os;
}
