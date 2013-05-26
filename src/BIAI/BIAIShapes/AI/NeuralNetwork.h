#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <vector>
#include <string>
#include <fstream>

struct TopologyInfo
{
	int inputCount;
	std::vector<int> hiddenCount;
	int outputCount;
};

class NeuralNetwork
{
private:
    Layer* inputLayer;
	std::vector<HiddenLayer*> hiddenLayers;
	OutputLayer* outputLayer;

	friend class NetworkIO;
public:
    NeuralNetwork(TopologyInfo info);
	virtual ~NeuralNetwork();

    void FeedForward(const std::vector<double> &inputVals);
    void BackPropagation(const std::vector<double> &targetVals);
    std::vector<double> GetResults() const;
};



#endif