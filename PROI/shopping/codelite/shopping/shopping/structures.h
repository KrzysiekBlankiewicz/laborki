#ifndef STRUCT_H
#define STRUCT_H

#include<Basket.h>
#include<string>

struct SpendingShedule
{
	Category* category;
	double money;
	
	SpendingShedule(Category* cate_gory, double mon_ey = 0);
};
#endif