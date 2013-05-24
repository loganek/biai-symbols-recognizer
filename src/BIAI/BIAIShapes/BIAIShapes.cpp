// BIAIShapes.cpp : Defines the entry point for the console application.
//
#define _USE_MATH_DEFINES

#include "Training/TrainingDataLoader.h"
#include "Training/TrainingData.h"
#include "AI/NeuralNetwork.h"
#include "ImageAlgorithms/ImageFeatures.h"
#include <tchar.h>
#include <iostream>

using namespace std;

const char* ShapeToStr(ShapeNo::Type shape)
{
	switch (shape)
	{
	case ShapeNo::CIRCLE:
		return "circle";
	case ShapeNo::CROSS:
		return "cross";
	case ShapeNo::SQUARE:
		return "square";
	case ShapeNo::TRIANGLE:
		return "triangle";
	default:
		return "unknow";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ContouredImage image("E:\\krzyz.png");
	ImageFeatures features(image);
	cout << features.Circularity() << endl;
	cout << features.Convexity() << endl;
	cout << features.Rectangularity() << endl;
 
	TrainingDataLoader<TrainingData> loader("E:\\test.txt");
	loader.LoadData();
	vector<TrainingData> v = loader.GetData();

	cout << "Circularity:\tConvexity:\tRectangularity:\tShape:" << endl;

	for ( auto it = v.begin(); it != v.end(); it++ )
	{
		cout << it->GetCircularity() << "\t\t" << it->GetConvexity() << "\t\t" << it->GetRectangularity() << "\t\t" << ShapeToStr(it->GetShapeType()) << endl;
	}

	return 0;
}

