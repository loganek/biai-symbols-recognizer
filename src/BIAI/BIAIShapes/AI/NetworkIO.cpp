#include "NetworkIO.h"
#include <algorithm>

using namespace std;

NetworkIO::NetworkIO(string fileName)
	: fileName(fileName)
{
}

void NetworkIO::SaveNetwork(NeuralNetwork* net)
{
	outputFile.open(fileName.c_str(), ios::out);

	if ( !outputFile.is_open() )
		throw exception("Nie mo¿na otworzyæ pliku do zapisu sieci.");

	network = net;

	SaveTopologyInfo();

	SaveSingleLayer(network->inputLayer);

	for ( auto it = network->hiddenLayers.begin(); it != network->hiddenLayers.end(); it++ )
		SaveSingleLayer(*it);

	outputFile.close();
}

void NetworkIO::SaveTopologyInfo()
{
	outputFile << network->inputLayer->NeuronCount() - 1 << " " << network->outputLayer->NeuronCount() - 1 << " " << network->hiddenLayers.size() << " ";

	for_each(network->hiddenLayers.begin(), network->hiddenLayers.end(), [this](HiddenLayer* layer)
	{
		outputFile << layer->NeuronCount() - 1 << " ";
	});

	outputFile << endl;
}

void NetworkIO::SaveSingleLayer(Layer* layer)
{
	for ( auto it = layer->begin();  it != layer->end(); it++ )
	{
		outputFile << it->GetWeightCount() << " ";

		for ( int i = 0; i < it->GetWeightCount(); i++ )
			outputFile << it->GetWeight(i) << " ";

		outputFile << endl;
	}

	outputFile << endl;
}

NeuralNetwork* NetworkIO::LoadNetwork()
{
	inputFile.open(fileName.c_str(), ios::in);

	if ( !inputFile.is_open() )
		throw exception("Nie mo¿na otworzyæ pliku do odczytu sieci.");

	NeuralNetwork* newNetwork = new NeuralNetwork(LoadTopologyInfo());

	LoadSingleLayer(newNetwork->inputLayer);

	for ( auto it = newNetwork->hiddenLayers.begin(); it != newNetwork->hiddenLayers.end(); it++ )
		LoadSingleLayer(*it);

	inputFile.close();

	return newNetwork;
}

TopologyInfo NetworkIO::LoadTopologyInfo()
{
	TopologyInfo info;
	int hiddenCnt;

	inputFile >> info.inputCount >> info.outputCount >> hiddenCnt;

	info.hiddenCount.resize(hiddenCnt);

	for ( int i = 0; i < hiddenCnt; i++ )
		inputFile >> info.hiddenCount[i];
	
	return info;
}

void NetworkIO::LoadSingleLayer(Layer* layer)
{
	double v;
	int weightsCount;

	for ( auto it = layer->begin();  it != layer->end(); it++ )
	{
		inputFile >> weightsCount;

		for ( int i = 0; i < weightsCount; i++ )
		{
			inputFile >> v;
			it->SetWeight(i, v);
		}
	}
}
