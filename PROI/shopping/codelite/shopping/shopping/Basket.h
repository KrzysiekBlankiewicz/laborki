#ifndef BASKET_H
#define BASKET_H

#include<Product.h>
#include<Category.h>

class Basket
{
    Product* product;
    double price;
    int amount;
	Basket* next; // można tworzyć listy basketów
public:
	Basket(Product* pro_duct, double pri_ce = 1, int amo_unt = 1);
    Product* getProduct();
    double getPrice();
    int getAmount();
    double cashSpent();
	void setNext(Basket* ne_xt);
	Basket* getNext();
};


#endif // BASKET_H