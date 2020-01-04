#include "Problem.h"
#include <chrono>

void Problem::prepare()
{
	graph.read(sourceFileName);
	solver.setG(&graph);

	drawing.setG(&graph);
	drawing.initialization();
}

void Problem::run()
{
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;

	drawing.draw();
	
	begin = std::chrono::steady_clock::now();
	solver.findSolution();
	end = std::chrono::steady_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

	result = *graph.getBestPath();
	drawing.drawPath(&result);

	Sleep(1000);
}

long int Problem::getDuration()
{
	return duration;
}
