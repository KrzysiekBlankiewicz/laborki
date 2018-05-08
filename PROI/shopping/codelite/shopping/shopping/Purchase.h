//Krzysztof Blankewicz
//Naglowki klasy Purchase
//Obiekt tej klasy reprezentuje konkretne wyjscie na zakupy. Zawiera liste koszykow.

#ifndef PURCHASE_H
#define PURCHASE_H
#include<structures.h>
#include<Month.h>
#include<Basket.h>
#include<string>
#include<iostream>

class Purchase
{
	std::string shop;
	Basket* basket;
	Month* month;
	double spentOnce;
public:
	Purchase(Basket* bas_ket, monthName mo_nth, std::string sh_op = "-");
	void showPurchase(std::ostream& os) const; 		//wypisuje zakup do strumienia
	void acceptPurchase() const;						//wprowadza dane o zakupie do obiektow innych klas (Product, Category, Month)
 	void setMonth(Month* newMonth);
	void freeBaskets() const;
};




#endif // PURCHASE_H