#ifndef NEURAL_NETWORK_H
#define NERUAL_NETWORK_H

#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <vector>

class NeuralNetwork
{
private:
    Layer* inputLayer;
	HiddenLayer* hiddenLayer;
	OutputLayer* outputLayer;

public:
    NeuralNetwork(int inpNeuron, int hidNeuron, int outNeuron);
	virtual ~NeuralNetwork();

    void FeedForward(const std::vector<double> &inputVals);
    void BackPropagation(const std::vector<double> &targetVals);
    std::vector<double> GetResults() const;
};



#endif