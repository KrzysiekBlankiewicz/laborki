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
	static Product* currentProduct;
	static Product* firstProduct;

	Product(std::string na_me, Category* cate_gory = NULL);
    double getMyPrice();
	std::string getMyShop();
    std::string getName();
    Category* getCategory();
	double getTotalSpent();
	Product* getNext();
	
	void addSpending(double spentOnce);
	void showTotalSpent();
	static Product* findProduct(std::string neededName);
	void setMyShop(std::string newShop);
	void setMyPrice(double newPrice);
	void setCategory(Category* newCategory);
};

#endif // PRODUCT_H
