#ifndef TRAINING_H
#define TRAINING_H

#include "../AI/NeuralNetwork.h"
#include "TrainingDataLoader.h"
#include "TrainingData.h"

#include <string>

class Training
{
private:
	TrainingDataLoader<TrainingData>* loader;
	NeuralNetwork* network;

public:
	Training(NeuralNetwork* network);
	virtual ~Training();

	void LoadTrainingData(const std::string& fileName);
	void StartTraining(int itCount);
};

#endif