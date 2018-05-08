// Krzysztof Blankiewicz
// Główna pętla programu do kontroli wydatków
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
								//Dla wygody tworzę jeden:
	Product bag("torebka");		//...produkt
	Category some("inne");		//...kategorię
	bag.setCategory(&some);		// (przypisuję produktowi kategorię)
	Basket firstBasket(&bag, 1, 0); //...koszyk
	Purchase zakup(&firstBasket, JAN, "domowy"); // zakup, na którym będę operował (to jest jedyny obiekt klasy Purchase)
	Basket* basket1 = &firstBasket; //basket1 zawsze jest pierwszym koszykiem w 'zakup'
	Basket* basket2;				//pomocniczy, do przełączania koszyków	
	
	int amount;							//kontenery na dane wprowadzone z konsoli
	double price;						//	
	string productName;					//	
	string categoryName;				//
	int basketsAmount;					//
	monthName monthOfPurchase;			//
	int yearOfPurchase;					//
	string contin = "help", assistance; //pomocnicze, potrzebne do cin-ów
	int assistance1;					//pomocnicze, potrzebne do cin-ów
	
	while(contin != "koniec"){
		if(contin == "help"){
			cout << "-----------------------------------------------------" << endl;
			cout << "Wprowadź...		 ...aby:" << endl;
			cout << "	zakupy 			dodać nowy zakup" << endl;
			cout << "	koniec 			zakończyć" << endl;
			cout << "	pokaz_mies		wyświetlic wydatki wedlug miesiecy" << endl;
			cout << "	pokaz_kateg		wyświetlic wydatki wedlug kategorii" << endl;
			cout << "	pokaz_prod		wyświetlic wydatki wedlug produktow" << endl;
			cout << "	gdzie_kupic		sprawdzic gdzie oplaca się kupowcć" << endl;
			cout << "	pokaz_rok		wyświetlic wydatki według lat" << endl;
			cout << "	zapis_last		zapisac ostatni zakup do pliku" << endl;
			cout << "-----------------------------------------------------" << endl;
		}
		else if(contin == "zakupy"){
			firstBasket.setNext(NULL);
			basket1 = &firstBasket;
			cout << "W formacie: Miesiąc Rok LiczbaProduktow " << endl;
			cin >> monthOfPurchase >> yearOfPurchase >> basketsAmount;
			zakup.setMonth(Month::findMonth(monthOfPurchase, yearOfPurchase));
			cout << "Teraz po jednym: Nazwa Cena Ilosc" << endl;
			for(int i = 0; i < basketsAmount; i++){ // do wprowadzania basketów z cin
				cin >> productName >> price >> amount;
				basket2 = new Basket(Product::findProduct(productName), price, amount);
				if(basket2->getProduct()->getCategory() == NULL){
					cout << "Poprosze o nazwę kategorii:" << endl;
					cin >> categoryName;
					basket2->getProduct()->setCategory(Category::findCategory(categoryName));
				}
				basket1->setNext(basket2);
				basket1 = basket2;
			}
			zakup.showPurchase(cout);	
			cout << "Zaakceptowac? ------( tak/cokolwiekinnego=nie )------" << endl;
			cin >> assistance;
			if(assistance == "tak")
				zakup.acceptPurchase();
			zakup.freeBaskets();
		}
		else if(contin == "pokaz_kateg"){
			Category* category = Category::firstCategory;
			while(category != NULL){
				cout << category->getName() << "  "<< category->getSpentForMe() << endl;
				category = category->getNext();
			}
		}
		else if(contin == "pokaz_mies"){
			Month* month = Month::firstMonth;
			while(month != NULL){
				cout << "	" << month->getName() << "  "<< month->getSpentInMonth() << endl;
				month = month->getNext();
			}
		}
		else if(contin == "pokaz_prod"){
			Product* product = Product::firstProduct;
			while(product != NULL){
				cout << "	" << product->getName() << "  "<< product->getTotalSpent() << endl;
				product = product->getNext();
			}
		}
		else if(contin == "pokaz_rok"){
			cout << "Ktory rok?" << endl;
			cin >> assistance1;
			cout << "	Wydales " << Month::spentInYear(assistance1) << endl;
		}
		else if(contin == "gdzie_kupic"){
			cout << "Jaki produkt?" << endl;
			cin >> assistance;
			if(Product::findProduct(assistance)->getMyShop() == "") cout << "Brakuje mi danych..." << endl;
			else cout << "Najtaniej w '" << Product::findProduct(assistance)->getMyShop() << "'" << endl;
		}
		else cout << "Bledna instrukcja, ale..." << endl;
		cout << endl << "Slucham...";
		cin >> contin;
		cout << endl;
	}
	Month::freeMonths();
	Category::freeCategory();
	Product::freeProducts();
}