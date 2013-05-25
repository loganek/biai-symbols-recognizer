#include "OutputLayer.h"

OutputLayer::OutputLayer(int neuronCount, Layer* previousLayer)
	: FurtherLayer(neuronCount, previousLayer, 0)
{}

void OutputLayer::CalculateGradients(const std::vector<double>& expected)
{
	for ( unsigned i = 0; i < neurons.size() - 1; i++ ) 
	{
		neurons[i].SetGradient((expected[i] - neurons[i].GetOutput()) * activationFunctionDerivative(neurons[i].GetOutput()));
	}
}