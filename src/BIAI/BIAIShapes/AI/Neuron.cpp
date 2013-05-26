#include "Neuron.h"
#include <algorithm>

double Neuron::trainRate = 0.10;
double Neuron::momentum= 0.55;

Neuron::Neuron(unsigned outputCount, unsigned index)
	: index(index)
{
	weightsInitializer = [] { return rand() / double(RAND_MAX); };

    for ( unsigned i = 0; i < outputCount; i++ )
		weights.push_back(Line(weightsInitializer()));
}

void Neuron::UpdateWeight(const Neuron& targetNeuron)
{
	weights[targetNeuron.index].delta = Neuron::trainRate * output * targetNeuron.gradient + Neuron::momentum * weights[targetNeuron.index].delta;;
	weights[targetNeuron.index].weight += weights[targetNeuron.index].delta;
}