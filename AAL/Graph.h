#pragma once
#include<vector>
#include<string>
#include<utility>
#include "City.h"
#include "Path.h"

class Graph
{
	std::vector<City*> cities;
	std::vector<City*> borderline;		// miasta znajduj¹ce siê na granicy
	City* startingCity = nullptr;		//miasto, w którym wykryto z³odzeja

	Path bestPath;						// wynik dzia³ania programu
	int maxLootVolume;					// pojemnoœæ baga¿nika

	// pommocnicze
	void addNode(City* newNode);
	void setStartingCity(int id);

public:
	Graph();
	~Graph();
	void read(std::string fileName);
	City* getStartingCity();
	std::vector<City*>* getCities();
	Path* getBestPath();
	std::vector<City*>* getBorderline();
	int getMaxLootVolume();
	void setMaxLootVolume(int newMax);
	void setBestPath(Path newBest);
};
