#pragma once
#include<string>
#include<vector>

class City
{
private:
	int id;
	int xPosition;
	int yPosition;
	std::string name;		// nie u¿ywane w tym momencie, ale mog³oby byæ przydatne przy ew. rozszerzaniu
	int lootValue;			// bogactwo mo¿liwe do zrabowania
	int lootVolume;
	std::vector<City*> edges;
	bool border = false;	// czy miasto znajduje siê na granicy

public:
	City();
	City(int i, int x, int y, int val, int vol, bool isBorder);

	int getXPosition();
	int getId();
	int getYPosition();
	std::string getName();
	int getLootValue();
	int getLootVolume();
	bool isNeighbour(City* potentialNeighbour);
	bool isOnBorder();
	std::vector<City*>* getEgdes();
	void addEdge(City* newNeighbour);
	double getDistance(City* targetCity);

	friend class DrawGraph;			// dla u³atwienia procesu wyœwietlania
};

