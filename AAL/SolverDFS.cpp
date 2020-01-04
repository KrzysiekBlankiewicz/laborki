#include "SolverDFS.h"

void SolverDFS::findShortestPaths(std::vector<Path>* shortestPaths)
{
	City* startingCity = g->getStartingCity();
	Path myPath;
	myPath.addCity(startingCity);

	std::vector<bool> visitedOrNot;
	for (auto a : visitedOrNot)
		a = false;
	visitedOrNot.resize(g->getCities()->size(), false);

	DFS(startingCity, &myPath, visitedOrNot);
	(*shortestPaths).push_back(myPath);
}

void SolverDFS::chooseBestPath(std::vector<Path>* shortestPaths)
{
	// TODO prowizorka:
	Path* xxx = g->getBestPath();
	std::vector<Path> v = *shortestPaths;
	*xxx = v[0];
}

bool SolverDFS::DFS(City* currentCity, Path* currentPath, std::vector<bool> visitedCities)
{
	if (visitedCities[currentCity->getId()])
		return false;
	else
		visitedCities[currentCity->getId()] = true;

	if (currentCity->isOnBorder())
		return true;
	else
	{
		for (auto a : *(currentCity->getEgdes()))
		{
			currentPath->addCity(a);
			if (DFS(a, currentPath, visitedCities))
				return true;
			else
				currentPath->popLastCity();
		}
		return false;
	}
}