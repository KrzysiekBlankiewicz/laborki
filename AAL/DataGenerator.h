#pragma once
#include <string>

class DataGenerator
{
	std::string sourceFileName;
	int screenWidth = 800;
	int screenHeight = 600;
	int maxGSize = 100;
	int maxDensity = 10;
public:
	void initialize(int w, int h, std::string fileName);
	void generateData(int gSize, int density, double abroadFactor);
};

