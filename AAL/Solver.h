#pragma once
#include "Graph.h"

class Solver
{
	Graph* g;
	std::vector<Path> shortestPaths;

	void findShortestPaths();
	void chooseBestPath();

public:
	void setG(Graph* newG);
	void findSolution();
};

