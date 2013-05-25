#include "NeuralNetwork.h"
#include <algorithm>

using namespace std;

double ActivationFunction(double x)
{
    return tanh(x);
}

double ActivationFunctionDerivative(double x)
{
    return 1.0 - x * x;
}

NeuralNetwork::NeuralNetwork(TopologyInfo info)
{
	inputLayer = info.hiddenCount.size() == 0 ? new Layer(info.inputCount, info.outputCount + 1) : inputLayer = new Layer(info.inputCount, info.hiddenCount[0] + 1);
	
	Layer* prevLayer = inputLayer;

	hiddenLayers.reserve(info.hiddenCount.size());
	info.hiddenCount.push_back(info.outputCount);

	for ( auto it = info.hiddenCount.begin(); it != info.hiddenCount.end() - 1; it++ )
	{
		hiddenLayers.push_back(new HiddenLayer(*it, prevLayer, *(it + 1) + 1));
		prevLayer = hiddenLayers.back();
		((HiddenLayer*)prevLayer)->SetActivationFunctions(ActivationFunction, ActivationFunctionDerivative);
	}


	outputLayer = new OutputLayer(info.outputCount, prevLayer);
	outputLayer->SetActivationFunctions(ActivationFunction, ActivationFunctionDerivative);
}

NeuralNetwork::~NeuralNetwork()
{
	delete outputLayer;
	

	delete inputLayer;
}

vector<double> NeuralNetwork::GetResults() const
{
    return outputLayer->GetValues();
}

void NeuralNetwork::BackPropagation(const vector<double>& expected)
{
    outputLayer->CalculateGradients(expected);

	Layer* nextLayer = outputLayer;

	for ( auto rit = hiddenLayers.rbegin(); rit != hiddenLayers.rend(); rit++ )
	{
		(*(rit))->CalculateGradients(nextLayer);
		nextLayer = (*(rit));
	}

	outputLayer->UpdateInputWeights();
	
	for ( auto rit = hiddenLayers.rbegin(); rit != hiddenLayers.rend(); rit++ )
		(*(rit))->UpdateInputWeights();
}

void NeuralNetwork::FeedForward(const vector<double>& inputs)
{
	inputLayer->LoadInputs(inputs);

	for ( auto it = hiddenLayers.begin(); it != hiddenLayers.end(); it++ )
		(*(it))->FeedForward();

	outputLayer->FeedForward();
}

void NeuralNetwork::SaveNetwork(const string& fileName) const
{
	ofstream file;
	file.open(fileName.c_str(), ios::out);

	if ( !file.is_open() )
		throw std::exception("Nie mo¿na otworzyæ pliku ¿eby zapisaæ sieæ!");

	SaveTopologyInfo(file);

	SaveSingleLayer(inputLayer, file);

	for ( auto it = hiddenLayers.begin(); it != hiddenLayers.end(); it++ )
		SaveSingleLayer(*it, file);

	file.close();
}

void NeuralNetwork::SaveSingleLayer(Layer* lay, ofstream& file) const
{
	for ( auto it = lay->begin();  it != lay->end(); it++ )
	{
		file << it->GetWeightCount() << " ";

		for ( int i = 0; i < it->GetWeightCount(); i++ )
			file << it->GetWeight(i) << " ";

		file << endl;
	}

	file << endl;
}

void NeuralNetwork::SaveTopologyInfo(ofstream& file) const
{
	file << inputLayer->NeuronCount() - 1 << " " << outputLayer->NeuronCount() - 1 << " " << hiddenLayers.size() << " ";

	for_each(hiddenLayers.begin(), hiddenLayers.end(), [this, &file](HiddenLayer* layer)
	{
		file << layer->NeuronCount() - 1 << " ";
	});

	file << endl;
}

NeuralNetwork* NeuralNetwork::LoadNetwork(const std::string& fileName)
{
	ifstream file;
	file.open(fileName.c_str(), ios::in);

	if ( !file.is_open() )
		throw std::exception("Nie mo¿na otworzyæ pliku do odczytu przy ³adowaniu sieci z pliku.");

	NeuralNetwork* network = new NeuralNetwork(LoadTopologyInfo(file));

	LoadSingleLayer(network->inputLayer, file);

	for ( auto it = network->hiddenLayers.begin(); it != network->hiddenLayers.end(); it++ )
		LoadSingleLayer(*it, file);

	file.close();

	return network;
}

void NeuralNetwork::LoadSingleLayer(Layer* lay, ifstream& file)
{
	for ( auto it = lay->begin();  it != lay->end(); it++ )
	{
		int weightsCount;

		file >> weightsCount;

		for ( int i = 0; i < weightsCount; i++ )
		{
			double v;
			file >> v;
			it->SetWeight(i, v);
		}
	}
}

TopologyInfo NeuralNetwork::LoadTopologyInfo(ifstream& file)
{
	TopologyInfo info;
	int hiddenCnt;

	file >> info.inputCount >> info.outputCount >> hiddenCnt;

	info.hiddenCount.resize(hiddenCnt);

	for ( int i = 0; i < hiddenCnt; i++ )
		file >> info.hiddenCount[i];
	
	return info;
}