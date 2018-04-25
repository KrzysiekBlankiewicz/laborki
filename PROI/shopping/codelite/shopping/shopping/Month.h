#ifndef MONTH_H
#define MONTH_H

#include<string>
#include<vector>
#include<structures.h>
#include<iostream>

const int THISYEAR = 2018;

enum monthName{JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, OCT, SEP, NOV, DEC};

/*std::istream& operator>>( std::istream& is, monthName& i )
{
	int x;
	std::cin >> x;
	i = static_cast<monthName>(x);
	return is;
}
*/
class Month
{
	int year;
	monthName name;
	int spentInMonth;
	std::vector<SpendingShedule*> spentForCateg;
	Month* next;
	
public:
	static Month* firstMonth;
	static Month* currentMonth;
	Month(monthName na_me, int ye_ar = THISYEAR);
	monthName getName();
	int getYear();
	static Month* findMonth(monthName neededName, int neededYear = THISYEAR);
	void addSpending(double additionalMoney);
	void addToSchedule(Category* category, double additionalMoney);
	void showSpendings();
};

#endif // MONTH_H