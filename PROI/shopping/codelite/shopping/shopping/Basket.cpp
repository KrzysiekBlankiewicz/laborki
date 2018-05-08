#include "Basket.h"
#include <iostream>

using namespace std;

	Basket::Basket(Product* pro_duct, double pri_ce, int amo_unt)// roboczy
	{
		product = pro_duct;
		price = pri_ce;
		amount = amo_unt;
		next = NULL;
	}
    Product* Basket::getProduct() const
	{
		return product;
	}
    double Basket::getPrice() const
	{
		return price;
	}
    int Basket::getAmount() const
	{
		return amount;
	}
    double Basket::cashSpent() const
	{
		return price*amount;
	}
	void Basket::setNext(Basket* ne_xt)
	{
		next = ne_xt;
	}
	Basket* Basket::getNext() const
	{
		return next;
	}
