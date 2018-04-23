#ifndef PRODUCT_H
#define PRODUCT_H
//#define Category int

#include<string>

class Product
{
    std::string name;
    //std::string category; // na razie nie obsługuje kategorii
	std::string myShop;
	double myPrice;
	double totalSpent;
	Product* next;
public:
	static Product* currentProduct;
	static Product* firstProduct;

	Product(std::string na_me);
    double getMyPrice();
	std::string getMyShop();
    std::string getName();
    std::string getCategory();
	double getTotalSpent();
	void addSpending(double spentOnce);
	void showTotalSpent();
	Product* findProduct(std::string neededName);
};

#endif // PRODUCT_H
