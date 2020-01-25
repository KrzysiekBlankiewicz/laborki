#include "MapSegment.h"

int MapSegment::citiesQuantity = 0;

MapSegment::MapSegment()
{
	full = false;
	border = false;
	starting = false;
	cityId = -1;
}

bool MapSegment::isFull()
{
	return full;
}

bool MapSegment::getBorder()
{
	return border;
}

bool MapSegment::getStarting()
{
	return starting;
}

int MapSegment::getCityId()
{
	return cityId;
}

void MapSegment::setBorder(bool newBorder)
{
	border = newBorder;
}

void MapSegment::setFull(bool newFull)
{
	full = newFull;
}

void MapSegment::setStarting(bool newStarting)
{
	starting = newStarting;
}

void MapSegment::setCityId(int newId)
{
	cityId = newId;
}
