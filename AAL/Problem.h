#pragma once
#include "Graph.h"
#include "Solver.h"
#include "Path.h"

class Problem
{
	std::string sourceFileName = "data.txt";
	Graph graph;
	Solver solver;
	Path result;

public:
	void prepare();
	void run();
};