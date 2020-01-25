#include "Problem.h"
#include <fstream>
#include <iostream>
#include <string>

int main()
{
	
	Problem problem;
	problem.test();
	
	//problem.generateData(20, 2, 0.05);	// TODO argumenty z linii komend
	problem.prepare();
	problem.run();
	std::cout << problem.getDuration() << std::endl;

	return 0;
}