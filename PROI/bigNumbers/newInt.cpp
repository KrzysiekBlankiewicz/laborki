#include <iostream>
#include "newInt.h"
#include <string>
#include <cmath>

using namespace std;

bigInt::bigInt()
{
    for(int i = 0; i < N; i++){
        tab[i] = 0;
    }
    invalid = false;
    sgn = 1;
}

bigInt::bigInt(string input){
    if(input.length() > N){
        invalid = true;
        return;
    }

}

bigInt::bigInt(int input){
    if(input > pow(10, N)){
        invalid = true;
        return;
    }
	if(input < 0){
        sgn = -1;
        input *= -1;
    }
	else sgn = 1;
    for(int i = 1; i < N+1; i++){
        tab[N-i] = static_cast<unsigned char>(input%10 + 48);
        input = input/10;
    }
    invalid = false;
}

void bigInt::print()
{
    for(int i = 0; i < N; i++){
        cout << tab[i] << " ";
    }
    if(sgn == -1) cout<<"(ujemna)";
    cout << endl;
}

void bigInt::setPosition(int i, unsigned char c)
{
    tab[i] = c;
}

unsigned char bigInt::getPosition(int i)
{
    return tab[i];
}

bool bigInt::operator==(bigInt y)
{
    for(int i = 0; i < N; i++){
        if(tab[i] != y.getPosition(i)) return false;
    }
    return true;
}

bool bigInt::operator>(bigInt y)//nie działa dla ujemnych
{
    if(sgn != y.sgn) return (sgn > y.sgn) ? true : false;
    for(int i = 0; i < N; i++){
        if(tab[i] == y.getPosition(i)) continue;
        if(tab[i] > y.getPosition(i)) return true;
        if(tab[i] < y.getPosition(i)) return false;
    }
    return false;
}

bool bigInt::operator<(bigInt y)
{
    if(y > *this) return true;
    else return false;
}

bigInt bigInt::operator+(bigInt y)
{
    bigInt sum;
    int help, helpUpgraded;
    int carriage = 0;
	if(sgn == y.sgn){
		for(int i = N-1; i >= 0; i--)
		{
			help = ((int)tab[i] - 48) + ((int)y.getPosition(i) - 48) + carriage;
			helpUpgraded = help%10;
			if(helpUpgraded != help) carriage = 1;
			else carriage = 0;
			sum.setPosition(i, ((unsigned char)helpUpgraded + 48));
		}
		if(carriage != 0) sum.invalid = true;
		sum.sgn = sgn;
	}
	//Dalej nie dokonczone
	/*else{
		for(int i = N-1; i >= 0; i--)
		{
			help = sgn*((int)tab[i] - 48) + y.sgn*((int)y.getPosition(i) - 48) + carriage;
			//cout << help << "=" << sgn*((int)tab[i] - 48) << "+" << y.sgn*((int)y.getPosition(i) - 48) << "+" << carriage << endl;
			if(help < 0){
				help += 10;
				carriage = -1;
			}
			else carriage = 0;
			cout << "->" << help << endl;
			sum.setPosition(i, ((unsigned char)(help + 48)));
		}
	}*/
	return sum;
}
