#include "Training.h"
#include "../NeuronTranslator.h"
#include <iostream>

using namespace std;

Training::Training(NeuralNetwork* network)
	: loader(NULL),
	network(network)
{}

Training::~Training()
{
	delete loader;
}

void Training::LoadTrainingData(const string& fileName)
{
	loader = new TrainingDataLoader<TrainingData>(fileName);
	loader->LoadData();
}

void Training::StartTraining(int itCount)
{
	vector<TrainingData> data = loader->GetData();

	for ( int i  = 0; i < itCount; i++ )
	{
		for ( auto it = data.begin(); it != data.end(); it++ )
		{
			std::vector<double> v;
			v.push_back(it->GetCircularity()); v.push_back(it->GetConvexity()); v.push_back(it->GetRectangularity());
			network->FeedForward(v);
			network->BackPropagation(NeuronTranslator<3>::GenerateIndexedData(it->GetShapeType()));
		}

		cout << i << endl;
	}
}