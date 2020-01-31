#include "Problem.h"
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>

int main(int argc, char* argv[])
{
	// do wywo³ywania z lini poleceñ
	
	const int ASCII_SHIFT = 48;
	if (argc != 7)
	{
		std::cout << "B³êdna liczba argumentów" << std::endl;
		return -1;
	}
	// argument 1 - tryb
	bool graphicMode = false;
	std::string stringMode = argv[1];
	if (stringMode == "graphic")
	{
		graphicMode = true;
	}
	// argument 2 - generacja
	bool generationNeeded = false;
	if (argv[2] == "gen")
		generationNeeded = true;
	//argument 3 - rozmiar
	int problemSize = 0;
	std::string stringSize = argv[3];
	for (int i = 0; i < stringSize.length(); ++i)
	{
		problemSize += ((int)stringSize[i]-ASCII_SHIFT) * pow(10, stringSize.length() - i - 1);
	}

	int attempts = 1;
	int iterations = 1;
	int deltaSize = 0;

	if (!graphicMode)
	{
		// argument 4 - uœrednienie po ilu próbach
		std::string stringAttempts = argv[4];
		attempts = 0;
		for (int i = 0; i < stringAttempts.length(); ++i)
		{
			attempts += ((int)stringAttempts[i] - ASCII_SHIFT) * pow(10, stringAttempts.length() - i - 1);
		}
		// argument 5 - ile pomiarów
		std::string stringIterations = argv[5];
		iterations = 0;
		for (int i = 0; i < stringIterations.length(); ++i)
		{
			iterations += ((int)stringIterations[i] - ASCII_SHIFT) * pow(10, stringIterations.length() - i - 1);
		}
		// argument 6 - przyrost danych miêdzy pomiarami
		std::string stringDeltaSize = argv[6];
		deltaSize = 0;
		for (int i = 0; i < stringDeltaSize.length(); ++i)
		{
			deltaSize += ((int)stringDeltaSize[i] - ASCII_SHIFT) * pow(10, stringDeltaSize.length() - i - 1);
		}
	}

	/*
	bool graphicMode = false;
	bool generationNeeded = true;
	int problemSize = 50;
	int attempts = 1;
	int iterations = 1;
	int deltaSize = 0;
	*/

	int sumDuration = 0;

	std::string destFileName = ".//out.txt";
	std::ofstream outFile(destFileName, std::ios::out | std::ios::app);
	if (!outFile.good())
	{
		std::cout << "B³¹d otwarcia pliku out" << std::endl;
		return 0;
	}
	for (int i = 0; i < iterations; i++)
	{
		for (int i = 0; i < attempts; ++i)
		{
			Problem problem;
			problem.generateNiceData(problemSize, 1, graphicMode);
			problem.prepare(graphicMode);
			problem.run(graphicMode);
			sumDuration += problem.getDuration();
		}
		outFile << problemSize << " " << sumDuration / attempts << ";" << std::endl;
		std::cout << problemSize << " " << sumDuration / attempts << ";" << std::endl;
		problemSize += deltaSize;
	}
	outFile.close();
	return 0;
}