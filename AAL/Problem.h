#pragma once
#include "Graph.h"
#include "Solver.h"
#include "SolverBFS.h"
#include "SolverALaAStar.h"
#include "Path.h"
#include "DrawGraph.h"
#include "DataGenerator.h"
#include <string>

class Problem
{
	std::string sourceFileName = ".//data.txt";
	int screenWidth = 1100;
	int screenHeight = 700;
	int trunk = 50;
	int maxValue = 100;
	int maxVolume = 50;

	DataGenerator generator;
	Graph graph;
	SolverBFS solver;
	Path result;
	DrawGraph drawing;
	long int duration;

public:
	void prepare(bool graphicMode);
	void run(bool allRoutes);
	long int getDuration();
	void generateRandomData(int gSize, int density, double abroadFactor);
	void generateNiceData(int gSize, double abroadFactor, bool graphicMode);
	void writeToFile();
};