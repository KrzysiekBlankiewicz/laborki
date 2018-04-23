#include<Purchase.h>
#include<Month.h>
#include<Product.h>
#include<iostream>
#include<string>

using namespace std;

Purchase::Purchase(Basket* bas_ket, string sh_op /* = "-" */)// Roboczy konstruktor, większość pól zeruje
{
	shop = "";
	//month = findMonth;
	spentOnce = 0;
	basket = bas_ket;
}

void Purchase::showPurchase()//wyświetla dotychczas wprowadzone
{
	Basket* currentBasket = basket;
	cout<< "Kupowałeś w " << shop << endl;
	do{
		cout<< currentBasket->getProduct()->getName() << " " << currentBasket->cashSpent()<< endl;
		currentBasket = currentBasket->getNext();
	}while(currentBasket != NULL);
}
void Purchase::acceptPurchase() // zapisuje do innych klas dane  z tych zakupów
{
	Basket* currentBasket = basket;
	while(currentBasket != NULL){
		currentBasket->getProduct()->addSpending(currentBasket->cashSpent());
		currentBasket = currentBasket->getNext();
	}
}