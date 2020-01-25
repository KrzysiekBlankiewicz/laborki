#pragma once
#include <string>
#include <vector>
#include "MapSegment.h"

class DataGenerator
{
	std::string sourceFileName;
	int screenWidth = 800;
	int screenHeight = 600;
	int maxGSize = 100;
	int maxDensity = 10;
	int longestPossibleRoad = 4;

	std::vector<std::vector<MapSegment>> map;
	

	void fillMapWithCities(int mapSize);
	void markBorderCities(int abroadFactor, int mapSize);
	void writeMapToFile(int mapSize);
	int startingCityId(int mapSize);

public:
	void initialize(int w, int h, std::string fileName);
	void generateRandomData(int gSize, int density, double abroadFactor);
	void generateNiceData(int gSize, double abroadFactor);
};

