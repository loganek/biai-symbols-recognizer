#ifndef MAIN_PROGRAM_H
#define MAIN_PROGRAM_H

#include "Training/TrainingData.h"

class MainProgram
{
private:
	void DisplayMenu(const char* appName);
	void ProcessImage(int argc, char** argv);
	void GenerateNetwork(int argc, char** argv);
	const char* ShapeToStr(ShapeNo::Type shape);
public:
	virtual ~MainProgram() {}
	MainProgram(){}

	void ParseArguments(int argc, char** argv);

};

#endif