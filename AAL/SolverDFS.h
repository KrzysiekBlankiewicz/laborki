#pragma once
#include "Solver.h"

class SolverDFS : public Solver
{
	bool DFS(City* currentCity, Path* currentPath, std::vector<bool> visitedCities);			// TODO nie kopiowa� vectora
	void virtual findShortestPaths(std::vector<Path>* shortestPaths);
	void virtual chooseBestPath(std::vector<Path>* shortestPaths);
public:

};

