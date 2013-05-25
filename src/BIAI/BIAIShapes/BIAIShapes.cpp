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
#include "NeuronTranslator.h"

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

void DisplayTrainingData(const vector<TrainingData>& v)
{
	cout << "Circularity:\tConvexity:\tRectangularity:\tShape:" << endl;

	for ( auto it = v.begin(); it != v.end(); it++ )
	{
		cout << it->GetCircularity() << "\t\t" << it->GetConvexity() << "\t\t" << it->GetRectangularity() << "\t\t" << ShapeToStr(it->GetShapeType()) << endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	const int shapes = 3;

	vector<int> hiddenLayers;
	hiddenLayers.push_back(4);
	hiddenLayers.push_back(5);

	NeuralNetwork net(3, hiddenLayers, shapes);
	NeuronTranslator<shapes> translator;

	ContouredImage image("E:\\krzyz.png");
	ImageFeatures features(image);
	cout << features.Circularity() << endl;
	cout << features.Convexity() << endl;
	cout << features.Rectangularity() << endl;
 
	TrainingDataLoader<TrainingData> loader("D:\\Moj_folder\\Dokumenty\\uczelnia\\BIAI\\biai-projekt\\test.txt");
	loader.LoadData();
	vector<TrainingData> v = loader.GetData();

	DisplayTrainingData(v);
	for ( int i = 0; i < 200; i++ )
	for ( auto it = v.begin(); it != v.end(); it++ )
	{
		std::vector<double> v;
		v.push_back(it->GetCircularity()); v.push_back(it->GetConvexity()); v.push_back(it->GetRectangularity());
		net.FeedForward(v);
		translator.Init(net.GetResults());
		vector<double> aa = translator.GetOriginalData();
		cout << it->GetCircularity() << " " << it->GetConvexity() << " " << it->GetRectangularity() << " " << aa[0] << " " << aa[1] << " " << aa[2] << endl;

		net.BackPropagation(NeuronTranslator<shapes>::GenerateIndexedData(it->GetShapeType()));
	}

	std::vector<double> vv;
		vv.push_back(features.Circularity()); vv.push_back(features.Convexity()); vv.push_back(features.Rectangularity());
		net.FeedForward(vv);
		translator.Init(net.GetResults());
		vector<double> aa = translator.GetOriginalData();
		
	return 0;
}

