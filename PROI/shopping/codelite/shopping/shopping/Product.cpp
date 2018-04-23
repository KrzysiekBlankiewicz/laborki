#include<Product.h>
#include<iostream>

using namespace std;

Product* Product::firstProduct = NULL;
Product* Product::currentProduct = NULL;

Product::Product(string na_me)//roboczy
{
	if(currentProduct != NULL){
		name = na_me;
		currentProduct->next = this;
		currentProduct = this;
		next = NULL;
	}
	else{
		name = na_me;
		currentProduct = this;
		firstProduct = this;
	}
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
/*string Product::getCategory() //chwilowo działam bez kategorii
{
	return category;
}*/
double Product::getTotalSpent()
{
	return totalSpent;
}
void Product::addSpending(double spentOnce)
{
	totalSpent += spentOnce;
}
Product* Product::findProduct(string neededName)
{
	Product* currentProduct = Product::firstProduct;
	while(currentProduct != NULL){
		if(currentProduct->getName() == neededName) return currentProduct;
		else currentProduct = currentProduct->next;
	}
	Product* newProduct= new Product(neededName);
	return newProduct;
}
