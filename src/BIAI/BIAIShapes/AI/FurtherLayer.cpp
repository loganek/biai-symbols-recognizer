#include "FurtherLayer.h"
#include <algorithm>

using namespace std;

FurtherLayer::FurtherLayer(int neuronCount, Layer* previousLayer, int outputs)
	: Layer(neuronCount, outputs),
	previousLayer(previousLayer)
{
}

void FurtherLayer::UpdateInputWeights()
{
	for ( auto itExt = neurons.begin(); itExt != neurons.end() - 1; itExt ++ )
	{
		for ( auto it = previousLayer->begin(); it != previousLayer->end(); it++ )
		{
			it->UpdateWeight(neurons[itExt->GetIndex()]);
		}
	}
}

void FurtherLayer::FeedForward()
{
	for ( auto it = neurons.begin(); it != neurons.end() - 1; it++ )
	{
		double sum = 0.0;

		for_each(previousLayer->begin(), previousLayer->end(), [&sum, it](Neuron n)
		{
			sum += n.GetWeighted(it->GetIndex());
		});

		it->SetOutput(activationFunction(sum));
	}
}

void FurtherLayer::SetActivationFunctions(std::function<double(double)> actFun, std::function<double(double)> actFunDer)
{
	activationFunction = actFun;
	activationFunctionDerivative = actFunDer;
}