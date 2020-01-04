#include "Problem.h"
#include <chrono>
#include <fstream>
#include <time.h>
#include "allegro5/allegro.h"	// tylko do al_rest

void Problem::prepare()
{
	graph.read(sourceFileName);
	solver.setG(&graph);

	drawing.setG(&graph);
	drawing.initialization(screenWidth, screenHeight);
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
	
	//TODO wywaliæ:
	al_rest(5);
}

long int Problem::getDuration()
{
	return duration;
}

void Problem::generateData(int gSize, int density, double abroadFactor)
{
	density = density > maxDensity ? maxDensity : density;
	gSize = gSize > maxGSize ? maxGSize : gSize;
	srand(time(0));
	int startingCity = rand() % (int)(gSize*(1 - abroadFactor));				//potrzebny kometarz
	std::fstream file(sourceFileName, std::ios::out);
	file << gSize << std::endl;
	for (int i = 0; i < gSize; ++i)
		file << rand() % screenWidth << " " << rand() % screenHeight << " " << 0 << " " << 0 << " " << (i < (gSize*(1 - abroadFactor)) ? 0 : 1) <<std::endl;		//potrzebny kometarz
	file << startingCity << std::endl;
	
	for (int i = 0; i < gSize; ++i)
	{
		for (int j = i + 1; j < gSize; ++j)
		{
			if (rand() % 10 < density)
				file << i << " " << j << std::endl;
		}
	}
	file.close();
}

void Problem::test()
{
	generateData(10, 5, 0.2);
	prepare();
	drawing.draw();
	Sleep(2000);
}
