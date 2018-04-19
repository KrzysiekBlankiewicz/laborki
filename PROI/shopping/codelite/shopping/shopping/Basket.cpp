#include "Basket.h"
#include <iostream>

using namespace std;

	Basket::Basket(Product* pro_duct)// roboczy
	{
		product = pro_duct;
		price = 2;
		amount = 3;
	}
    Product* Basket::getProduct()
	{
		return product;
	}
    double Basket::getPrice()
	{
		return price;
	}
    int Basket::getAmount()
	{
		return amount;
	}
    int Basket::cashSpent()
	{
		return price*amount;
	}
