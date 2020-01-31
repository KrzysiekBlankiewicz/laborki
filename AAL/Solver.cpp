#include "Solver.h"
#include <windows.h>


void Solver::setG(Graph* newG)
{
	g = newG;
}


void Solver::findSolution()
{
	if (g->getBorderline()->empty())
		return;
	std::vector<Path*> shortestPaths;
	findShortestPaths(&shortestPaths);
	chooseBestPath(&shortestPaths);

	for (Path* a : shortestPaths)
		delete a;
}

std::vector<Path*>* Solver::findSolutionAndDrawAll()
{
	std::vector<Path*>* shortestPaths = new std::vector<Path*>;
	findShortestPaths(shortestPaths);
	chooseBestPath(shortestPaths);
	return shortestPaths;
}
