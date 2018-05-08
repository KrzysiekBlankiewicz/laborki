#include<Purchase.h>
#include<Product.h>
#include<iostream>
#include<fstream>
#include<string>


using namespace std;

void Purchase::setMonth(Month* newMonth)
{
	month = newMonth;
}

Purchase::Purchase(Basket* bas_ket, monthName mo_nth, string sh_op /* = "-" */)// Roboczy konstruktor, większość pól zeruje
{
	shop = sh_op;
	month = Month::findMonth(mo_nth);
	spentOnce = 0;
	basket = bas_ket;
}

void Purchase::showPurchase(ostream& os)//wyświetla dotychczas wprowadzone
{
	Basket* currentBasket = basket; 
	os<< endl << "Kupowałeś w: '" << shop << "' w " << month->getName() << "." << month->getYear() << endl;
	do{
		os<< currentBasket->getProduct()->getName() << " (" << currentBasket->getProduct()->getCategory()->getName() << ") "<< currentBasket->cashSpent()<< endl;
		currentBasket = currentBasket->getNext();
	}while(currentBasket != NULL);

}
void Purchase::acceptPurchase() // zapisuje do innych klas dane z tych zakupów
{
	Basket* currentBasket = basket;
	double spentForBasket;
	while(currentBasket != NULL){
		spentForBasket = currentBasket->cashSpent();
		currentBasket->getProduct()->addSpending(spentForBasket);                		//zwiększam wydatki na ten produkt
		if(currentBasket->getProduct()->getCategory() == NULL) cout << "null" << endl;
		currentBasket->getProduct()->getCategory()->addSpending(spentForBasket); 		// zwiększam wydatki na tę kategorię
		month->addSpending(spentForBasket);                                      		// zwiększam wydatki w tym miesiącu
		month->addToSchedule(currentBasket->getProduct()->getCategory(), spentForBasket);//zwiększam wydatki na kategorię w miesiącu
		if(currentBasket->getPrice() < currentBasket->getProduct()->getMyPrice()){
			currentBasket->getProduct()->setMyShop(shop);                        // ustawiam nowy, lepszy sklep
			currentBasket->getProduct()->setMyPrice(currentBasket->getPrice());  // ustawiam nową, lepszą cenę
		}
		currentBasket = currentBasket->getNext();
	}	
	fstream plik;
	plik.open("test.txt", ios::app);
	this->showPurchase(plik);
	plik.close();
}

void Purchase::freeBaskets()
{
	Basket* currentBasket = basket;
	Basket* nextBasket;
	while(currentBasket != NULL){
		nextBasket = currentBasket->getNext();
		delete currentBasket;
		currentBasket = nextBasket;
	}
}