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

NeuralNetwork::NeuralNetwork(int inpNeuron, int hidNeuron, int outNeuron)
{
	inputLayer = new Layer(inpNeuron, hidNeuron + 1);
	hiddenLayer = new HiddenLayer(hidNeuron, inputLayer, outNeuron + 1);
	hiddenLayer->SetActivationFunctions(ActivationFunction, ActivationFunctionDerivative);
	outputLayer = new OutputLayer(outNeuron, hiddenLayer);
	outputLayer->SetActivationFunctions(ActivationFunction, ActivationFunctionDerivative);
}

NeuralNetwork::~NeuralNetwork()
{
	delete [] inputLayer;
	delete [] hiddenLayer;
	delete [] outputLayer;
}

vector<double> NeuralNetwork::GetResults() const
{
    return outputLayer->GetValues();
}

void NeuralNetwork::BackPropagation(const vector<double>& expected)
{
    outputLayer->CalculateGradients(expected);
	hiddenLayer->CalculateGradients(outputLayer);
    
	outputLayer->UpdateInputWeights();
	hiddenLayer->UpdateInputWeights();
}

void NeuralNetwork::FeedForward(const vector<double>& inputs)
{
	inputLayer->LoadInputs(inputs);
	hiddenLayer->FeedForward();
	outputLayer->FeedForward();
}

