#include<Product.h>
#include<iostream>

using namespace std;

Product::Product(string na_me)//roboczy
{
	name = na_me;
}
double Product::getMyPrice()
{
	return myPrice;
}
string Product::getMyShop()
{
	return myShop;
}
string Product::getName()
{
	return name;
}
string Product::getCategory()
{
	return category;
}