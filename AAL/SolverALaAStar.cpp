#include "SolverALaAStar.h"
#include <set>
#include <iostream>


void SolverALaAStar::findBorderCity(City* currentCity, std::set<City*>* possiblyNextCities, std::vector<int>* predecessorsTable, std::vector<int>* cityRank)
{
	// TODO zmieniæ jka poni¿ej
	// przekazywaæ poziom zagnie¿d¿enia
	// jak znajdê granicê, to dokoñczyæ szukaj¹c wszerz "bez pog³êbiania"
	// wrzucaæ wszystkie znalezione cele do vektora 
	// potem oddtworzê œcie¿ki for each w vektorze

	if (currentCity == nullptr || currentCity->isOnBorder())
	{
		targetCity = currentCity;
		return;
	}

	for (auto a : *(currentCity->getEgdes()))
	{
		if ((*cityRank)[a->getId()] == INT16_MAX)
		{
			possiblyNextCities->insert(a);
			(*predecessorsTable)[a->getId()] = currentCity->getId();
			(*cityRank)[a->getId()] = (*cityRank)[currentCity->getId()] + 1;
		}
		// TODO tu powinno siê dodaæ poprawianie rang w przypadku spotkania ju¿ sprawdzonego miasta
	}
	possiblyNextCities->erase(currentCity);

	City* nextCity = closestToBorder(possiblyNextCities);

	findBorderCity(nextCity, possiblyNextCities, predecessorsTable, cityRank);
}

City* SolverALaAStar::closestToBorder(std::set<City*>* possibleCities)
{
	City* closestCity = nullptr;
	double minDistanceToBorder = INT16_MAX;
	double tempDistance = 0;
	for (auto a : *possibleCities)
	{
		for (auto b : *(g->getBorderline()))
		{
			// TODO wywaliæ to: 
			//std::cout << b->getId() << " " << a->getId() << " " << b->getDistance(a) << std::endl;
			tempDistance = a->getDistance(b);
			if (tempDistance < minDistanceToBorder)
			{
				closestCity = a;
				minDistanceToBorder = tempDistance;
			}
		}
	}
	return closestCity;
}

void SolverALaAStar::reconstructPath(Path* targetPath, std::vector<int>* precedessorsTable)
{
	int startingCityId = g->getStartingCity()->getId();
	City* tempCity = targetCity;
	std::vector<City*> tempVect;

	do
	{
		if (tempCity == nullptr)
			return;
		tempVect.push_back(tempCity);
		tempCity = (*(g->getCities()))[(*precedessorsTable)[tempCity->getId()]];
	} while (tempCity->getId() != startingCityId);
	tempVect.push_back(tempCity);													// tu dodajê startingCity którego nie doda³a pêtla

	for (std::vector<City*>::reverse_iterator i = tempVect.rbegin(); i < tempVect.rend(); ++i)
	{
		targetPath->addCity(*i);
	}
}

void SolverALaAStar::findShortestPaths(std::vector<Path>* shortestPaths)
{
	City* currentCity;
	currentCity = g->getStartingCity();
	if (currentCity == nullptr)
		return;													// TODO przy pora¿ce nic nie robiê

	std::set<City*> possiblyNextCities;

	std::vector<int> predecessorsTable;
	predecessorsTable.resize(g->getCities()->size(), -1);

	std::vector<int> cityRank;
	for (int i = 0; i < cityRank.size(); ++i)
		cityRank[i] = INT16_MAX;
	cityRank.resize(g->getCities()->size(), INT16_MAX);
	cityRank[currentCity->getId()] = 0;

	
	findBorderCity(currentCity, &possiblyNextCities, &predecessorsTable, &cityRank);		// algorytm a la A*
	// TODO sprawdzaj czy algrytm siê nie wysypa³

	reconstructPath(g->getBestPath(), &predecessorsTable);
}

void SolverALaAStar::chooseBestPath(std::vector<Path>* shortestPaths)
{
	// TODO
}
