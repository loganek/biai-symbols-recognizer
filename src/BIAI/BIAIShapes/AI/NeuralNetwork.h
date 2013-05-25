#ifndef NEURAL_NETWORK_H
#define NERUAL_NETWORK_H

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

	void SaveTopologyInfo(std::ofstream& file) const;
	void SaveSingleLayer(Layer* lay, std::ofstream& file) const;
	
	static TopologyInfo LoadTopologyInfo(std::ifstream& file);
	static void LoadSingleLayer(Layer* lay, std::ifstream& file);
public:
    NeuralNetwork(TopologyInfo info);
	virtual ~NeuralNetwork();

    void FeedForward(const std::vector<double> &inputVals);
    void BackPropagation(const std::vector<double> &targetVals);
    std::vector<double> GetResults() const;

	void SaveNetwork(const std::string& fileName) const;
	static NeuralNetwork* LoadNetwork(const std::string& fileName);
};

#endif