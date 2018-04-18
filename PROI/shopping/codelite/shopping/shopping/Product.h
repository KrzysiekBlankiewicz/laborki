#ifndef PRODUCT_H
#define PRODUCT_H
//#define Category int

#include<string>

class Product
{
    std::string name;
    std::string category;
	std::string myShop;
	double myPrice;
public:
    double getMyPrice();
	std::string getMyShop();
    std::string getName();
    std::string getCategory();
};

#endif // PRODUCT_H
