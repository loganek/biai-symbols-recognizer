#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <functional>

struct Connection
{
    double weight;
    double deltaWeight;

	Connection(double weight = 0.0, double deltaWeight = 0.0) : weight(weight), deltaWeight(deltaWeight) {}
};

class Neuron
{
private:
	double gradient;
	double output;
	unsigned index;
	std::vector<Connection> weights;

    std::function<double()> weightsInitializer;

	static double trainRate;
    static double momentum;
public:
	
    Neuron(unsigned outputCount, unsigned index);

	void SetOutput(double val) { output = val; }
    double GetOutput() const { return output; }
	
	double GetWeighted(int i) const { return output * weights[i].weight; }
	
	double GetGradient() const { return gradient; }
	void SetGradient(double value) { gradient = value; }

	double GetWeight(int index) const { return weights[index].weight; }

	unsigned GetIndex() const { return index; }
	
	void UpdateWeight(const Neuron& targetNeuron);
};

#endif