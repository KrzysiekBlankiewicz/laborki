#pragma once
#include "City.h"
#include <vector>

class Path
{
	std::vector<City*> cities;
public:
	std::vector<City*>* getCities();
	void addCity(City* newCity);			//mo¿e nie dodaæ miasta, a SolverDFS o tym nie wie. Przy normalnych danych zawsze doda
	void popLastCity();
};

