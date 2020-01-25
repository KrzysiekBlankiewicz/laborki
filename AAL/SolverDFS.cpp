#include "SolverDFS.h"
#include <iostream>			//TODO wywaliæ

void SolverDFS::DFS()
{
	if (!borderFound && mainQueue->empty())		// przeszuka³ kolejny poziom
	{
		std::queue<int>* temp = subQueue;
		subQueue = mainQueue;
		mainQueue = temp;
	}
	if (borderFound && mainQueue->empty())	//koniec algorytmu
		return;

	City* currentCity = (*(g->getCities()))[mainQueue->front()];
	mainQueue->pop();

	for (auto e : *(currentCity->getEgdes()))
	{
		if (predecessorsTable[e->getId()] == -1)
		{
			subQueue->push(e->getId());
			predecessorsTable[e->getId()] = currentCity->getId();
			if (e->isOnBorder())
			{
				targets.push_back(e->getId());
				borderFound = true;
			}
		}
	}
	DFS();
	return;
}

void SolverDFS::findShortestPaths(std::vector<Path*>* shortestPaths)
{
	initStructures();

	mainQueue->push(g->getStartingCity()->getId());
	predecessorsTable[g->getStartingCity()->getId()] = -2;
	DFS();

	for (auto a : targets)
	{
		shortestPaths->push_back(reconstructPath(a));
	}
	
}

void SolverDFS::chooseBestPath(std::vector<Path*>* shortestPaths)
{
	int robbedSum = 0;
	int maxSum = 0;
	Path maxPath;
	for (auto a : *shortestPaths)
	{
		robbedSum = 0;
		for (auto b : *(a->getCities()))
		{
			if(robbedSum < g->getMaxLootVolume())
				robbedSum += b->getLootValue();
		}
		if (robbedSum > maxSum)
		{
			maxSum = robbedSum;
			maxPath = *a;
		}
	}
	
	g->setBestPath(maxPath);
}

Path* SolverDFS::reconstructPath(int targetId)
{
	Path* newPath = new Path();
	std::vector<City*> tempVector;
	std::vector<City*> cities = *(g->getCities());
	int tempId = targetId;
	do
	{
		std::cout << tempId << " ";	// TODO wywal
		tempVector.push_back(cities[tempId]);
		tempId = predecessorsTable[tempId];
	} while (tempId != -2);

	for (std::vector<City*>::reverse_iterator i = tempVector.rbegin(); i < tempVector.rend(); ++i)
	{
		newPath->addCity(*i);
	}
	std::cout << std::endl;	// TODO wywal
	return newPath;
}

void SolverDFS::initStructures()
{
	borderFound = false;
	predecessorsTable.clear();
	predecessorsTable.resize(g->getCities()->size(), -1);
}

SolverDFS::SolverDFS()
{
	mainQueue = new std::queue<int>;
	subQueue = new std::queue<int>;
}

SolverDFS::~SolverDFS()
{
	delete mainQueue;
	delete subQueue;
}

