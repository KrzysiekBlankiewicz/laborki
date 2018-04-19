#ifndef PURCHASE_H
#define PURCHASE_H
#include<structures.h>
#include<Month.h>
#include<Basket.h>
#include<string>

class Purchase
{
	std::string shop;
	BasketList* shoppingList;
	Month* month;
	double spentOnce;
public:
	Purchase(BasketList* shopping_List);
	void showPurchase();
	void acceptPurchase();
};




#endif // PURCHASE_H