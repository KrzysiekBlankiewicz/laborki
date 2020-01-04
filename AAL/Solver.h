#pragma once
#include "Graph.h"

class Solver
{
	Graph* g;

	void findShortestPaths(std::vector<Path>* shortestPaths);
	void chooseBestPath(std::vector<Path>* shortestPaths);
	bool DFS(City* currentCity, Path* currentPath, std::vector<bool> visitedCities);			// TODO nie kopiowaæ vectora
public:
	void setG(Graph* newG);
	void findSolution();
};

