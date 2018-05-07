// Krzysztof Blankiewicz
// Główna pętla programu do kontroli wydatków
// 
//

#include<Basket.h>
#include<Product.h>
#include<Purchase.h>
#include<structures.h>
#include<Month.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

int main ()
{	
	/*
	Category x("pieczywo"), y("warzywa"), z("nabiał");
	Month j(JAN), f(FEB), m(MAR);
	
	j.addToSchedule(&x, 10);
	j.addToSchedule(&x, 20);
	j.addToSchedule(&y, 8);
	
	j.showSpendings();
	Basket some(Product::findProduct("wtb"), 1, 1);
	Purchase purchase(&some, MAR, "spolem");
	purchase.showPurchase();
	purchase.acceptPurchase();
	cout << x.getSpentForMe() << endl;
	
	*/
	
	Product bag("torebka");
	Category some("inne");
	bag.setCategory(&some);
	Basket firstBasket(&bag, 1, 0);
	Purchase zakup(&firstBasket, JAN, "domowy");
	
	Basket* basket1 = &firstBasket;
	Basket* basket2;
	int amount;
	double price;
	string productName;
	string categoryName;
	int basketsAmount;
	monthName monthOfPurchase;
	int yearOfPurchase;
	
	string contin = "help", assistance; //pomocnicze, potrzebne do cin-ów
	int assistance1;					//pomocnicze, potrzebne do cin-ów
	
	while(contin != "koniec"){
		if(contin == "help"){
			cout << "-----------------------------------------------------" << endl;
			cout << "Wprowadź...		 ...aby:" << endl;
			cout << "	zakupy 			dodać nowy zakup" << endl;
			cout << "	koniec 			zako/ńczyć" << endl;
			cout << "	pokaz_mies		wyświetlić wydatki według miesięcy" << endl;
			cout << "	pokaz_kateg		wyświetlić wydatki według kategorii" << endl;
			cout << "	pokaz_prod		wyświetlić wydatki według produktów" << endl;
			cout << "	gdzie_kupić		sprawdzić gdzie opłaca się kupować" << endl;
			cout << "	pokaz_rok		wyświetlić wydatki według lat" << endl;
			cout << "-----------------------------------------------------" << endl;
		}
		if(contin == "zakupy"){
			firstBasket.setNext(NULL);
			basket1 = &firstBasket;
			cout << "W formacie: Miesiąc Rok LiczbaProduktów " << endl;
			cin >> monthOfPurchase >> yearOfPurchase >> basketsAmount;
			zakup.setMonth(Month::findMonth(monthOfPurchase, yearOfPurchase));
			cout << "Teraz po jednym: Nazwa Cena Ilość" << endl;
			for(int i = 0; i < basketsAmount; i++){ // do wprowadzania basketów z cin
				cin >> productName >> price >> amount;
				basket2 = new Basket(bag.findProduct(productName), price, amount);
				if(basket2->getProduct()->getCategory() == NULL){
					cout << "Poproszę o nazwę kategorii:" << endl;
					cin >> categoryName;
					basket2->getProduct()->setCategory(Category::findCategory(categoryName));
				}
				basket1->setNext(basket2);
				basket1 = basket2;
			}
			zakup.showPurchase(cout);
			cout << "Zaakceptować? ------( tak/cokolwiekinnego=nie )------" << endl;
			cin >> assistance;
			if(assistance == "tak")
				zakup.acceptPurchase();
		}
		if(contin == "pokaz_kateg"){
			Category* category = Category::firstCategory;
			while(category != NULL){
				cout << category->getName() << "  "<< category->getSpentForMe() << endl;
				category = category->getNext();
			}
		}
		if(contin == "pokaz_mies"){
			Month* month = Month::firstMonth;
			while(month != NULL){
				cout << month->getName() << "  "<< month->getSpentInMonth() << endl;
				month = month->getNext();
			}
		}
		if(contin == "pokaz_prod"){
			Product* product = Product::firstProduct;
			while(product != NULL){
				cout << product->getName() << "  "<< product->getTotalSpent() << endl;
				product = product->getNext();
			}
		}
		if(contin == "pokaz_rok"){
			cout << "Który rok?" << endl;
			cin >> assistance1;
			cout << Month::spentInYear(assistance1) << endl;
		}
		if(contin == "gdzie_kupić"){
			cout << "Jaki produkt?" << endl;
			cin >> assistance;
			if(Product::findProduct(assistance)->getMyShop() == "") cout << "Brakuje mi danych..." << endl;
			else cout << "Najtaniej w '" << Product::findProduct(assistance)->getMyShop() << "'" << endl;
		}		
		cout << endl << "Słucham...";
		cin >> contin;
		cout << endl;
	}
	//cout << Product::findProduct("d")->getTotalSpent();
	//cout << Product::findProduct("d")->getMyShop() <<  Product::findProduct("d")->getMyPrice();
	
	/*Product a("torebka");
	int basketsNumber;
	int amount;
	double price;
	string productName;
	Basket x(&a, 1, 1);
	Basket* basketPtr1;
	Basket* basketPtr2;
	Purchase* currentPurchase;
	for(int i = 0; i < 1; i++){ // do wprowadzania basketów z cin
		cin >> productName >> price >> amount;
		basketPtr2 = new Basket(a.findProduct(productName), price, amount);
		basketPtr1->setNext(basketPtr2);
		basketPtr1 = basketPtr2;
	}
	
	fstream plik;
	plik.open("test.txt");
	
	while(!plik.eof()){
					cout << "f" << endl;

		basketPtr1 = new Basket(&a, 0, 1);
		currentPurchase = new Purchase(basketPtr1);
		plik >> basketsNumber;
		for(int i = 0; i < basketsNumber; i++){ // czyta z pliku 5 linii. Każda to kolejny basket
			plik >> productName >> price >> amount;
			basketPtr2 = new Basket(a.findProduct(productName), price, amount);
			basketPtr1->setNext(basketPtr2);
			basketPtr1 = basketPtr2;	
		}
		currentPurchase->showPurchase();
	}
	plik.close();
	
	Purchase TOTO(&x); 
	TOTO.showPurchase(); //wypisuje na cout zawrtość jednych zakupów
	*/
}