#include "Basket.h"
#include <iostream>

using namespace std;

    //Product* get_product();
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
