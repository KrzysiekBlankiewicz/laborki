#ifndef BASKET_H
#define BASKET_H
#include<Product.h>

class Basket
{
    Product* product;
    double price;
    int amount;
public:
    Product* getProduct();
    double getPrice();
    int getAmount();
    int cashSpent();
};


#endif // BASKET_H