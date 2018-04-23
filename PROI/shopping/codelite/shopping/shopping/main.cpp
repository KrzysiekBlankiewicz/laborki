// Krzysztof Blankiewicz
// Główna pętla programu do kontroli wydatków
// Na razie wprowadza z pliku test.txt i wypisuje zawartość jednych zakupów
//

#include<Basket.h>
#include<Product.h>
#include<Purchase.h>
#include<structures.h>
#include<Month.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main ()
{	
	
	Product a("marchew"), b("boczek"); // tworzy przykładowe produkty
	int amount;
	double price;
	string productName;
	Basket x(&a, 1, 1);
	Basket* basketPtr1 = &x;
	Basket* basketPtr2;
	/*for(int i = 0; i < 1; i++){ // do wprowadzania basketów z cin
		cin >> productName >> price >> amount;
		basketPtr2 = new Basket(a.findProduct(productName), price, amount);
		basketPtr1->setNext(basketPtr2);
		basketPtr1 = basketPtr2;
	}
	*/
	fstream plik;
	plik.open("test.txt");
	for(int i = 0; i < 5; i++){ // czyta z pliku 5 linii. Każda to kolejny basket
		plik >> productName >> price >> amount;
		basketPtr2 = new Basket(a.findProduct(productName), price, amount);
		basketPtr1->setNext(basketPtr2);
		basketPtr1 = basketPtr2;	
	}
	plik.close();
	
	Purchase TOTO(&x); 
	TOTO.showPurchase(); //wypisuje na cout zawrtość jednych zakupów
	
}