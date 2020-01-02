#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_primitives.h>
#include"Graph.h"

class DrawGraph
{
private:
	ALLEGRO_DISPLAY* display;
	Graph* g;
	ALLEGRO_COLOR green, red, blue;

	bool drawNodesAndEdges();
	bool show();
public:
	DrawGraph();
	~DrawGraph();

	void setG(Graph* newG);
	void draw();
	void initialization();


};
