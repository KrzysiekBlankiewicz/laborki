#include "Problem.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{
	bool withAllPaths = true;
	Problem problem;
	problem.generateNiceData(15, 1);
	
	//problem.generateRandomData(20, 2, 0.05);	// TODO argumenty z linii komend
	problem.prepare();
	problem.run(withAllPaths);
	std::cout << problem.getDuration() << std::endl;

	return 0;
}