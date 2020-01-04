#include "Path.h"

std::vector<City*>* Path::getCities()
{
	return &cities;
}

void Path::addCity(City* newCity)
{
	if (cities.size() == 0) {
		cities.push_back(newCity);
		return;
	}
	City* lastOnPath = cities[cities.size() - 1];
	if (lastOnPath->isNeighbour(newCity))
		cities.push_back(newCity);
}

void Path::popLastCity()
{
	cities.pop_back();
}
