#pragma once
#include "Graph.h"
#include "Solver.h"
#include "SolverDFS.h"
#include "Path.h"
#include "DrawGraph.h"
#include <string>

class Problem
{
	std::string sourceFileName = "C:/Users/Dell/source/repos/VS projects/Thief/Debug/data.txt";
	Graph graph;
	SolverDFS solver;
	Path result;
	DrawGraph drawing;
	long int duration;

public:
	void prepare();
	void run();
	long int getDuration();
};