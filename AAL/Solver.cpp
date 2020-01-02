#include "Solver.h"
#include <windows.h>

void Solver::findShortestPaths()
{
	Sleep(5000);
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
