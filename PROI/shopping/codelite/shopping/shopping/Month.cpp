#include<Month.h>
#include<iostream>
#include<structures.h>

using namespace std;

Month* Month::firstMonth = NULL;
Month* Month::currentMonth = NULL;

std::istream& operator>>( std::istream& is, monthName& i)
{
	int x;
	std::cin >> x;
	i = static_cast<monthName>(x);
	return is;
}

Month::Month(monthName na_me, int ye_ar)//roboczy
{
	if(currentMonth != NULL){
		year = ye_ar;
		name = na_me;
		spentInMonth = 0;
		currentMonth->next = this;
		currentMonth = this;
		next = NULL;
	}
	else{
		year = ye_ar;
		name = na_me;
		spentInMonth = 0;
		currentMonth = this;
		firstMonth = this;
		next = NULL;
	}
}

monthName Month::getName() const
{	
	return name;
}
int Month::getYear() const
{	
	return year;
}

double Month::getSpentInMonth() const
{
	return spentInMonth;
}

Month* Month::getNext() const
{
	return this->next;
}

double Month::spentInYear(int neededYear)
{
	Month* month = firstMonth;
	double sum = 0;
	while(month != NULL){
		if(month->year == neededYear) sum += month->spentInMonth;
		month = month->next;
	}
	return sum;
}

Month* Month::findMonth(monthName neededName, int neededYear)
{
	Month* tempMonth = firstMonth;
	while(tempMonth != NULL){
		if(tempMonth->name == neededName && tempMonth->getYear() == neededYear)
			return tempMonth;
		else
			tempMonth = tempMonth->next;
	}
	Month* newMonth = new Month(neededName, neededYear);
	return newMonth;
}

void Month::addSpending(double additionalMoney)
{
		spentInMonth += additionalMoney;
}

void Month::addToSchedule(Category* category, double additionalMoney)
{
	for(int i = 0; i < spentForCateg.size(); i++)
		if(spentForCateg[i]->category == category){
			spentForCateg[i]->money += additionalMoney;
			return;
		}
	SpendingShedule* newSpendingShedule = new SpendingShedule(category, additionalMoney);
	spentForCateg.push_back(newSpendingShedule);
}

void Month::showSpendings() const
{
	cout << name << "." << year << endl;
	for(int i = 0; i < spentForCateg.size(); i++){
		cout << "  " << spentForCateg[i]->category->getName() << " " << spentForCateg[i]->money << endl;
	}
}

void Month::freeVector() const
{
	int x = spentForCateg.size();
	for(int i = 0; i < spentForCateg.size(); i++)
		delete spentForCateg[i];
}

void Month::freeMonths()
{
	Month* currentMonth = firstMonth;
	Month* nextMonth;
	while(currentMonth != NULL){
		nextMonth = currentMonth->getNext();
		delete currentMonth;
		currentMonth->freeVector();
		currentMonth = nextMonth;
	}
}