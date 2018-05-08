//Krzysztof Blankiewicz
//Naglowki klasy Product
//Obiekt tej klasy reprezentuje jakiś produkt, ktory pojawil sie w zakupach. 
//Zawiera dane o sklepie, w ktorym warto dany produkt kupowac, oraz ile wydalismy na niego w historii.
//Jest tworzony jesli produkt pojawi sie w zakupach. 

#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>
#include<vector>
#include<Category.h>

const double HIPRICE = 1000;

class Product
{
    std::string name;
	Category* myCategory;
	std::string myShop;
	double myPrice;
	double totalSpent;
	Product* next;
public:
	static Product* currentProduct;		//potrzebne do findProduct
	static Product* firstProduct;		//

	Product(std::string na_me, Category* cate_gory = NULL);
    double getMyPrice() const;
	std::string getMyShop() const;
    std::string getName() const;
    Category* getCategory() const;
	double getTotalSpent() const;
	Product* getNext()const;
	
	void addSpending(double spentOnce);
	void showTotalSpent()const;
	static Product* findProduct(std::string neededName);
	void setMyShop(std::string newShop);
	void setMyPrice(double newPrice);
	void setCategory(Category* newCategory);
	static void freeProducts();
};

#endif // PRODUCT_H
