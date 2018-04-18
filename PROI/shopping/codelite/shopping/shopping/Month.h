#ifndef MONTH_H
#define MONTH_H

#include<string>
#include<vector>
#include<structures.h>

enum monthName{JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, OCT, SEP, NOV, DEC};
class Month
{
	int year;
	monthName name;
	int spentInMonth;
	vector<SpendingShedule> spentForCateg;
public:

};



#endif // MONTH_H