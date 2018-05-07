#ifndef CATEG_H
#define CATEG_H

#include<string>

class Category
{
	std::string name;
	double spentForMe;
	Category* next;
public:	
	static Category* firstCategory;
	static Category* currentCategory;
	
	Category(std::string na_me);
	double getSpentForMe();
	std::string getName();
	static Category* findCategory(std::string neededName);
	void addSpending(double additionalMoney);
	Category* getNext();
};

#endif