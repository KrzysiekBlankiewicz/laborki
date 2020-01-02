#include "DrawGraph.h"
#include <iostream>
#include <vector>

using namespace std;

void DrawGraph::initialization()
{
	al_init();
	al_init_primitives_addon();
	display = al_create_display(600, 500);
	/**green = al_map_rgb(0, 255, 0);
	*red = al_map_rgb(255, 0, 0);
	*blue = al_map_rgb(0, 0, 255);*/
}

bool DrawGraph::drawNodesAndEdges()
{
	vector<bool> visited;
	City* whereIsDanny;
	visited.resize(g->nodes.size(), false);
	for (auto i : visited)
		i = false;

	for (auto i: g->nodes)
	{
		al_draw_filled_circle(i->getXPosition(), i->getYPosition(), 10, al_map_rgb(255, 0, 0));
		for (auto j : i->edges)
		{
			if(visited[j->getId()] == false)
			al_draw_line(i->getXPosition(), i->getYPosition(), j->getXPosition(), j->getYPosition(), al_map_rgb(0, 0, 255), 3);
		}
		visited[i->getId()] = true;
	}
	whereIsDanny = g->getDanny()->getPosition();
	al_draw_filled_circle(whereIsDanny->getXPosition(), whereIsDanny->getYPosition(), 6, al_map_rgb(0, 255, 0));

	/*for (auto j : g->edges)
	{
		al_draw_line(j.first->getXPosition(), j.first->getYPosition(), j.second->getXPosition(), j.second->getYPosition(), al_map_rgb(255, 0, 0), 10);
	}*/

	return true;
}

bool DrawGraph::show()
{
	al_flip_display();
	return true;
}

DrawGraph::DrawGraph()
{
	g = nullptr;
	display = nullptr;
	/*blue = nullptr;
	green = nullptr;
	red = nullptr;*/
}

DrawGraph::~DrawGraph()
{
	al_destroy_display(display);
}

DrawGraph::DrawGraph(Graph* newG)
{
	g = newG;
	display = nullptr;
}
