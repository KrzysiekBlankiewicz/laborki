#include "Problem.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <time.h>
#include "allegro5/allegro.h"	// tylko do al_rest


void Problem::prepare(bool graphicMode)
{
	graph.read(sourceFileName);
	graph.setMaxLootVolume(trunk);
	generator.setMaxValue(maxValue);
	generator.setMaxVolume(maxValue);
	solver.setG(&graph);
	if (graphicMode)
	{
		drawing.setG(&graph);
		drawing.initialization(screenWidth, screenHeight);
	}
}

void Problem::run(bool graphicMode)
{
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;
	
	if (graphicMode)
	{
		drawing.draw();

		begin = std::chrono::steady_clock::now();
		std::vector<Path*> paths = *(solver.findSolutionAndDrawAll());
		end = std::chrono::steady_clock::now();

		for (auto a : paths)
			drawing.drawPath(a);
		
		if (graph.getBestPath() != nullptr)
		{
			result = *graph.getBestPath();
			drawing.drawResult(&result);
		}
		al_rest(30);
	}
	else
	{
		begin = std::chrono::steady_clock::now();
		solver.findSolution();
		end = std::chrono::steady_clock::now();
	}
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

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

void Problem::writeToFile()
{
		
}


