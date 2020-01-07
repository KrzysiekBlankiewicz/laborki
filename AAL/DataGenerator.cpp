#include "DataGenerator.h"
#include <time.h>
#include <fstream>
#include <iostream>

void DataGenerator::initialize(int w, int h, std::string fileName)
{
	screenWidth = w;
	screenHeight = h;
	sourceFileName = fileName;
}


void DataGenerator::generateData(int gSize, int density, double abroadFactor)
{
	density = density > maxDensity ? maxDensity : density;
	gSize = gSize > maxGSize ? maxGSize : gSize;
	srand(time(0));
	int startingCity = std::rand() % (int)(gSize * (1 - abroadFactor));				//potrzebny kometarz
	std::fstream file(sourceFileName, std::ios::out);
	file << gSize << std::endl;
	for (int i = 0; i < gSize; ++i)
		file << rand() % screenWidth << " " << rand() % screenHeight << " " << 0 << " " << 0 << " " << (i < (gSize * (1 - abroadFactor)) ? 0 : 1) << std::endl;		//potrzebny kometarz
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