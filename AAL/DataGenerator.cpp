#include "DataGenerator.h"
#include <time.h>
#include <fstream>
#include <iostream>

void DataGenerator::fillMapWithCities(int mapSize)
{

	int currentId = 0;

	map.resize(mapSize);
	for (std::vector<std::vector<MapSegment>>::iterator i = map.begin(); i < map.end(); ++i)
		i->resize(mapSize);

	for (std::vector<std::vector<MapSegment>>::iterator i = map.begin(); i < map.end(); ++i)
		for (std::vector<MapSegment>::iterator j = i->begin(); j < i->end(); ++j)
		{
			if (rand() % 2 == 1)
			{
				j->setFull(true);
				j->setCityId(currentId);
				++currentId;
				++MapSegment::citiesQuantity;
			}
			else
				j->setFull(false);
		}
}

void DataGenerator::markBorderCities(int abroadFactor, int mapSize)
{
	int firstInRow = -1;
	int lastInRow = -1;

	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i][j].isFull())
			{
				lastInRow = j;
				if (firstInRow == -1)
					firstInRow = j;
			}
		}
		if(firstInRow != -1 && firstInRow < abroadFactor)				//abroadFactor oznacza ile kolumn jest zagranicznych
			map[i][firstInRow].setBorder(true);							//	dla abroadFactor == 1, tylko 0 i ostatnia kolumna
		if(lastInRow != -1 && lastInRow >= mapSize - abroadFactor)		//
			map[i][lastInRow].setBorder(true);
		firstInRow = lastInRow = -1;
	}
}

void DataGenerator::writeMapToFile(int mapSize, bool graphicMode)
{
	int segmentHeight;
	int segmentWidth;
	if (graphicMode)
	{
		segmentHeight = screenHeight / mapSize;
		segmentWidth = screenWidth / mapSize;
	}
	else
	{
		segmentHeight = mapSize;
		segmentWidth = mapSize;
	}

	std::fstream file(sourceFileName, std::ios::out);
	
	file << MapSegment::citiesQuantity << std::endl;

	for (int i = 0; i < map.size(); ++i)
		for (int j = 0; j < map[i].size(); ++j)
			if (map[i][j].isFull())
			{
				file << segmentWidth * j + rand() % segmentWidth << " ";
				file << segmentHeight * i + rand() % segmentHeight << " ";
				file << 0 << " " << 0 << " ";
				file << map[i][j].getBorder() << std::endl;					// getBorder zwraca bool'a, który siê konwertuje na informacjê, czy miasto jest za granic¹ (1), czy nie (0)
			}
	file << startingCityId(mapSize) << std::endl;

	for (int i = 0; i < map.size(); ++i)				// potrójnie zagnie¿d¿ona pêtla wyznacza krawêdzie grafu
		for (int j = 0; j < map[i].size(); ++j)			// miasto mo¿e byæ po³¹czone tylko z 4 s¹siednimi
			if (map[i][j].isFull())						// s¹siednimi w sensie z s¹siednich segmentów
			{
				for (int k = i + 1; k < map.size(); ++k)
				{
					if (map[k][j].isFull())
					{
						file << map[i][j].getCityId() << " " << map[k][j].getCityId() << std::endl;
						break;
					}
					if (k - i > longestPossibleRoad)
						break;
				}
				for (int l = j + 1; l < map[i].size(); ++l)
				{
					if (map[i][l].isFull())
					{
						file << map[i][j].getCityId() << " " << map[i][l].getCityId() << std::endl;
						break;
					}
					if (l - j > longestPossibleRoad)
						break;
				}
			}
	file.close();
}

int DataGenerator::startingCityId(int mapSize)
{
	int tempI = mapSize / 2;
	int tempJ = mapSize / 2;
	while (1)
	{
		if (tempI >= mapSize || tempI <= 0)
			tempI = mapSize / 2;
		if (tempJ >= mapSize || tempJ <= 0)
			tempJ = mapSize / 2;
		if (map[tempI][tempJ].isFull() && !map[tempI][tempJ].getBorder())
			return map[tempI][tempJ].getCityId();
		switch (rand() % 4)
		{
		case 0: ++tempI;
		case 1: --tempI;
		case 2: ++tempJ;
		case 3: --tempJ;
		}
	}
}

void DataGenerator::initialize(int w, int h, std::string fileName)
{
	screenWidth = w;
	screenHeight = h;
	sourceFileName = fileName;
}

/*
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
*/

void DataGenerator::generateRandomData(int gSize, int density, double abroadFactor)
{
	density = density > maxDensity ? maxDensity : density;
	gSize = gSize > maxGSize ? maxGSize : gSize;
	srand(time(0));
	int startingCity = std::rand() % gSize;											// starting City jest ca³kiem losowe...
	std::fstream file(sourceFileName, std::ios::out);
	file << gSize << std::endl;
	
	int pointX, pointY;
	for (int i = 0; i < gSize; ++i)
	{
		pointX = rand() % screenWidth;
		pointY = rand() % screenHeight;
			file << pointX << " " << pointY << " " << 0 << " " << 0 << " ";
			if (i == startingCity)													//...dlatego upewniam siê tutaj, ¿e nie bêdzie ono za granic¹
			{
				file << 0 << std::endl;
				continue;
			}
			if (pointX < screenWidth * abroadFactor || pointX > screenWidth * (1 - abroadFactor)
				|| pointY < screenHeight * abroadFactor || pointY > screenHeight * (1 - abroadFactor))
				file << 1 << std::endl;																	// 1 oznacza zagranicê, jest wpisywana jeœli miasto jest w odleg³oœci abroadFactor od krawêdzi ekranu
			else
				file << 0 << std::endl;
	}
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

void DataGenerator::generateNiceData(int gSize, double abroadFactor, bool graphicMode)
{
	srand(time(0));
	fillMapWithCities(gSize);
	markBorderCities(abroadFactor, gSize);
	writeMapToFile(gSize, graphicMode);
}
