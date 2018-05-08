//Krzysztof Blankiewicz
//Naglowki klasy Basket
//Obiekt tej klasy reprezentuje jakiś jeden produkt wrzucony do koszyka.
//Zawiera info. jaki to produkt i ile kosztowal.
//Jest tworzony przy wprowadzaniu danych o zakupach.


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
    Product* getProduct() const;
    double getPrice() const;
    int getAmount() const;
    double cashSpent() const;
	void setNext(Basket* ne_xt);
	Basket* getNext() const;
};


#endif // BASKET_H