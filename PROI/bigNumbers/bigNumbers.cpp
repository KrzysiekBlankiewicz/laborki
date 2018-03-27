
#include <iostream>
#include "newInt.h"
#include <math.h>
using namespace std;

int main()
{
    //int tablica[10] = {4, 4, 5, 5, 7, 4 ,4, 4,4, 5};
    /*bigInt x = bigInt(2), z;
    bigInt y = bigInt(2);
    x.print();
    y.print();
    z = x + y;
    z.print();*/
    bigInt x, y,z;
    string mode, numberStr1, numberStr2;
    int numberInt1, numberInt2;
    cout<< "Hello World" << endl << "Umiem trzymać duże liczby i je dodawać/odejmować."<< endl << "Wynierz tryb wprowadzania  int/string. I 2 liczby." << endl;
    cin >> mode;
    if(mode == "int"){
        cin >> numberInt1 >> numberInt2;
        x = bigInt(numberInt1);
        y = bigInt(numberInt2);
    }
    if(mode == "string"){
        cin >> numberStr1 >> numberStr2;
        x = bigInt(numberStr1);
        y = bigInt(numberStr2);
    }
    x.print();
    y.print();
    cout << "dodane - ";
    z = x+y;
    z.print();
    cout << "odjęte - ";
    z = x-y;
    z.print();
}
