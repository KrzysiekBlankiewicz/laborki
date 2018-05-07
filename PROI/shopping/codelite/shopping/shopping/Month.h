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
	static Month* firstMonth;
	static Month* currentMonth;
	static double spentInYear(int neededYear);
	Month(monthName na_me, int ye_ar = THISYEAR);
	monthName getName();
	int getYear();
	double getSpentInMonth();
	Month* getNext();
	static Month* findMonth(monthName neededName, int neededYear = THISYEAR);
	void addSpending(double additionalMoney);
	void addToSchedule(Category* category, double additionalMoney);
	void showSpendings();
};

#endif // MONTH_H