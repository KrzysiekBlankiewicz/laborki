#ifndef PURCHASE_H
#define PURCHASE_H
#include<structures.h>
#include<Month.h>
#include<Basket.h>
#include<string>

class Purchase
{
	std::string shop;
	Basket* basket;
	//Month* month;
	double spentOnce;
public:
	Purchase(Basket* bas_ket, std::string sh_op = "-");
	void showPurchase();
	void acceptPurchase();
};




#endif // PURCHASE_H