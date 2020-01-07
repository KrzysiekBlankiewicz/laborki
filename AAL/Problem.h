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
	int screenWidth = 800;
	int screenHeight = 600;

	DataGenerator generator;
	Graph graph;
	SolverALaAStar solver;
	Path result;
	DrawGraph drawing;
	long int duration;

public:
	void prepare();
	void run();
	long int getDuration();
	void generateData(int gSize, int density, double abroadFactor);
	void test();
};