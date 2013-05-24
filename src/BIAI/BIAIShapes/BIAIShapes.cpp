// BIAIShapes.cpp : Defines the entry point for the console application.
//
#define _USE_MATH_DEFINES

#include "ImageAlgorithms/ImageFeatures.h"

#include <tchar.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ContouredImage image("E:\\krzyz.png");
	ImageFeatures features(image);
	cout << features.Circularity() << endl;
	cout << features.Convexity() << endl;
	cout << features.Rectangularity() << endl;
	return 0;
}

