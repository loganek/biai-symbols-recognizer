#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"
#include <vector>

class Layer
{
protected:
	typedef std::vector<Neuron> NeuronVect;
	NeuronVect neurons; 

public:
	Layer(int neuronCount, int outputs);
	~Layer() {}

	NeuronVect::iterator begin() { return neurons.begin(); }
	NeuronVect::iterator end() { return neurons.end(); }
	NeuronVect::const_iterator begin() const { return neurons.begin(); }
	NeuronVect::const_iterator end() const { return neurons.end(); }

	std::vector<double> GetValues() const;
	void LoadInputs(const std::vector<double>& inputs);
};


#endif