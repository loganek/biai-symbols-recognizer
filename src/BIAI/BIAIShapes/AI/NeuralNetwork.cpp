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
	
	hiddenLayer = new HiddenLayer(hidNeuron, inputLayer, 4 + 1);
	hiddenLayer->SetActivationFunctions(ActivationFunction, ActivationFunctionDerivative);
	
	hiddenLayer2 = new HiddenLayer(5, hiddenLayer, outNeuron + 1);
	hiddenLayer2->SetActivationFunctions(ActivationFunction, ActivationFunctionDerivative);
	
	outputLayer = new OutputLayer(outNeuron, hiddenLayer2);
	outputLayer->SetActivationFunctions(ActivationFunction, ActivationFunctionDerivative);
}

NeuralNetwork::~NeuralNetwork()
{
	delete outputLayer;
	delete hiddenLayer;
	delete inputLayer;
}

vector<double> NeuralNetwork::GetResults() const
{
    return outputLayer->GetValues();
}

void NeuralNetwork::BackPropagation(const vector<double>& expected)
{
    outputLayer->CalculateGradients(expected);
	hiddenLayer2->CalculateGradients(outputLayer);
	hiddenLayer->CalculateGradients(hiddenLayer2);
    
	outputLayer->UpdateInputWeights();
	hiddenLayer2->UpdateInputWeights();
	hiddenLayer->UpdateInputWeights();
}

void NeuralNetwork::FeedForward(const vector<double>& inputs)
{
	inputLayer->LoadInputs(inputs);
	hiddenLayer->FeedForward();
	hiddenLayer2->FeedForward();
	outputLayer->FeedForward();
}

