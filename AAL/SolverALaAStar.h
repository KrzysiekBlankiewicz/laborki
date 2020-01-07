#pragma once
#include "Solver.h"
#include <set>

class SolverALaAStar :
	public Solver
{
	City* targetCity;

	City* closestToBorder(std::set<City*>* possibleCities);
	void findBorderCity(City* currentCity, std::set<City*>* possiblyNextCities, std::vector<int>* predecessorsTable, std::vector<int>* cityRank);
	void reconstructPath(Path* targetPath, std::vector<int>* precedessorsTable);
	void virtual findShortestPaths(std::vector<Path>* shortestPaths);
	void virtual chooseBestPath(std::vector<Path>* shortestPaths);
};

