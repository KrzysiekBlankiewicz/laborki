#include "Problem.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <time.h>
#include "allegro5/allegro.h"	// tylko do al_rest

void Problem::prepare()
{
	graph.read(sourceFileName);
	solver.setG(&graph);

	drawing.setG(&graph);
	drawing.initialization(screenWidth, screenHeight);

}

void Problem::run(bool allRoutes)
{
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;

	drawing.draw();
	
	begin = std::chrono::steady_clock::now();
	if (allRoutes)
	{
		std::vector<Path*> paths = *(solver.findSolutionAndDrawAll());
		for (auto a : paths)
			drawing.drawPath(a);
	}
	else
		solver.findSolution();
	end = std::chrono::steady_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();


	if (graph.getBestPath() == nullptr)
		return;

	result = *graph.getBestPath();	// TODO to powinno byæ docelowo tylko ³adniejsze
	drawing.drawPath(&result);

	// TODO dodaæ jakieœ wypluwanie wyniku

}

long int Problem::getDuration()
{
	return duration;
}

void Problem::generateRandomData(int gSize, int density, double abroadFactor)
{
	generator.initialize(screenWidth, screenHeight, sourceFileName);
	generator.generateRandomData(gSize, density, abroadFactor);
}

void Problem::generateNiceData(int gSize, double abroadFactor, bool graphicMode)
{
	if (gSize > 100 && graphicMode)
	{
		std::cout << "Zbyt du¿y problem dla tryvu graficznego" << std::endl;
		return;
	}
	generator.initialize(screenWidth, screenHeight, sourceFileName);
	generator.generateNiceData(gSize, abroadFactor, graphicMode);
}
