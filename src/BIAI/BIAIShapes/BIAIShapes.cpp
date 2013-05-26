// BIAIShapes.cpp : Defines the entry point for the console application.
//
#define _USE_MATH_DEFINES

#include <tchar.h>
#include "MainProgram.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	MainProgram program;

	char** arguments = new char*[argc];

	for ( int i = 0; i < argc; i++ )
	{
		wstring wstr(argv[i]);
		string str(wstr.begin(), wstr.end());
		arguments[i] = new char[str.length() + 1];
		strcpy(arguments[i], str.c_str());
	}
	
	program.ParseArguments(argc, arguments);
	
	for ( int i = 0; i < argc; i++ )
	{
		delete [] arguments[i];
	}

	delete [] arguments;

	return 0;
}

