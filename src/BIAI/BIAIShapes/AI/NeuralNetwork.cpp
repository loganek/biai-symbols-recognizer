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

NeuralNetwork::NeuralNetwork(int inpNeuron, vector<int> hidLayers, int outNeuron)
{
	inputLayer = hidLayers.size() == 0 ? new Layer(inpNeuron, outNeuron + 1) : inputLayer = new Layer(inpNeuron, hidLayers[0] + 1);
	
	Layer* prevLayer = inputLayer;

	hiddenLayers.reserve(hidLayers.size());
	hidLayers.push_back(outNeuron);

	for ( auto it = hidLayers.begin(); it != hidLayers.end() - 1; it++ )
	{
		hiddenLayers.push_back(new HiddenLayer(*it, prevLayer, *(it + 1) + 1));
		prevLayer = hiddenLayers.back();
		((HiddenLayer*)prevLayer)->SetActivationFunctions(ActivationFunction, ActivationFunctionDerivative);
	}


	outputLayer = new OutputLayer(outNeuron, prevLayer);
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

