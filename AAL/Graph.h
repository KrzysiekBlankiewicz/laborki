#pragma once
#include<vector>
#include<string>
#include<utility>
#include "City.h"
#include "Path.h"

class Graph
{
	std::vector<City*> cities;
	std::vector<City*> borderline;
	City* startingCity = nullptr;

	Path* bestPath = nullptr;

	// pommocnicze
	void addNode(City* newNode);
	void setStartingCity(int id);

public:
	Graph();
	~Graph();
	void read(std::string fileName);

};
