#pragma once
#include "Graph.h"
#include "Solver.h"
#include "Path.h"
#include "DrawGraph.h"
#include <string>

class Problem
{
	std::string sourceFileName = "C:/Users/Dell/source/repos/VS projects/Thief/Debug/data.txt";
	Graph graph;
	Solver solver;
	Path result;
	DrawGraph drawing;

public:
	void prepare();
	void run();
};