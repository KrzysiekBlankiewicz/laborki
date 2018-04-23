#ifndef BASKET_H
#define BASKET_H
#include<Product.h>

class Basket
{
    Product* product;
    double price;
    int amount;
	Basket* next; // można tworzyć listy basketów
public:
	Basket();
	Basket(Product* pro_duct, double pri_ce, int amo_unt);
    Product* getProduct();
    double getPrice();
    int getAmount();
    double cashSpent();
	void setNext(Basket* ne_xt);
	Basket* getNext();
};


#endif // BASKET_H