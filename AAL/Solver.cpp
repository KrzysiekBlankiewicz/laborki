#include "Solver.h"

void Solver::findShortestPaths()
{
}

void Solver::chooseBestPath()
{
}

void Solver::setG(Graph* newG)
{
	g = newG;
}

void Solver::findSolution()
{
	findShortestPaths();
	chooseBestPath();
}
