#include<Product.h>
#include<iostream>

using namespace std;

Product* Product::firstProduct = NULL;
Product* Product::currentProduct = NULL;

Product::Product(string na_me, Category* cate_gory)
{
	if(currentProduct != NULL){
		name = na_me;
		totalSpent = 0;
		myPrice = HIPRICE;
		myCategory = cate_gory;
		currentProduct->next = this;
		currentProduct = this;
		next = NULL;
	}
	else{
		name = na_me;
		totalSpent = 0;
		myPrice = HIPRICE;
		myCategory = cate_gory;
		currentProduct = this;
		firstProduct = this;
		next = NULL;
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
Product* Product::getNext(){
	return next;
}
double Product::getTotalSpent()
{
	return totalSpent;
}

Category* Product::getCategory()
{
	return myCategory;
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

void Product::setMyShop(std::string newShop)
{
	myShop = newShop;
}

void Product::setMyPrice(double newPrice)
{
	myPrice = newPrice;
}

void Product::setCategory(Category* newCategory)
{
	myCategory = newCategory;
}

void Product::freeProducts()
{
	Product* currentProduct = firstProduct;
	Product* nextProduct;
	while(currentProduct != NULL){
		nextProduct = currentProduct->getNext();
		delete currentProduct;
		currentProduct = nextProduct;
	}
}
