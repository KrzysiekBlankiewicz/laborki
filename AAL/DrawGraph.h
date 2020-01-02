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
	//ALLEGRO_COLOR *green, *red, *blue;
public:
	DrawGraph();
	~DrawGraph();
	DrawGraph(Graph* newG);
	
	void initialization();
	bool drawNodesAndEdges();
	bool show();

};
