//Krzysztof Blankiewicz
//Naglowki klasy Month
//Obiekt tej klasy reprezentuje miesiac. 
//Jest tworzony jesli pojawia sie zakupy zrobione w tym miesiacu. 
//Zawiera dane o kwotach wydanych w tym miesiacu.

#ifndef MONTH_H
#define MONTH_H

#include<string>
#include<vector>
#include<structures.h>
#include<iostream>

const int THISYEAR = 2018;

enum monthName{JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, OCT, SEP, NOV, DEC};

std::istream& operator>>( std::istream& is, monthName& i);

class Month
{
	int year;
	monthName name;
	double spentInMonth;
	std::vector<SpendingShedule*> spentForCateg;
	Month* next;
	
public:
	static Month* firstMonth;		//potrzebne do findMonth
	static Month* currentMonth;		//
	static double spentInYear(int neededYear);      //oblicza wydatki z roku
	Month(monthName na_me, int ye_ar = THISYEAR);
	monthName getName() const;
	int getYear() const;
	double getSpentInMonth() const;
	Month* getNext() const;
	static Month* findMonth(monthName neededName, int neededYear = THISYEAR);
	void addSpending(double additionalMoney);		//dodaje po prostu
	void addToSchedule(Category* category, double additionalMoney); //dodaje z uwzgl. kategorii
	void showSpendings() const;							//wyswietla na konsoli wydatki z miesiaca kategoriami
	static void freeMonths();
	void freeVector() const;
};

#endif // MONTH_H