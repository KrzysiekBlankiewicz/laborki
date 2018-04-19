#include<Purchase.h>
#include<iostream>
#include<string>

using namespace std;

Purchase::Purchase(BasketList* shopping_List)// Roboczy konstruktor, większość pól zeruje
{
	shop = "";
	month = NULL;
	spentOnce = 0;
	shoppingList = shopping_List;
}

void Purchase::showPurchase()//wyświetla dotychczas wprowadzone
{
	BasketList* currentBasket = shoppingList;
	cout<< "Kupowałeś w " << shop << endl;
	while(currentBasket != NULL){
		cout<< currentBasket->basket->getProduct()->getName() << " " << currentBasket->basket->cashSpent()<< endl;
		currentBasket = currentBasket->next;
	}
}
//void Purchase::acceptPurchase();