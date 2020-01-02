#pragma once
#include<vector>
#include<string>
#include<utility>
#include "City.h"

class Graph
{
	std::vector<City*> nodes;
	City* startingCity;
public:
	Graph();
	~Graph();
	void addNode(City* newNode);
	void read(std::string fileName);
};
