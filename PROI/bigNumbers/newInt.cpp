#include <iostream>
#include "newInt.h"
#include <string>
#include <cmath>

using namespace std;

enum oneOfUs{me, he};

bigInt::bigInt()
{
    for(int i = 0; i < N; i++){
        tab[i] = 0;
    }
    invalid = false;
    sgn = 1;
}

bigInt::bigInt(string input){
    int sizeOfInput = input.length();
    if( sizeOfInput > N){
        invalid = true;
        return;
    }
    sgn = 1;
    for(int i = 0; i < N; i++)
    {
        tab[i] = '0';
    }
    for(int i = sizeOfInput - 1; i >= 0; i--)
    {
        if(input[i] == '-'){
            sgn = -1;
            break;
        }
        tab[N - sizeOfInput + i] = (unsigned char)input[i];
    }
    invalid = false;
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

bigInt::bigInt(int input[N])//działa tylko dla tablic N-elementowych (ew. zera na początku)
{
    for(int i = N - 1; i >= 0; i--){
        tab[i] = static_cast<unsigned char>(input[i] + 48);
    }
    sgn = 1;//zakładam, że  nie da się tak zrobić ujemnej
    invalid = false;
}

void bigInt::print()
{
    if(invalid == true){
        cout << "Ta liczba może być ułomna, ale proszę bardzo..." << endl;
    }
    for(int i = 0; i < N; i++){
        cout << tab[i] << " ";
    }
    if(sgn == -1) cout<<"(ujemna)";
    cout << endl;
}

void bigInt::setPosition(int i, unsigned char c)
{
    /*string s;
    cout << "Modyfikujesz ułomną liczbę. Kliknij aby kontynuować." << endl;
    cin >> s;*/
    tab[i] = c;
}

unsigned char bigInt::getPosition(int i)
{
    /*string s;
    cout << "Czytasz ułomną liczbę. Kliknij aby kontynuować." << endl;
    cin >> s;*/
    return tab[i];
}

bigInt bigInt::abs(){
    bigInt positive;
    positive = *this;
    positive.sgn = 1;
    return positive;
}

bool bigInt::operator==(bigInt y)
{
    for(int i = 0; i < N; i++){
        if(tab[i] != y.getPosition(i)) return false;
    }
    return true;
}

bool bigInt::operator>(bigInt y)
{
    if(sgn != y.sgn) return (sgn > y.sgn) ? true : false;
    for(int i = 0; i < N; i++){
        if(tab[i] == y.getPosition(i)) continue;
        if(tab[i] > y.getPosition(i)){
            if(sgn == 1)  return true;
            if(sgn == -1) return false;
        }
        if(tab[i] < y.getPosition(i)){
            if(sgn == 1)  return false;
            if(sgn == -1) return true;
        }
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
	else{
        oneOfUs biggerOne; // potrzebne żeby potem ustawić znak
        int myOriginalSgn = sgn; // potrzebne żeby potem ustawić znak
        if(y.abs() > abs()){
            y.sgn = 1;
            sgn = -1;
            biggerOne = he;
        }
        else{
            y.sgn = -1;
            sgn = 1;
            biggerOne = me;
        }
		for(int i = N-1; i >= 0; i--)
		{
			help = sgn*((int)tab[i] - 48) + y.sgn*((int)y.getPosition(i) - 48) + carriage;//edejmowanie pod kreską
			if(help < 0){
				help += 10;
				carriage = -1;
			}
			else carriage = 0;
			sum.setPosition(i, ((unsigned char)(help + 48)));
		}
        if(biggerOne == me) sum.sgn = myOriginalSgn;
        else sum.sgn = -1 * myOriginalSgn;
    }
	return sum;
}

bigInt bigInt::operator-(bigInt y)
{
    y.sgn *= -1;
    return (*this + y);
}

bigInt bigInt::operator*(bigInt y)
{
    int d = 0;
    bigInt product = bigInt(0);
    for(int i = N-1; i >= 0; i--){
        for(int j = ((int)tab[i] - 48) * pow(10, N - 1 - i); j > 0; j--){
            product = product + y;
        }
    }
    return product;
}

void bigInt::operator=(bigInt y)
{
    for(int i = 0; i < N; i++){
        tab[i] = y.getPosition(i);
    }
    sgn = y.sgn;
    invalid = y.invalid;
}
