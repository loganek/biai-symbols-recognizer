#include "Layer.h"
#include <algorithm>

using namespace std;


Layer::Layer(int neuronCount, int outputs)
{
	for ( int i = 0; i <= neuronCount; i++ )
		neurons.push_back(Neuron(outputs, i));

	neurons.back().SetOutput(1.0);
}

void Layer::LoadInputs(const std::vector<double>& inputs)
{
	if ( inputs.size() != neurons.size() - 1 )
		throw std::exception("Liczba wartoœci wejœciowych musi siê równaæ liczbie neuronów pierwszej warstwy!");

	for ( unsigned i = 0; i < inputs.size(); ++i) 
		neurons[i].SetOutput(inputs[i]);
}

vector<double> Layer::GetValues() const
{
	vector<double> results;
	
	for_each(neurons.begin(), neurons.end() - 1, [&results, this](Neuron n) 
	{
		results.push_back(n.GetOutput());
	});

	return results;
}