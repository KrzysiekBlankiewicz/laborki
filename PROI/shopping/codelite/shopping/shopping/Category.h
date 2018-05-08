//Krzysztof Blankiewicz
//Naglowki klasy Category
//Obiekt tej klasy reprezentuje kategorie
//Zawiera dane o sklepie, w ktorym warto dany produkt kupowac, oraz ile wydalismy na niego w historii.
//Jest tworzony jesli kategoria pojawi sie w zakupach.

#ifndef CATEG_H
#define CATEG_H

#include<string>

class Category
{
	std::string name;
	double spentForMe;
	Category* next;
public:	
	static Category* firstCategory;		//potrzebne do findCategory
	static Category* currentCategory;	//
	
	Category(std::string na_me);
	double getSpentForMe() const;
	std::string getName() const;
	static Category* findCategory(std::string neededName);
	void addSpending(double additionalMoney);
	Category* getNext() const;
	static void freeCategory();
};

#endif