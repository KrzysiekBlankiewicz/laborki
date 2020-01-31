#pragma once
#include "City.h"
#include <vector>

class Path
{
	std::vector<City*> cities;
public:
	std::vector<City*>* getCities();
	void addCity(City* newCity);
	void popLastCity();
};