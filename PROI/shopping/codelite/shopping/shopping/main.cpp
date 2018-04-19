// Krzysztof Blankiewicz
// Główna pętla programu do kontroli wydatków
// Na razie wprowadza i wypisuje zawartość jednych zakupów
//

#include<Basket.h>
#include<Product.h>
#include<Purchase.h>
#include<structures.h>
#include<Month.h>
#include<iostream>

using namespace std;

int main ()
{	
	Product a("marchew"), b("boczek");
	Basket x(&a), y(&b), z(&a);
	BasketList list1, list2, list3;
	list1.basket = &x;
	list1.next = &list2;
	list2.basket = &y;
	list2.next = &list3;
	list3.basket = &z;
	list3.next = NULL;
	
	Purchase TOTO(&list1);
	TOTO.showPurchase();
	
}