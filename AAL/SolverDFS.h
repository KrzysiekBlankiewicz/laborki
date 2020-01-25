#pragma once
#include "Solver.h"
#include <queue>

class SolverDFS : public Solver
{
	std::vector<int> targets;
	std::vector<int> predecessorsTable;
	std::queue<int>* mainQueue;
	std::queue<int>* subQueue;
	bool borderFound;

	void DFS();
	void virtual findShortestPaths(std::vector<Path*>* shortestPaths);
	void virtual chooseBestPath(std::vector<Path*>* shortestPaths);
	Path* reconstructPath(int targetId);
	void initStructures();
public:
	SolverDFS();
	~SolverDFS();
};

