//#include <iostream>
#define XYZ 30000
using namespace std;

void swaping(int* tab, int x, int sajz)
{
    int c = tab[x];
    tab[x] = tab[sajz-x];
    tab[sajz-x] = c;
}

int main()
{
    int* wsk = new int;
    int text[XYZ];
    for(int i = 0; i < XYZ; i++){
        text[i] = i;
    }
    for(int j = 0; j < XYZ; j++){

        for(int i = 0; i < XYZ; i++){
        swaping(text, i, XYZ);
        }
    }
}
