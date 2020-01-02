#include "Problem.h"

void Problem::prepare()
{
	graph.read(sourceFileName);
	solver.setG(&g);
}

void Problem::run()
{
	solver.findSolution();
}
