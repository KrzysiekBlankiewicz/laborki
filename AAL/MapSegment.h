#pragma once
#include "City.h"
class MapSegment
{
	bool full;
	bool border;
	bool starting ;
	int cityId;
public:
	MapSegment();
	static int citiesQuantity;
	bool isFull();
	bool getBorder();
	bool getStarting();
	int getCityId();
	void setBorder(bool newBorder);
	void setFull(bool newFull);
	void setStarting(bool newStarting);
	void setCityId(int newId);

};
