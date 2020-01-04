#pragma once
#include "Graph.h"

class Solver
{
protected:

	Graph* g;

	void virtual findShortestPaths(std::vector<Path>* shortestPaths) = 0;
	void virtual chooseBestPath(std::vector<Path>* shortestPaths) = 0;
public:
	void setG(Graph* newG);
	void findSolution();
};

