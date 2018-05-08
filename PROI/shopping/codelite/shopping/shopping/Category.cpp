#include<Category.h>

using namespace std;

Category* Category::firstCategory = NULL;
Category* Category::currentCategory = NULL;

Category::Category(string na_me)
{
	if(currentCategory != NULL){
		name = na_me;
		spentForMe = 0;
		currentCategory->next = this;
		currentCategory = this;
		next = NULL;
	}
	else{
		name = na_me;
		spentForMe = 0;
		currentCategory = this;
		firstCategory = this;
		next = NULL;
	}
}

double Category::getSpentForMe()
{
		return spentForMe;
}

string Category::getName()
{
	return name;
}

Category* Category::findCategory(string neededName)
{
	Category* tempCategory = firstCategory;
	while(tempCategory != NULL){
		if(tempCategory->name == neededName)
			return tempCategory;
		else
			tempCategory = tempCategory->next;
	}
	Category* newCategory = new Category(neededName);
	return newCategory;
}

void Category::addSpending(double additionalMoney)
{
	spentForMe += additionalMoney;
}

Category* Category::getNext()
{
	return this->next;
}

void Category::freeCategory()
{
	Category* currentCategory = firstCategory;
	Category* nextCategory;
	while(currentCategory != NULL){
		nextCategory = currentCategory->getNext();
		delete currentCategory;
		currentCategory = nextCategory;
	}
}