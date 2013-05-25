#include "HiddenLayer.h"
#include <algorithm>
#include <iostream>
using namespace std;

HiddenLayer::HiddenLayer(int neuronCount, Layer* previousLayer, int outputs)
	: FurtherLayer(neuronCount, previousLayer, outputs)
{}

void HiddenLayer::CalculateGradients(Layer* nextLayer)
{
	for ( auto it = neurons.begin(); it != neurons.end(); it++ ) 
	{
		double sum = 0.0;
	
		for_each(nextLayer->begin(), nextLayer->end() - 1, [&sum, it, this](Neuron n)
		{
			sum += neurons[it->GetIndex()].GetWeight(n.GetIndex()) * n.GetGradient();
		});
		
		neurons[it->GetIndex()].SetGradient(sum * activationFunctionDerivative(neurons[it->GetIndex()].GetOutput()));
	}
}

