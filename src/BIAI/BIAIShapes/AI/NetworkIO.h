#ifndef NETWORK_IO_H
#define NETWORK_IO_H

#include "NeuralNetwork.h"
#include <fstream>
#include <string>

class NetworkIO
{
private:
	std::ifstream inputFile;
	std::fstream outputFile;
	std::string fileName;

	NeuralNetwork* network;

	void SaveTopologyInfo();
	void SaveSingleLayer(Layer* layer);

	TopologyInfo LoadTopologyInfo();
	void LoadSingleLayer(Layer* layer);
public:
	NetworkIO(std::string fileName);
	virtual ~NetworkIO() {}

	void SaveNetwork(NeuralNetwork* net);
	NeuralNetwork* LoadNetwork();
};

#endif