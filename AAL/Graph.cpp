#include "Graph.h"
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
	for (auto i : cities)
		delete i;
}


void Graph::addNode(City* newNode)
{
	cities.push_back(newNode);
}

void Graph::setStartingCity(int id)
{
	startingCity = cities[id];
}

void Graph::read(string fileName)										// dane z pliku
{
	// TODO nie kontrolujê wprowadznych przez u¿ytkownika danych
	int amount;
	int robbersLocal;
	int newX, newY, newValue, newVolume, newEdgeA, newEdgeB, border;

	ifstream file;
	file.open(fileName.c_str(), ios::in);

	file >> amount;
	for(int i = 0; i < amount; ++i)										// wczytaj info o miastach
	{
		file >> newX >> newY >> newValue >> newVolume >> border;
		if(border == 0)													// internal city
			cities.push_back(new City(i, newX, newY, newValue, newVolume, false));		
		else 
		{																// city at border
			City* newBorderCity = new City(i, newX, newY, newValue, newVolume, true);	
			cities.push_back(newBorderCity);
			borderline.push_back(newBorderCity);
		}

	}
	file >> robbersLocal;												// wczytaj info o rabusiu
	setStartingCity(robbersLocal);

	while (!file.eof())													// wczytaj info o drogach
	{
		file >> newEdgeA >> newEdgeB;
		cities[newEdgeA]->addEdge(cities[newEdgeB]);
		cities[newEdgeB]->addEdge(cities[newEdgeA]);
	}

	file.close();
}
