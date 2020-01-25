#include "Problem.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{
	bool graphicMode = false;
	Problem problem;
	problem.generateNiceData(500, 1, graphicMode);
	
	//problem.generateRandomData(20, 2, 0.05);	// TODO argumenty z linii komend
	problem.prepare();
	problem.run(graphicMode);
	std::cout << problem.getDuration() << std::endl;

	return 0;
}