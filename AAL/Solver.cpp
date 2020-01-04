#include "Solver.h"
#include <windows.h>


void Solver::setG(Graph* newG)
{
	g = newG;
}


void Solver::findSolution()
{
	std::vector<Path> shortestPaths;
	findShortestPaths(&shortestPaths);
	chooseBestPath(&shortestPaths);
}
