// BIAIShapes.cpp : Defines the entry point for the console application.
//
#define _USE_MATH_DEFINES

#ifdef _WIN32
#include <tchar.h>
#endif
#include "MainProgram.h"

using namespace std;

#ifdef _WIN32
int _tmain(int argc, _TCHAR* argv[])
{
	char** arguments = new char*[argc];

	for ( int i = 0; i < argc; i++ )
	{
		wstring wstr(argv[i]);
		string str(wstr.begin(), wstr.end());
		arguments[i] = new char[str.length() + 1];
		strcpy(arguments[i], str.c_str());
	}
#elif __linux__
int main (int argc, char* arguments[])
{
#endif

	MainProgram program;
	program.ParseArguments(argc, arguments);

#ifdef _WIN32
	for ( int i = 0; i < argc; i++ )
	{
		delete [] arguments[i];
	}

	delete [] arguments;
#endif

	return 0;
}

