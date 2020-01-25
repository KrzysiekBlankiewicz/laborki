#pragma once
#include "Graph.h"
#include "Solver.h"
#include "SolverDFS.h"
#include "SolverALaAStar.h"
#include "Path.h"
#include "DrawGraph.h"
#include "DataGenerator.h"
#include <string>

class Problem
{
	std::string sourceFileName = "C:/Users/Dell/source/repos/VS projects/Thief/Debug/data.txt";
	int screenWidth = 1100;
	int screenHeight = 700;

	DataGenerator generator;
	Graph graph;
	SolverDFS solver;
	Path result;
	DrawGraph drawing;
	long int duration;

public:
	void prepare();
	void run(bool allRoutes);
	long int getDuration();
	void generateRandomData(int gSize, int density, double abroadFactor);
	void generateNiceData(int gSize, double abroadFactor);
};