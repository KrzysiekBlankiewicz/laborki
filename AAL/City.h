#pragma once
#include<string>
#include<vector>

class City
{
private:
	int id;
	int xPosition;
	int yPosition;
	std::string name;
	int lootValue;
	int lootVolume;
	std::vector<City*> edges;
	bool border = false;

public:
	City();
	City(int i, int x, int y, int val, int vol, bool isBorder);

	int getXPosition();
	int getId();
	int getYPosition();
	std::string getName();
	int getLootValue();
	int getLootVolume();
	void addEdge(City* newNeighbour);

	friend class DrawGraph;
};

