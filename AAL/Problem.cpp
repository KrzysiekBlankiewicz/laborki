#include "Problem.h"

void Problem::prepare()
{
	graph.read(sourceFileName);
	solver.setG(&graph);

	drawing.setG(&graph);
	drawing.initialization();
}

void Problem::run()
{
	drawing.draw();
	solver.findSolution();
}
