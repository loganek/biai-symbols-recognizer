// BIAIShapes.cpp : Defines the entry point for the console application.
//
#define _USE_MATH_DEFINES

#include "Training/TrainingDataLoader.h"
#include "Training/TrainingData.h"
#include "AI/NeuralNetwork.h"
#include "ImageAlgorithms/ImageFeatures.h"
#include <tchar.h>
#include <iostream>
#include <ctime>
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
	/*ContouredImage image("E:\\krzyz.png");
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
	*/


	NeuralNetwork net(2, 4, 4);
	srand( time(NULL) ); 
	for ( int i = 0; i < 3000; i++ )
	{
		int a = rand() % 2; 
		int b = rand() % 2;
		cout << b << " " << a;
		vector<double> xx;
		xx.push_back(a);
		xx.push_back(b);
        
 		net.FeedForward(xx);
		vector<double> res = net.GetResults();
        
        cout << " " << res[0] <<  " " << res[1]<<  " " << res[2]<<  " " << res[3] << endl;
		vector<double> expected;
		expected.push_back( !a && !b);
		expected.push_back(a && !b);
		expected.push_back(!a && b);
		expected.push_back(a && b);
		net.BackPropagation(expected);

	}

	return 0;
}

