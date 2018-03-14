#include <iostream>
#include "class.h"

using namespace std;

int calcSurface(int x, int y){
    return x*y;
}

void fault(){
    int* x = NULL;
    *x = 3;
}

void fault2(){
    int* wsk = new int;
}

int main()
{
    Wall X, Y;
    int w1, w2, h1, pos1;
    string color;
    cin >> w1 >> h1 >> color;
    X.paintWall(color);
    X.setHeight(h1);
    X.setWidth(w1);
    cout << X.getColor() << "  " << calcSurface(X.getHeight(), X.getWidth());

    fault();

    return 0;
}

