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
	for (auto i : nodes)
		delete i;
}

void Graph::addNode(City* newNode)
{
	nodes.push_back(newNode);
}

void Graph::read(string fileName)										// dane z pliku
{
	int amount;
	int dannysLocal;
	int newX, newY, newValue, newVolume, newEdgeA, newEdgeB, border;
	bool isBorder;
	ifstream file;
	file.open(fileName.c_str(), ios::in);

	file >> amount;
	for(int i = 0; i < amount; ++i)										// wczytaj info o miastach
	{
		file >> newX >> newY >> newValue >> newVolume >> border;
		isBorder = (bool)border;
		nodes.push_back(new City(i, newX, newY, newValue, newVolume, isBorder));
	}
	file >> dannysLocal;												// wczytaj info o rabusiu
	//TODO jak ustawiam startingCity
	while (!file.eof())													// wczytaj info o drogach
	{
		file >> newEdgeA >> newEdgeB;
		nodes[newEdgeA]->addEdge(nodes[newEdgeB]);
		nodes[newEdgeB]->addEdge(nodes[newEdgeA]);
	}

	file.close();
}
